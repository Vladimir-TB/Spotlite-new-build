@echo off
rem Build SpotLite (Qt 5.15.2 MSVC)
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" || goto :error
set "PATH=C:\Qt\5.15.2-msvc2019\bin;%PATH%"
cd /d C:\Users\William\Desktop\spotlite-webengine
nmake || goto :error
echo NMake klaar.
goto :eof
:error
echo Fout tijdens build.
exit /b 1
