@echo off
rem Deploy SpotLite release met Qt 5.15.2 (incl. WebEngine)
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" || goto :error
set "PATH=C:\Qt\5.15.2-msvc2019\bin;%PATH%"
cd /d C:\Users\William\Desktop\spotlite-webengine
windeployqt --webengine release\SpotLite.exe || goto :error
echo Deploy klaar in release\.
goto :eof
:error
echo Fout tijdens deploy.
exit /b 1
