# 03. Знакомство с WinDbg

## Цель
- Краткое знакомство с возможностями WinDbg, включая сценарии
  - отладка своих приложений (с доступным исходным кодом)
  - отладка приложений, для которых не доступен исходный код (но есть доступ к отладочным символам) 

## Необходимые инструменты
- пакет Windows Debugging Tools
- Visual Studio 2017 с установленным набором поддержки C++

## WinDbg в пользовательском режиме

Выполните следующий tutorial [Getting Started with WinDbg (User-Mode)](https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/getting-started-with-windbg)

**_Обратите внимание_**, что во второй части (где компилируется ваша программа) вам потребуется не только скомпилировать программу, но и выставить правильные настройки для сборщика (это можно сделать в настройках проекта в разделе **Linker\\All options**), а именно:

|Настройка|Значение|
|-|-|
|**Set Checksum**|Yes (/RELEASE)|
|**Generate Debug Info**|Generate Debug Information optimized for sharing and publishing (/DEBUG:FULL)|