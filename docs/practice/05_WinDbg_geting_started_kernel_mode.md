# 05. Знакомство с WinDbg для режима ядра

## Цель
- Краткое знакомство с возможностями WinDbg в части отладки ядра Windows

## Необходимые инструменты
- виртуальная машина c Windows 2003
- пакет Windows Debugging Tools

## Подготовка

- Запустите виртуальную машину и залогиньтесь
- Откройте на редактирование **boot.ini** и добавьте в его конец строку

```
multi(0)disk(0)rdisk(0)partition(1)\WINDOWS="Windows Server 2003 (debug)" /noexecute=optout /fastdetect /debug /debugport=COM1 
```

- Запустите **WinDbg** настройте и запустите отладку режима ядра аналогично практикуму [Сборка и установка ядра WRK](01_WRK_build_and_install.md)

- Перезапустите виртуальную машину и при старте выберите только что добавленную конфигурацию
- Убедитесь, что WinDbg подключился к отладчику ядра

## WinDbg в режиме ядра

Выполните следующий tutorial [Getting Started with WinDbg (Kernel-Mode)](https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/getting-started-with-windbg--kernel-mode-)

**_Обратите внимание_**
- Местами у команд присутствуют паразитные символы "\\". Например, на шаге 4 вместо команды **".sympath srv\\*"** необходимо ввести **".sympath srv\*"**
- На шаге 22 вместо функции **CLASSPNP!ClassGlobalDispatch** (она отсутствует в Windows 2003) поставьте точку останова на функции **CLASSPNP!ClassDeviceControlDispatch**