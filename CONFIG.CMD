@echo off
:: SELECT START v0.1
:: Copyright (c) 2022 Retro Menu. All rights reserved.
:: Thanks ^& Credits to castellonmichael@gmail.com
::----------------------------------------------------------------------------------

color 1f
title CONFIG v0.1
REM mode con: cols=16 lines=25

::----------------------------------------------------------------------------------
:: Main Menu
::----------------------------------------------------------------------------------
:MainMenu
cls
echo.================
echo.      BOOT
echo.================
echo.
echo. [1] NORMAL
echo.
echo. [2] CLASSIC
echo.
echo. [X] EXIT
echo.================
choice /C:12X /N /M "Choice : "
if errorlevel 3 goto :EXIT
if errorlevel 2 goto :MENU
if errorlevel 1 goto :EXPLORER
::----------------------------------------------------------------------------------

:EXPLORER
cls
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon" /V Shell /t REG_SZ /d  "explorer.exe" /f
echo. [1] EXPLORER
pause
cls
echo.
choice /C:YN /N /M "Are you sure to reboot ? ['Y'es/'N'o] : "
if "%errorlevel%" equ "1" set "IsRebootSelected=Yes"
if errorlevel 2 goto :MainMenu
echo.
echo.----------------
echo.####Reboot######
echo.----------------
echo.
if "%IsRebootSelected%" equ "Yes" (shutdown -r -t 0)
goto :MainMenu
::----------------------------------------------------------------------------------

:MENU
cls
reg add "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon" /V Shell /t REG_SZ /d  "C:\MENU\MENU.exe" /f
echo. [2] MENU
pause
cls
echo.
choice /C:YN /N /M "Are you sure to reboot ? ['Y'es/'N'o] : "
if "%errorlevel%" equ "1" set "IsRebootSelected=Yes"
if errorlevel 2 goto :MainMenu
echo.
echo.----------------
echo.####Reboot######
echo.----------------
echo.
if "%IsRebootSelected%" equ "Yes" (shutdown -r -t 0)
goto :MainMenu
::----------------------------------------------------------------------------------

:EXIT
exit
::----------------------------------------------------------------------------------
