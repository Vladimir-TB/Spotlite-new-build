; Inno Setup script voor Spotlite 2.1.0 (Qt 5.15 WebEngine build)
; Auteur: spotnet team
; Help: spotnet.forum
; Met dank aan: Qt opensource

[Setup]
AppId={{B1E59C4F-2F82-4F1B-A5C3-6F8C5E2B210F}
AppName=Spotlite Release 2026
AppVersion=2.1.0
AppPublisher=spotnet team
AppPublisherURL=https://spotnet.forum
AppSupportURL=https://spotnet.forum
AppComments=Met dank aan Qt opensource
DefaultDirName={pf}\Spotlite
DefaultGroupName=Spotlite
OutputDir=dist\installer2
OutputBaseFilename=Spotlite-Setup-2.1.0-clean
LicenseFile=installer_terms.txt
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64
Compression=lzma
SolidCompression=yes
WizardStyle=modern
DisableDirPage=no
DisableProgramGroupPage=no
PrivilegesRequired=admin
UsePreviousAppDir=yes
SetupLogging=yes
DirExistsWarning=no
AppendDefaultDirName=yes
SetupIconFile=C:\Users\William\Desktop\spotlite-webengine\icon.ico

[Languages]
Name: "nl"; MessagesFile: "compiler:Languages\\Dutch.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
; Neem de opgeschoonde runtime uit dist\app mee (inclusief resources-map)
Source: "dist\\app\\*"; DestDir: "{app}"; Flags: recursesubdirs createallsubdirs ignoreversion

[Icons]
Name: "{group}\Spotlite"; Filename: "{app}\SpotLite.exe"
Name: "{commondesktop}\Spotlite"; Filename: "{app}\SpotLite.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\SpotLite.exe"; Description: "{cm:LaunchProgram,Spotlite}"; Flags: nowait postinstall skipifsilent
