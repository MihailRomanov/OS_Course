# 04. Низкоуровневые операции в Visual C/C++

Под низкоуровненвыми операцияими (в данной работе) мы будем понимать операции, которые невозможно выполнить стандартными средствами C/С++ и которые требуют обращения к уровню языка ассемблера и/или машинным инструкциям.

В Visual C/C++ есть 3 основных механизма реализации низкоуровневых операций для процессоров x86/x64:
- встроекнные в компилятор функции ([intrinsics](https://en.wikipedia.org/wiki/Intrinsic_function))
- встроенный ассемблер для архитектуры x86 (inline assembler)
- Microsoft Macro assembler (MASM)

Все эти способы описаны в статье [Compiler Intrinsics and Assembly Language](https://docs.microsoft.com/en-us/cpp/intrinsics/compiler-intrinsics-and-assembly-language)

Для знакомства со всеми тремя вариантами мы будем использовать инструкцию процессорв [CPUID](https://en.wikipedia.org/wiki/CPUID)


## Встроенный ассемблер

1. 
