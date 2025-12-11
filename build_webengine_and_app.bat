@echo off
setlocal
rem ============================================================
rem Qt 5.15.2 volledige build + WebEngine (MSVC x64)
rem Deze .bat bouwt Qt vanaf de bron, inclusief WebEngine, en installeert in een prefix.
rem Pas paden hieronder aan indien nodig.
rem Vereisten: MSVC Build Tools 2022, Python 2.7 (C:\Python27), Perl (C:\Strawberry\perl\bin)
rem ============================================================

rem Pad naar MSVC vcvars64.bat
set VCVARS="C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
rem Pad naar Python2 en Perl
set PY2=C:\Python27
set PERL=C:\Strawberry\perl\bin
rem Qt bronmap en install-prefix
set QT_SRC=C:\Users\William\Desktop\qt-everywhere-src-5.15.2
set QT_PREFIX=C:\Qt\5.15.2-msvc64

echo.
echo [1/4] Init MSVC omgeving...
call %VCVARS% || goto :error

echo.
echo [2/4] Configure Qt (incl. WebEngine)...
pushd "%QT_SRC%" || goto :error
set PATH=%PY2%;%PERL%;%PATH%
cd /d "%QT_SRC%\qtbase" || goto :error
call "%QT_SRC%\qtbase\configure.bat" -top-level -prefix "%QT_PREFIX%" ^
  -release -opensource -confirm-license ^
  -nomake tests -nomake examples ^
  -opengl desktop ^
  -webengine-proprietary-codecs || goto :error
cd /d "%QT_SRC%" || goto :error

echo.
echo [3/4] nmake (kan uren duren)...
nmake || goto :error

echo.
echo [4/4] nmake install...
nmake install || goto :error
popd

echo.
echo Klaar: Qt staat in %QT_PREFIX%
goto :eof

:error
echo.
echo FOUT opgetreden. Controleer de output hierboven.
exit /b 1
