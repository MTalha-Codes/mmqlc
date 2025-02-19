<p align="center" width="100%">
    <img height="100" src="https://github.com/said7388/developer-portfolio/assets/77630868/c0064908-cd5f-4751-a77c-eba90a62b55c">
</p>


# MmQL - The Mathematical Query Language 
**MmQL** is a very lightweight computational query language used to compute operations involving real and complex numbers (the queries are interpreted by **MmQLC**) developed purely in **C++23**.

---

## What is MmQL ?
**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is an interpreted language as well as a case-sensitive **where uppercase and  lowercase matters**. The interpreter (**MmQLC**) is a custom and and yet a very simple interpreter. Techniques like Tokenization and Parsing are used by **MmQLC**.

**MmQL** is a lightweight, *cross-platform* query language tailored for mathematical computations. Designed for speed and simplicity, **MmQL** allows users to write precise mathematical queries.
> [!NOTE]
> - Please note that **MmQL** is not a symbolic language and it does not uses CAS (Computer Algebra Systems)
> - **MmQL** is a unique because it does not uses an **Abstract Syntax Tree**.

---

# What is MmQLC ?  

**MmQLC** stands for **M**athe**m**atical **Q**uery **L**anguage **C**ompiler (although this is an interpreter 😁). It is a **case-sensitive** interpreted query language with a minimalistic syntax, focused on mathematical operations.  

### Key Features:  
- **Portable and Cross-Platform:** The language can run on various platforms by compiling its interpreter for your operating system.  
- **Lightweight and Efficient:** Perfect for quick and resource-friendly computations.  
- **Case-Sensitive Syntax:** Commands are interpreted based on their casing.  
- Specializes in:  
  - **Real Numbers**  
  - **Complex Numbers**  

**MmQL** is particularly suited for users who need fast, precise calculations without the overhead of complex mathematical software.

---

## Why Choose MmQL?  

**MmQL** provides a lightweight and flexible environment for mathematical queries, perfect for students and professionals looking for:  
- A **simple and efficient query language** for real and complex number calculations.  
- A **cross-platform tool**, for any operating system (Windows, Linux and Mac) via compilation.  
- An **unbloated alternative** to large-scale computational platforms.  

With its clean syntax and custom interpreter, **MmQL** delivers a tailored solution for performing mathematical computations. Compile **MmQLC** on your preferred OS, and you're ready to handle your queries with speed and precision!

---

## Dependencies
This project depends upon the following libraries
They are as follows:
- [ ] Boost C++ Library v 1.86.0
- [ ] GNU GMP Library 
- [ ] MPFR Library 
- [ ] FMT Library

---

## Setting Up The Environment for Building From Source  
### Windows:  
> [!IMPORTANT]  
> - [X] **Install MSYS2**. A UCRT Terminal Instance will open then you will enter the following commands one bye one.
> ```bash  
> pacman -Syu # Updates the package database for latest metadata.  
> pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain # Install Latest version of GNU GCC Compiler.
> pacman -S mingw-w64-x86_64-ucrt-gmp # Installs GMP.  
> pacman -S mingw-w64-x86_64-ucrt-mpfr # Installs MPFR.  
> pacman -S mingw-w64-x86_64-ucrt-fmt # Installs FMT.  
> pacman -S mingw-w64-x86_64-ucrt-boost # Installs Boost.  
> ```  
> - [X] Add the base **dir** of `boost` as a new **environment variable**.  
> - [X] Edit both top-level and inner `CMakeLists.txt` files to match your library paths.  
> - [X] Install `scoop`:  
> ```powershell  
> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser  
> Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression  
> ```  
> - [X] Install `cmake` via `scoop`:  
> ```powershell  
> scoop install main/cmake  
> ```  
> - [X] Install `make` via `scoop`:  
> ```powershell  
> scoop install main/make  
> ```  

🎉 Congratulations! 🎉  
You have set up the environment for building **MmQLC** for Windows.  

---

