@echo off
rem ============================================================
rem Qt 5.15.2 MSVC64 omgeving klaarmaken voor builds
rem Gebruik:
rem   1) Open een normale cmd.exe / PowerShell.
rem   2) Run: qt-env-msvc2019.bat
rem Daarna kun je meteen qmake/nmake/windeployqt gebruiken.
rem ============================================================

rem Pad naar MSVC vcvars64.bat (Build Tools 2022)
set "VCVARS=C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"

rem Qt prefix
set "QT_PREFIX=C:\Qt\5.15.2-msvc2019"

if not exist "%VCVARS%" (
  echo Kan vcvars64.bat niet vinden op: %VCVARS%
  exit /b 1
)

if not exist "%QT_PREFIX%\bin\qmake.exe" (
  echo Qt niet gevonden op: %QT_PREFIX%
  exit /b 1
)

call "%VCVARS%" || exit /b 1
set "PATH=%QT_PREFIX%\bin;%PATH%"
set "QTDIR=%QT_PREFIX%"
set "QT_PLUGIN_PATH=%QT_PREFIX%\plugins"
set "QML2_IMPORT_PATH=%QT_PREFIX%\qml"

echo.
echo Qt-omgeving klaar. Controle: 
"%QT_PREFIX%\bin\qmake.exe" -v
