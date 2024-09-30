# MmQLC  Usage Guide

## MmQLC  works with following cmd command:

```cmd
MmQLC ~r PATH_TO_EXISTING_QUERY_FILE ~w PATH_TO_GENERATE_ANSWER_FILE
```

Explaination of the above command:

1. **MmQLC**  Compiler name
2. **~r** the handle used to load query file.[file of **mmql** extenstion type]
3. **PATH_TO_EXISTING_QUERY_FILE** for example **E:\\\\file.mmql**
4. **~r** the handle used to write answers to answer file.[files of **ans** extenstion type]
5. **PATH_TO_GENERATE_ANSWER_FILE** for example **E:\\\\file.ans**

### Plus Point ⭐⭐
  If folders are missing in **PATH_TO_GENERATE_ANSWER_FILE** , it will be created automatically by the compiler.
### Note:
   In **PATH_TO_EXISTING_QUERY_FILE**, the name of .mmql files must not contain spaces because it will be not compiled
	</br> because the compiler will get confused and throw an error.