@echo off

::----------------------------------------------------------------------------------
:: MENU v0.1
:: Copyright (c) 2022 Retro Menu. All rights reserved.
:: Thanks ^& Credits to castellonmichael@gmail.com
::----------------------------------------------------------------------------------

color 1f
title MENU v0.1
REM mode con: cols=16 lines=25

::----------------------------------------------------------------------------------
:: Main Menu
::----------------------------------------------------------------------------------
:MainMenu
cls
echo.================
echo.      MENU
echo.================
echo.
echo. [1] HOME
echo.
echo. [2] PROGRAMS
echo.
echo. [3] PANEL
echo.
echo. [4] CMD
echo.
echo. [X] SHUTDOWN
echo.
echo.================
choice /C:12345X /N /M "Choice : "
if errorlevel 5 goto :SHUTDOWN
if errorlevel 4 goto :CMD
if errorlevel 3 goto :PANEL
if errorlevel 2 goto :PROGRAMS
if errorlevel 1 goto :HOME
::----------------------------------------------------------------------------------

:HOME
cls
explorer %homepath%
goto :MainMenu
::----------------------------------------------------------------------------------

:PROGRAMS
cls
explorer "%programdata%\Microsoft\Windows\Start Menu\Programs\"
goto :MainMenu
::----------------------------------------------------------------------------------

:PANEL
cls
control
goto :MainMenu
::----------------------------------------------------------------------------------

:CMD
cls
start cmd
goto :MainMenu
::----------------------------------------------------------------------------------

:SHUTDOWN
cls
echo.================
echo.    SHUTDOWN
echo.================
echo.
echo. [1] POWEROFF
echo.
echo. [2] REBOOT
echo.
echo. [X] BACK
echo.
echo.================
echo.
choice /C:12X /N /M "Choice : "
if errorlevel 3 goto :MainMenu
if errorlevel 2 goto :Reboot
if errorlevel 1 goto :Poweroff
::----------------------------------------------------------------------------------

:Poweroff
cls
echo.
choice /C:YN /N /M "Are you sure to turn off ? ['Y'es/'N'o] : "
if "%errorlevel%" equ "1" set "IsPoweroffSelected=Yes"
echo.
echo.----------------
echo.####Poweroff####
echo.----------------
echo.
if errorlevel 2 goto :SHUTDOWN
if "%IsPoweroffSelected%" equ "Yes" (shutdown -s -t 0)
::----------------------------------------------------------------------------------

:Reboot
cls
echo.
choice /C:YN /N /M "Are you sure to reboot ? ['Y'es/'N'o] : "
if "%errorlevel%" equ "1" set "IsRebootSelected=Yes"
if errorlevel 2 goto :SHUTDOWN
echo.
echo.----------------
echo.####Reboot######
echo.----------------
echo.
if "%IsRebootSelected%" equ "Yes" (shutdown -r -t 0)
::----------------------------------------------------------------------------------