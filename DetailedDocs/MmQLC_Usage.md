# MmQLC Usage Guide

## Command Overview

To use the MmQLC compiler, enter the following command in your terminal or command prompt:

```cmd
mmqlc ~r PATH_TO_EXISTING_QUERY_FILE ~w PATH_TO_GENERATE_ANSWER_FILE
```

Explanation of the above command:

1. **mmqlc**  Compiler name in lowercase(**Recommended when using terminal or cmd**).
2. **~r** the handle used to load query file.[file of **mmql** extension type].
3. **PATH_TO_EXISTING_QUERY_FILE** for example **E:\\\\file.mmql**.
4. **~w** the handle used to write answers to answer file.[files of **ans** extension. type]
5. **PATH_TO_GENERATE_ANSWER_FILE** for example **E:\\\\file.ans**.

> [!WARNING]
> In **PATH_TO_EXISTING_QUERY_FILE** and **PATH_TO_GENERATE_ANSWER_FILE**, any kind of
> spaces are not allowed . Since MmQLC works on command line arguments and single space can increase the argument count which can throw exception. For example.
> ```cmd
>   mmqlc ~r E:\\tests\\My Queries.mmql ~w E:\\tests\\Test Results\\MyAns.ans
> ```

> [!TIP]
> - Enclosing **PATH_TO_EXISTING_QUERY_FILE** and **PATH_TO_GENERATE_ANSWER_FILE** in quotation marks can save you from exceptions thrown by compiler. For Example
> ```cmd
> mmqlc ~r "E:\\tests\\My Queries.mmql" ~w "E:\\tests\\Test Results\\MyAns.ans"
> ```
> - If folders are missing in **PATH_TO_GENERATE_ANSWER_FILE** , it will be created 
>  automatically by the compiler.
