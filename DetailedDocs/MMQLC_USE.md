# MmQLC Usage Guide

## REPL Mode(MmQLC v2.2+)
To use the MmQLC interpreter for one on one query interpretation, enter the following command in your terminal:

```bash
mmqlc --live
```
Explanation of the above command:

1. **mmqlc:**  interpreter name in lowercase(**Recommended when using terminal or cmd**).
2. **--live:** command line option for invoking **REPL** mode.

---

## Batch Mode

To use the MmQLC interpreter for batch query interpretation, enter the following command in your terminal:

```bash
mmqlc -r PATH_TO_EXISTING_QUERY_FILE -w PATH_TO_GENERATE_ANSWER_FILE
```

Explanation of the above command:

1. **mmqlc:**  interpreter name in lowercase(**Recommended when using terminal or cmd**).
2. **-r:** the handle used to load query file.
3. **PATH_TO_EXISTING_QUERY_FILE:** for example **E:\\\\file.mmql**.
4. **-w:** the handle used to write answers to answer file.
5. **PATH_TO_GENERATE_ANSWER_FILE:** for example **E:\\\\file.ans**.

> [!WARNING]
> In **PATH_TO_EXISTING_QUERY_FILE** and **PATH_TO_GENERATE_ANSWER_FILE**, any kind of
> spaces are not allowed . Since MmQLC works on command line arguments and single space can increase the argument count which can throw exception. For example.
> ```bash
>   mmqlc -r E:\\tests\\My Queries.mmql -w E:\\tests\\Test Results\\MyAns.ans
> ```

> [!TIP]
> - Enclosing **PATH_TO_EXISTING_QUERY_FILE** and **PATH_TO_GENERATE_ANSWER_FILE** in quotation marks can save you from exceptions thrown by interpreter. For Example
> ```bash
> mmqlc -r "E:\\tests\\My Queries.mmql" -w "E:\\tests\\Test Results\\MyAns.ans"
> ```
> - If folders are missing in **PATH_TO_GENERATE_ANSWER_FILE** , it will be created 
>  automatically by the interpreter.

---

## Miscellaneous Command Line Options
Following are some of the command line options that you might need(I think so...)
- Displaying the command for **batch** mode:
```bash
mmqlc --htu
```
- Displaying current release version:
```bash
mmqlc --version
```
- Displays all the available command line options:
```bash
mmqlc --help
```

