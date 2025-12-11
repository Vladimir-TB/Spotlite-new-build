SpotLite - Qt 5.15.2 WebEngine Edition
======================================

Overview
--------
SpotLite is refreshed to Qt 5.15.2 with Qt WebEngine. You get a modern rendering stack, light/dark UI, improved encoding (UTF-8 with cp1252 fallback), and a GUI-linked Windows build without a console window. Skins still work; the default skin is `standaard` with the light theme. WebEngine resources and the MSVC runtime should live next to the executable.

Highlights
- QtWebEngine instead of Qt4/WebKit (better security and compatibility).
- Light and dark themes; menu bar adjusted for dark UI.
- About text: "Door spotnet team 2026, voor hulp en vragen zie spotnet.forum".
- Encoding fixes: UTF-8 rendering with cp1252/Latin1 fallback for subjects and XML headers; comments/body decoded the same way.
- Logging filtered, linked as Windows GUI (no console window).
- Bundling: WebEngine pak/icu files plus the MSVC 2022 runtime next to the exe.

Build (Qt 5.15.2 MSVC x64)
Requirements:
- Visual Studio 2022 Build Tools (x64) — run `vcvars64.bat`.
- Qt 5.15.2 MSVC 2019 x64 (adjust the path).
- Optional: vcpkg libraries (adjust paths).

Steps:
```cmd
"<VSBuildTools>\VC\Auxiliary\Build\vcvars64.bat"
set PATH=<Qt5.15.2-msvc2019>\bin;%PATH%
cd <project-path>
del /q Makefile* .qmake.stash 2>nul
qmake SpotLite.pro
nmake -f Makefile.Release
```

Package/runtime layout:
- Copy `release\SpotLite.exe` to your dist folder (for example `dist\app\SpotLite.exe`).
- Place WebEngine data in `dist\app\resources`: `qtwebengine_resources.pak`, `qtwebengine_resources_100p.pak`, `qtwebengine_resources_200p.pak`, `qtwebengine_devtools_resources.pak`, `icudtl.dat`.
- Put the MSVC runtime beside the exe: `vcruntime140*.dll`, `msvcp140*.dll`, `concrt140.dll`, `vccorlib140.dll`.
- Deploy Qt DLLs/plugins via `windeployqt --release --webengine dist\app\SpotLite.exe` or copy from your Qt install.

Notes
- For correct accents/UTF-8, re-fetch headers; existing `spots.db` keeps old encoding errors.
- The `release/` folder with binaries is ignored in Git. If you need to track built artifacts, remove it from `.gitignore` and use Git LFS for large files.
