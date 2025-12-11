@echo off
rem Build SpotLite Release (Qt 5.15.2 MSVC)
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" || goto :error
set "PATH=C:\Qt\5.15.2-msvc2019\bin;%PATH%"
cd /d C:\Users\William\Desktop\spotlite-webengine
nmake -f Makefile.Release || goto :error
echo Release build klaar.
goto :eof
:error
echo Fout tijdens release-build.
exit /b 1
