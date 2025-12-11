SpotLite – Qt 5.15.2 WebEngine Edition
======================================

🇳🇱 Overzicht
-------------
SpotLite is opgefrist naar Qt 5.15.2 met Qt WebEngine. Je krijgt een modernere rendering stack, licht/donker UI, betere encoding (UTF-8 met cp1252 fallback) en een GUI-build zonder consolevenster. Skins blijven werken; standaard staat de `standaard` skin en licht thema aan. WebEngine resources en MSVC-runtime horen naast de exe.

🌟 Hoogtepunten
- QtWebEngine i.p.v. Qt4/WebKit (veiligheid, compatibiliteit, moderne browserstack).
- Licht én donker thema; menubalk aangepast voor dark UI.
- About/Help: “Door spotnet team 2026, voor hulp en vragen zie spotnet.forum”.
- Encoding fixes: UTF-8 rendering, subject fallback cp1252/Latin1, XML charset uit headers, comments/body idem.
- Logging gefilterd, gelinkt als Windows GUI (geen zwart consolevenster).
- Bundling: WebEngine pak/icu-bestanden + MSVC 2022 runtime naast de exe.

🔧 Bouwen (Qt 5.15.2 MSVC64)
Vereisten:
- Visual Studio 2022 Build Tools (x64) – `vcvars64.bat`.
- Qt 5.15.2 MSVC 2019 x64 (pas pad aan).
- (Optioneel) vcpkg libs (pas paden aan).

Stappen:
```cmd
"<VSBuildTools>\VC\Auxiliary\Build\vcvars64.bat"
set PATH=<Qt5.15.2-msvc2019>\bin;%PATH%
cd <project-path>
del /q Makefile* .qmake.stash 2>nul
qmake SpotLite.pro
nmake -f Makefile.Release
```

Runtime samenstellen:
- Kopieer `release\SpotLite.exe` naar je distributiemap (bijv. `dist\app\SpotLite.exe`).
- `dist\app\resources`: `qtwebengine_resources.pak`, `qtwebengine_resources_100p.pak`, `qtwebengine_resources_200p.pak`, `qtwebengine_devtools_resources.pak`, `icudtl.dat`.
- MSVC runtime naast de exe: `vcruntime140*.dll`, `msvcp140*.dll`, `concrt140.dll`, `vccorlib140.dll`.
- Qt DLL’s/plugins: via `windeployqt --release --webengine dist\app\SpotLite.exe` of handmatig uit je Qt-installatie.

Opmerking: Voor correcte accenten/UTF-8 moeten headers opnieuw worden binnengehaald; oude `spots.db` blijft zoals hij is.

🇬🇧 Overview
------------
SpotLite has been refreshed to Qt 5.15.2 with Qt WebEngine. You get a modern rendering stack, light/dark UI, better encoding (UTF-8 with cp1252 fallback), and a GUI-linked build without a console window. Skins still work; default skin is `standaard` and theme is light. WebEngine resources and MSVC runtime sit next to the exe.

🌟 Highlights
- QtWebEngine instead of Qt4/WebKit (security, compatibility, modern browser stack).
- Light and dark themes; menu bar fixed for dark UI.
- About text: “Door spotnet team 2026, voor hulp en vragen zie spotnet.forum”.
- Encoding: UTF-8 rendering; subject fallback cp1252/Latin1; XML charset from headers; comments/body decoded likewise.
- Logging filtered, linked as Windows GUI (no black console window).
- Bundling: WebEngine pak/icu files + MSVC 2022 runtime next to the exe.

🔧 Build (Qt 5.15.2 MSVC64)
Requirements:
- Visual Studio 2022 Build Tools (x64) – `vcvars64.bat`.
- Qt 5.15.2 MSVC 2019 x64 (adjust path).
- (Optional) vcpkg libs (adjust paths).

Steps:
```cmd
"<VSBuildTools>\VC\Auxiliary\Build\vcvars64.bat"
set PATH=<Qt5.15.2-msvc2019>\bin;%PATH%
cd <project-path>
del /q Makefile* .qmake.stash 2>nul
qmake SpotLite.pro
nmake -f Makefile.Release
```

Assemble runtime:
- Copy `release\SpotLite.exe` to your dist folder (e.g. `dist\app\SpotLite.exe`).
- `dist\app\resources`: `qtwebengine_resources.pak`, `qtwebengine_resources_100p.pak`, `qtwebengine_resources_200p.pak`, `qtwebengine_devtools_resources.pak`, `icudtl.dat`.
- MSVC runtime beside the exe: `vcruntime140*.dll`, `msvcp140*.dll`, `concrt140.dll`, `vccorlib140.dll`.
- Qt DLLs/plugins via `windeployqt --release --webengine dist\app\SpotLite.exe` or manual copy from your Qt install.

Note: For correct accents/UTF-8, re-fetch headers; existing `spots.db` keeps old encoding errors.
