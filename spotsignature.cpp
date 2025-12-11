#include "spotsignature.h"
#include <openssl/rsa.h>
#include <openssl/engine.h>
#include <openssl/bn.h>
#include <openssl/sha.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/rand.h>

#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <openssl/ssl.h>
#include <openssl/opensslv.h>

#if OPENSSL_VERSION_NUMBER < 0x10100000L
// OpenSSL 1.0.x compatibility shims: RSA accessors were added in 1.1+.
inline const BIGNUM *RSA_get0_n(const RSA *r) { return r->n; }
inline const BIGNUM *RSA_get0_e(const RSA *r) { return r->e; }
inline int RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d) {
    if (n) { r->n = n; }
    if (e) { r->e = e; }
    if (d) { r->d = d; }
    return 1;
}
#endif

#include <stdexcept>

// Socket fout: ( QAbstractSocket::UnknownSocketError )  "Fout bij het lezen: error:04077068:rsa routines:RSA_verify:bad signature"

#include <openssl/x509_vfy.h>
#include "crc.h"

bool SpotSignature::_initialized = false;


SpotSignature::SpotSignature(int numbits)
{
//    _init();
    _rsa = RSA_generate_key(numbits, RSA_F4, NULL, NULL);
    if (!_rsa)
        throw std::runtime_error("Fout bij aanmaken private key");
}

SpotSignature::SpotSignature(const QByteArray &key)
{
//    _init();
    BIO *mem = BIO_new(BIO_s_mem());;
    BIO_write(mem, key.constData(), key.length() );
    _rsa = PEM_read_bio_RSAPrivateKey(mem, NULL, NULL, NULL);
    BIO_free(mem);
}

SpotSignature::~SpotSignature()
{
    if (_rsa)
        RSA_free(_rsa);
}

QByteArray SpotSignature::publicKey()
{
    const BIGNUM *n = RSA_get0_n(_rsa);
    const BIGNUM *e = RSA_get0_e(_rsa);

    if (!n || !e)
        return "";

    const int modlen = BN_num_bytes(n);
    const int explen = BN_num_bytes(e);
    QByteArray mod(modlen, Qt::Uninitialized);
    QByteArray exp(explen, Qt::Uninitialized);
    BN_bn2bin(n, reinterpret_cast<unsigned char*>(mod.data()));
    BN_bn2bin(e, reinterpret_cast<unsigned char*>(exp.data()));

    return "<RSAKeyValue><Modulus>"+mod.toBase64()+"</Modulus><Exponent>"+exp.toBase64()+"</Exponent></RSAKeyValue>";
}

QByteArray SpotSignature::privateKey()
{
    BIO *mem = BIO_new(BIO_s_mem());;
    PEM_write_bio_RSAPrivateKey(mem, _rsa, NULL, NULL, 0, NULL, NULL);
    const int datalen = BIO_ctrl_pending(mem);
    QByteArray data(datalen, Qt::Uninitialized);
    BIO_read(mem, data.data(), datalen);
    BIO_free(mem);

    return data;
}

QByteArray SpotSignature::sign(const QByteArray &data)
{
   // qDebug() << data.length() << "RSA sign:\n" << data;
    unsigned char digest[SHA_DIGEST_LENGTH];
    unsigned int siglen = RSA_size(_rsa);
    QByteArray sig(siglen, Qt::Uninitialized);

    SHA1( (const unsigned char *) data.constData(), data.length(), digest);
    RSA_sign(NID_sha1, digest, sizeof(digest), reinterpret_cast<unsigned char*>(sig.data()), &siglen, _rsa);

    sig.resize(siglen);
    return sig;
}

bool SpotSignature::verify(const QByteArray &modulus, const QByteArray &exponent, const QByteArray &data, QByteArray &signature)
{
 //   qDebug() << data.length() << "RSA verify:\n" << data;
    unsigned char digest[SHA_DIGEST_LENGTH];
    bool ok = false;


    SHA1( (const unsigned char *) data.constData(), data.length(), digest);

    RSA *r = RSA_new();
    BIGNUM *n = BN_bin2bn( (const unsigned char *) modulus.constData(), modulus.length(), NULL);
    BIGNUM *e = BN_bin2bn( (const unsigned char *) exponent.constData(), exponent.length(), NULL);

    if (!n || !e || BN_num_bits(n) < 384)
        return false;

    RSA_set0_key(r, n, e, NULL);
    ok = RSA_verify(NID_sha1, digest, sizeof(digest), (unsigned char *) signature.data(), signature.length(), r);
    if (!ok)
        ERR_clear_error();
    RSA_free(r);

    return ok;
}

bool SpotSignature::verifyHeaderHashCash(const QByteArray &str)
{
    unsigned char digest[SHA_DIGEST_LENGTH];
    SHA1( (const unsigned char *) str.constData(), str.length(), digest);

    return (digest[0] == 0 && digest[1] == 0);
}

QByteArray SpotSignature::randomBytes(int num)
{
    QByteArray buf;
    buf.resize(num);
    RAND_pseudo_bytes( (unsigned char *) buf.data(), num);

    return buf;
}

QByteArray SpotSignature::crc32base64(const QByteArray &inbase64)
{
    QByteArray input = QByteArray::fromBase64(inbase64);
    uint32_t crc = crc32_begin();
    crc = crc32_data(crc, input.constData(), input.length() );
    crc = crc32_end(crc);
    QByteArray result( (char *) &crc, sizeof(crc) );

    return result.toBase64().replace("=", "").replace("+", "").replace("/", "");
}

/*
void SpotSignature::_init()
{
    if (!_initialized)
    {
        if ( QFile::exists("/dev/random") )
        {
            RAND_load_file("/dev/random", 16);
        }
        else
        {
            for (int i=0; i<10; i++)
            {
                qint64 ms = QDateTime::currentMSecsSinceEpoch();
                RAND_seed(&ms, sizeof(ms));
            }
        }

        _initialized = true;
    }
}
*/
