<link rel="stylesheet" href="style.css">

<mark>&nbsp;LAB04&nbsp;</mark>

# Bitwise Operators

[**Back to TOC**](/contents.md)

## Jump to...

- [And](#and)
- [Or](#or)
- [Shifting](#shifting)

[comment]: <body>

### and

```
5 & 6 ::= 4

    5:  0 1 0 1
&   6:  0 1 1 0
    ----------
    4:  0 1 0 0
```

### or

```
5 | 6 ::= 7

    5:  0 1 0 1
&   6:  0 1 1 0
    ----------
    7:  0 1 1 1
```

### shifting

#### shift right

```
5 >> 2 ::= 1

    5:  0 1 0 1
>>  1
    ----------
    2:  0 0 1 0
>>  1
    ----------
    1:  0 0 0 1
```

#### shift left

```
5 << 2 ::= 20

    5:  0 0 0 0  0 1 0 1
<<  1
    --------------------
    10: 0 0 0 0  1 0 1 0
<<  1
    --------------------
    20: 0 0 0 1  0 1 0 0
```

[comment]: <Footer>

<br>

---
<table width="100%">
    <td>
    <div class="foot-previous">
        <a href="/src/LAB03.md"><b>&#x2190; LAB03</b><br>Switch..Case</a>
    </div>
    </td>
    <td>
    <div class="foot-next">
        <a href="/src/LAB05.md"><b>LAB05 &#x2192;</b><br>Array</a>
    </div>
    </td>
</table>