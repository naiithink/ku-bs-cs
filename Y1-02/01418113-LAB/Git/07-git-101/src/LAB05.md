<link rel="stylesheet" href="style.css">

<mark>&nbsp;LAB05&nbsp;</mark>

# Arrays and Pointers

[**Back to TOC**](/contents.md)

## Jump to...

- [Arrays](#arrays)
- [Pointers](#pointers)
- [`scanf`](#scanf)

[comment]: <body>

## Arrays

```
[0] [1] [2] [3] [4] [5] [6] [7] [8]
```

### Declaration

```
<type> <var_name>`[`<total_indices>`]` [= `{` <value>[, <value>[, ...]] `}`];
```

### Assignment and Access

```
... <var_name>`[`<index>`]` ...
```

## Pointers

Memory address

### Operators

`*`&nbsp;&nbsp;&nbsp;&nbsp;Dereferencing<br>
`&`&nbsp;&nbsp;&nbsp;&nbsp;Referencing

### Declaration

```
<type> *<var_name> [= <&<some_var>>];
```

### Dereferencing

ค่าที่ตัวแปรเก็บ

```
... *<pointer_var> ...
```

### Referencing

ที่อยู่ของตัวแปร

```
... &<pointer_var> ...
```

### `scanf`

รับ input ที่อยู่ในรูป formatted string

```
scanf(const char *restrict format, ...);
```

[comment]: <footer>

<br>

---
<table width="100%">
    <td>
    <div class="foot-previous">
        <a href="/src/LAB04.md"><b>&#x2190; LAB04</b><br>Bitwise Operators</a>
    </div>
    </td>
</table>