### MacOS:  
> [!IMPORTANT]  
> - [X] **Install Homebrew**. Watch this [guide](https://brew.sh/) for installation instructions.  
> - [X] **Don't close your terminal yet! Paste these commands one by one:**  
> ```bash  
> brew update # Updates the package database for latest metadata.  
> brew install gcc # Installs GCC compiler.  
> brew install gmp mpfr fmt boost cmake make # Installs all required libraries and tools.  
> ```  
> - [X] Add the base **dir** of `boost` as a new **environment variable**.  
> - [X] Edit both top-level and inner `CMakeLists.txt` files to match your library paths.  

🎉 Congratulations! 🎉  
You have set up the environment for building **MmQLC** for MacOS.  

---

### Linux:  
> [!IMPORTANT]  
> - [X] **Install dependencies**. Open your terminal and paste these commands one by one:  
> ```bash  
> sudo apt update && sudo apt upgrade -y  
> sudo apt install g++ gcc make cmake libgmp-dev libmpfr-dev libfmt-dev libboost-all-dev # Installs GCC, libraries, and tools.  
> ```  
> - [X] Add the base **dir** of `boost` as a new **environment variable**.  
> - [X] Edit both top-level and inner `CMakeLists.txt` files to match your library paths.  

🎉 Congratulations! 🎉  
You have set up the environment for building **MmQLC** for Linux.  

---

### Step-By-Step Easy Building Procedure (Same on All OS):
- Open up `cmake-gui` and choose the **base directory** of the `repo`.
- Now, select the **build directory** of your choice (it can be an empty directory).
- Click `Generate` and wait a bit.
- After the generation of the `Makefile` is complete, open a terminal (or `cmd` on Windows) in the build directory.
- Paste this command into the terminal:
  ```cmd
  make
  ```
- Wait for the compilation to complete and... `MmQLC` is ready to use !

---

## Using the MmQL Language For Calculations

**MmQL**  is pretty simple to use , just download either the installer(**Windows**) from **Release** section or the source code **(If you want to build it for yourself.)(Other than Windows)** 

- First of all write queries by using text editor.
- Now for generation of answer file then you should run **MmQLC.exe** with special command line **arguments** defined for **MmQLC** The method for generating answer file from a query file is explained [**Here.**](DetailedDocs/MmQLC_Usage.md).
- To view or see the answers, open the **.ans** in any text editor.

> [!TIP]
>- For Syntax Highlighting; Use **Sublime Text, if you can afford it**.
>- **MmQLC v2.2+** also includes a sophisticated **REPL** mode if you want direct calculations.

 > [!NOTE]
 > - Consider adding **MmQLC.exe** to your environment variables for running it from the shell directly. Click  [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.
 > -  In  the case if you prefer the installer over manual build process then the installer wizard will take care of the above step.

---

## Supported Queries
Following types of queries are supported by **MmQL**.
- ### Queries For Calculations Involving Real Numbers. Click [**Here**](DetailedDocs/REAL_NUMBERS.md) to see.
- ### Queries For Calculations Involving Complex Numbers. Click [**Here**](DetailedDocs/COMPLEX_NUMBERS.md) to see.

---

## Comments in MmQL
The MmQL language only support single-line comments.

**Comment Declaration**: 
Comments looks like this
- `%% Comment`

---

## Possible Errors
> [!CAUTION]
Compound queries or stacking multiple queries on a single line may cause errors.
Nesting two or more queries or using inline comments will also throw errors.
### Examples of errors:
- Compound Queries: `ADD 3,4 FACTORIAL 43`
- Direct Nested Queries: `FACTORIAL ADD 3,4` , `INVERSE_SINE SINE 45`
- Inline Comments: `ADD 4,5 %% add two numbers`


## 🎈🎉 MmQLC v3.0 Has Been Released ! 🎉🎈 
Click To Read [**ChangeLog v3.0**](DetailedDocs/CHANGELOG.md).

---

## Message !:
Active development has been stopped from now till my 12th class exam ends.... Development will be continued somewhere in May 2025.
However, the codebase will be reviewed and optimizations and refactorings may be done after two months if possible.

## License
This project is protected under a custom license. You are permitted to clone this repository for personal and non-commercial use only. 

### Key Restrictions:
1. Forking, redistribution, or creating derivative works is prohibited.
2. The code may not be used for your academic submissions (e.g., final year projects, assignments) or included in resumes/portfolios.
3. Contributions are allowed only with prior written permission. Send an email to **khankkhan123apsacs@gmail.com** if you'd like to contribute.

For more details, see the [LICENSE](LICENSE) file.

---
