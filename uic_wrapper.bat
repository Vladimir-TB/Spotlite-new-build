@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\Qt\5.15.2-msvc2019\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\Qt\5.15.2-msvc2019\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\Qt\5.15.2-msvc2019\plugins
)
C:\Users\William\Desktop\qt-everywhere-src-5.15.2\qtbase\bin\uic.exe %*
EndLocal
