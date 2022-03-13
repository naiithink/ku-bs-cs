<link rel="stylesheet" href="style.css">

<mark>&nbsp;LAB01&nbsp;</mark>

# Introduction to C Programming

[**Back to TOC**](/contents.md)

## Jump to...

- [Command Line Interface](#command-line-interface)
- [GNU Compiler Collection](#gnu-compiler-collection)
- [Visual Studio Code](#visual-studio-code)
- [The C Programming Language](#the-c-programming-language)
- [Variable Declaration](#variable-declaration)
- [Operators in C](#operators-in-c)

[comment]: <body>

## Command Line Interface

**Command Line** คือ สิ่งที่ไว้ใช้สั่งงานคอมพิวเตอร์ผ่านทางการสั่งคำสั่ง ทีละบรรทัด

## GNU Compiler Collection

**GCC** คือ สิ่งที่ใช้สร้างไฟล์ binary หรือ machine code จาก source code และ library ต่าง ๆ – compilation

## Visual Studio Code

**Visual Studio Code** หรือ **vscode** คือ text editor ที่แนะนำเพื่อใช้ในการเรียนวิชานี้

## The C Programming Language

### Program Structure

```c
#include <stdio.h>          // Header file ที่ใช้ในโปรแกรมนี้

int main()                  // ประกาศฟังก์ชัน `main' ที่มี return type เป็น `integer`
{
    /* Instructions */      // Instruction สำหรับฟังก์ชัน `main'

    return 0;               // `return' ค่าของฟังก์ชัน `main'
}
```

### Synopsis

**Include Header File(s)**

```
#include <header_file>
```

**Declaration of `main`**

```
<return_type> main
```

return type ของ `main` ควรจะเป็น `int`<br>
หาก return `0` หมายถึง โปรแกรมทำงานเสร็จสมบูรณ์<br>
หากเป็นค่าอื่น หมายถึงเกิดปัญหาในการทำงาน

**Instructions of `main`**

```
{
    [instructions]

    return [value];
}
```

## Variable Declaration

```
<datatype> <var_name> [= <value>];
```

> หากเรา declare ตัวแปรภายใน `main` โดยที่ไม่ได้ assign ค่าใด ๆ ให้ ค่าของตัวแปรจะเป็น garbage value

## Operators in C

### Unary Operator

`!` not

### Binary Operator

| Operator | Description |
| :------: | :---------- |
| `+`      | addition    |
| `-`      | subtraction |
| `*`      | multiplication |
| `/`      | division    |
| `=`      | assignment  |
| `&`      | bitwise and |
| `\|`     | bitwise or  |
| `>>, <<` | bit shifting |

[comment]: <footer>

<br>

---

<table width="100%">
    <td><div class="foot-previous">
        <a href="/contents.md"><b>&#x2190; Contents</b><br>Table of Contents</a>
    </div></td>
    <td><div class="foot-next">
        <a href="/src/LAB02.md"><b>LAB02 &#x2192;</b><br>Input, Output, and Control Flow</a>
    </div></td>
</table>