# MmQL - The Mathematical Query Language  

**MmQL** is a lightweight, *cross-platform* query language tailored for mathematical computations. Designed for speed and simplicity, **MmQL** allows users to write precise mathematical queries, offering an efficient alternative to tools like **MAPLE**, **Wolfram Mathematica**, or **MATLAB**.  

---

## What is MmQL?  

**MmQL** stands for **M**athe**m**atical **Q**uery **L**anguage. It is a **case-sensitive** interpreted query language with a minimalistic syntax, focused on mathematical operations.  

### Key Features:  
- **Portable and Cross-Platform:** The language can run on various platforms by compiling its interpreter for your operating system.  
- **Lightweight and Efficient:** Perfect for quick and resource-friendly computations.  
- **Case-Sensitive Syntax:** Commands are interpreted based on their casing.  
- Specializes in:  
  - **Real Numbers**  
  - **Complex Numbers**  

**MmQL** is particularly suited for users who need fast, precise calculations without the overhead of complex mathematical software.

---

## What is MmQLC?  

**MmQLC** is the **interpreter** used to execute **MmQL** queries. While **MmQL** itself is platform-independent, **MmQLC** must be **compiled for your specific operating system** to ensure compatibility. Once compiled, it enables users to process and run **MmQL** queries efficiently.  

### Features of MmQLC:  
- **Cross-Platform Compatibility:** Can be compiled for any major operating system, including Windows, Linux, and macOS.  
- **Query Parsing and Execution:** Interprets mathematical commands using tokenization and parsing.  
- **Answer Generation:** Produces outputs or result files based on queries.  
- **Optimized for Speed:** Runs computations quickly and effectively.  

---

## Why Choose MmQL?  

**MmQL** provides a lightweight and flexible environment for mathematical queries, perfect for students and professionals looking for:  
- A **simple and efficient query language** for real and complex number calculations.  
- A **cross-platform tool**, customizable for your operating system via compilation.  
- An **unbloated alternative** to large-scale computational platforms.  

With its clean syntax and custom interpreter, **MmQL** delivers a tailored solution for performing mathematical computations. Compile **MmQLC** on your preferred OS, and you're ready to handle your queries with speed and precision!

---

## Dependencies
This project depends upon the following libraries
They are as follows:
- [ ]  Boost C++ Library v 1.86.0
- [X] GNU GMP Library **(mingw64)**
- [X] MPFR Library **(mingw64)**
- [X] FMT Library **(mingw64)**

If you want to build from source, then the you should download the libraries described above. Following are the **links** to each of those unchecked libraries.

[**Boost C++ Library - Pre-Built Windows Binaries v 1.86.0**](https://sourceforge.net/projects/boost/files/boost-binaries/1.86.0/boost_1_86_0-msvc-14.1-64.exe/download)

<!--[**Eigen Linear Algebra Library v 3.4.0**](https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip)-->

 The checked libraries **(built by MSYS2)** will be provided in the release section of the repository.


## Building From Source
> [!IMPORTANT]
> - [X] **Install MinGW. Watch this [video](https://youtu.be/oC69vlWofJQ) for detailed installation guide by `Microsoft` via `MSYS2`**
> - [X] **Extract the library archive into your `MinGW` base directory**
> - [X] Install `scoop`:
```cmd
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression
```
> - [X] Install `cmake` via `scoop`:
```cmd
scoop install main/cmake
```
> - [X] Install `make` via `scoop`:
```cmd
scoop install main/make
```

🎉 Congratulations ! 🎉
You have set up the environment for building **MmQLC** for your OS.
---


### Step By Step Easy Building Procedure:
- Open up the `cmake-gui` and choose the base directory of the `repo`
- Now, select the build directory of your choice.
- Click `Generate` ! and wait a bit.
- After generation of `Makefile` is complete, start `cmd` in the build directory.
- Paste this into cmd.
```cmd
make
```
- Wait for the compilation to complete and... `MmQLC` is ready to use !
---
## Using the MmQL Language For Calculations

**MmQL**  is pretty simple to use , just download either the installer from **Release** section or the source code **(If you want to build it for yourself.)** 

- First of all write queries by using  text editor.
- Now for generation of answer file then you should run **MmQLC.exe** with special command line **arguments** defined for **MmQLC** The method for generating answer file from a query file is explained [**Here.**](DetailedDocs/MmQLC_Usage.md).
- To view or see the answers, open the **.ans** in any text editor.

> [!TIP]
> For Syntax Highlighting; Use **Sublime Text, if you can afford it**.

 > [!NOTE]
 > - Consider adding **MmQLC.exe** to your environment variables for running it from the shell directly. Click  [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.
 > -  In  the case if you prefer the installer over manual build process then the installer wizard will take care of the above step.

## Supported Queries
Following types of queries are supported by **MmQL**.
- ### Queries For Calculations Involving Real Numbers. Click [**Here**](DetailedDocs/realNumbers.md) to see.
- ### Queries For Calculations Involving Complex Numbers. Click [**Here**](DetailedDocs/complexNumbers.md) to see.

##  Getting the perfect output
To always achieve the perfect output, arrange the queries in the following order:
- Queries Involving Real Numbers.
- Queries Involving Complex Numbers.
## FAQs - Frequently Asked Questions
**FAQ #1 : Why The Queries Needs To Be Ordered Like This ?**</br>
**Answer**: Because **MmQLC** tends to interpret the easier queries first and the harder queries second. Thus, by arranging queries in the specified order , you'll always get the perfect output.</br>
**FAQ #2: What If The Queries Are Not Arranged In The Specified Order ? Will MmQLC Throw An Error ?**</br>
**Answer**: If the queries are not arranged in the above specified order then it is more like to get an unexpected output rather than a interpretation error.

## Comments in MmQL
The MmQL language only support single-line comments.

**Comment Declaration**: 
Comments looks like this
- `%% Comment`
## Possible Errors
> [!CAUTION]
Compound queries or stacking multiple queries on a single line may cause errors.
Nesting two or more queries or using inline comments will also throw errors.
### Examples of errors:
- Compound Queries: `ADD 3,4 FACTORIAL 43`
- Nested Queries: `FACTORIAL ADD 3,4` , `INVERSE_SINE SINE 45`
- Inline Comments: `ADD 4,5 %% add two numbers`
## 🎈🎉 MmQLC v2.3 Has Been Released ! 🎉🎈 
Click To Read [**ChangeLog v2.3**](DetailedDocs/Change_Log.md).
## Too Many Commits! 😁
- **Most commits are for fixing markdown files.**
- **As a solo developer, it's a challenge to manage both markdown and source code! 😢**
## License
This Project is licensed under the CC0-1.0 License - See The LICENSE file for more details.
