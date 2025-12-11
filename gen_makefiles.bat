@echo off
rem Qt 5.15.2 MSVC64: Makefiles genereren
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" || goto :error
set "PATH=C:\Qt\5.15.2-msvc2019\bin;%PATH%"
set "QMAKESPEC=win32-msvc"
cd /d C:\Users\William\Desktop\spotlite-webengine
qmake SpotLite.pro || goto :error
echo Klaar.
goto :eof
:error
echo Fout bij qmake.
exit /b 1
