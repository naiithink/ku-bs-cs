<link rel="stylesheet" href="style.css">

<mark>&nbsp;LAB02&nbsp;</mark>

# Input, Output, and Control Flow

[**Back to TOC**](/contents.md)

## Jump to...

- [The Array of Character](#the-array-of-character)
- [Conditional Statement](#conditional-statement)
- [Functions](#getting-input)

[comment]: <body>

## The Array of Character

```
char <var_name>`[`<total_indices>`]` [= `"`<chars>`"`];
```

## Conditional Statement

- `if`
    ```
    if (<test_expression>)
    {
        [instructions]
    }
    else if (test_expression)
    {
        [instructions]
    }
    else
    {
        [instructions]
    }
    ```
- `for`
    ```
    for (<declare_var>; <checking_expression>; <update_expression>)
    {
        [instructions]
    }
    ```
- `while`
    ```
    while (<test_expression>)
    {
        [instructions]
    }
    ```
- `do..while`
    ```
    do
    {
        [instructions]
    }
    while (<test_expression>);
    ```

## Functions

### `stdio.h`

- `printf`<br>
    ```
    printf("<string[spacifier]>"[, <var>[, <var>[, ...]]]);
    ```
    **Format Specifiers**
    | Specifier    | Description     |
    | :----------- | :-------------- |
    | `%d`         | Decimal (`int`) |
    | `%f`         | Float (`float`) |
    | `%c`         | Single Character (`char`) |
    | `%s`         | Array of Character / String (`char *`) |

### `stdlib.h`

- `fgetc` – file get char<br>
    ```
    fgetc(FILE *stream);
    ```
- `fgets` – file get string<br>
    ```
    fgets(char *var, size_t buffer, FILE *steam);
    ```
- `getc` – get char<br>
    ```
    getc(FILE *stream);
    ```
- `gets` – get string<br>
    ```
    gets(char *var);
    ```
- `atoi`<br>
    ```
    atoi(const char *str);
    ```

[comment]: <footer>

<br>

---

<table width="100%">
    <td><div class="foot-previous">
        <a href="/src/LAB01.md"><b>&#x2190; LAB01</b><br>Input, Output, and Control Flow</a>
    </div></td>
    <td><div class="foot-next">
        <a href="/src/LAB03.md"><b>LAB03 &#x2192;</b><br>Switch..Case</a>
    </div></td>
</table>