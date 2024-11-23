# MmQL - The Mathematical Query Language
**MmQL** is a very lightweight computational tool in comparison to other strong contenders like ***MAPLE , Wolfram Mathematica and MATLAB*** developed purely in **C++23**. Though it is not as advanced as these tools but it really do some of the calculations swiftly and perfectly. 

---

## What is MmQL ?
**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is an interpreted language as well as a case-sensitive **where uppercase and  lowercase matters**. The interpreter (**MmQLC**) is a custom and and yet a very simple interpreter. Techniques like Tokenization and Parsing are used by **MmQLC**.

**MmQL** is a lightweight, *cross-platform* query language tailored for mathematical computations. Designed for speed and simplicity, **MmQL** allows users to write precise mathematical queries, offering an efficient alternative to tools like **MAPLE**, **Wolfram Mathematica**, or **MATLAB**.
> [!NOTE]
> Please note that **MmQL** is not a symbolic language and it doenot uses CAS (Computer Algebra Systems)

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
- A **cross-platform tool**, customizable for your operating system via compilation.  
- An **unbloated alternative** to large-scale computational platforms.  

With its clean syntax and custom interpreter, **MmQL** delivers a tailored solution for performing mathematical computations. Compile **MmQLC** on your preferred OS, and you're ready to handle your queries with speed and precision!

---

## Dependencies
This project depends upon the following libraries
They are as follows:
- [ ]  Boost C++ Library v 1.86.0
- [ ] GNU GMP Library **(mingw64)**
- [ ] MPFR Library **(mingw64)**
- [ ] FMT Library **(mingw64)**

---

## Setting Up The Environment for Building From Source  
### Windows:  
> [!IMPORTANT]  
> - [X] **Install MinGW. Watch this [video](https://youtu.be/oC69vlWofJQ) for detailed installation guide by `Microsoft` via `MSYS2`**  
> - (***!! Remove the `-ucrt` from the given command as shown in the video !!***)  
> - [X] **Don't close `MSYS2` terminal yet! Paste these commands one by one:**  
> ```bash  
> pacman -Syu # Updates the package database for latest metadata.  
> pacman -S mingw-w64-x86_64-gcc # Installs GCC compiler.  
> pacman -S mingw-w64-x86_64-gmp # Installs GMP.  
> pacman -S mingw-w64-x86_64-mpfr # Installs MPFR.  
> pacman -S mingw-w64-x86_64-fmt # Installs FMT.  
> pacman -S mingw-w64-x86_64-boost # Installs Boost.  
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

- First of all write queries by using  text editor.
- Now for generation of answer file then you should run **MmQLC.exe** with special command line **arguments** defined for **MmQLC** The method for generating answer file from a query file is explained [**Here.**](DetailedDocs/MmQLC_Usage.md).
- To view or see the answers, open the **.ans** in any text editor.

> [!TIP]
> For Syntax Highlighting; Use **Sublime Text, if you can afford it**.

 > [!NOTE]
 > - Consider adding **MmQLC.exe** to your environment variables for running it from the shell directly. Click  [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.
 > -  In  the case if you prefer the installer over manual build process then the installer wizard will take care of the above step.

---

## Supported Queries
Following types of queries are supported by **MmQL**.
- ### Queries For Calculations Involving Real Numbers. Click [**Here**](DetailedDocs/realNumbers.md) to see.
- ### Queries For Calculations Involving Complex Numbers. Click [**Here**](DetailedDocs/complexNumbers.md) to see.

---

##  Getting the perfect output
To always achieve the perfect output, arrange the queries in the following order:
- Queries Involving Real Numbers.
- Queries Involving Complex Numbers.
## FAQs - Frequently Asked Questions
**FAQ #1 : Why The Queries Needs To Be Ordered Like This ?**</br>
**Answer**: Because **MmQLC** tends to interpret the easier queries first and the harder queries second. Thus, by arranging queries in the specified order , you'll always get the perfect output.</br>
**FAQ #2: What If The Queries Are Not Arranged In The Specified Order ? Will MmQLC Throw An Error ?**</br>
**Answer**: If the queries are not arranged in the above specified order then it is more like to get an unexpected output rather than a interpretation error.

> [!NOTE]
> The above terms not applied to interactive mode from **MmQLC v2.2**(See Change log for more details)

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
- Nested Queries: `FACTORIAL ADD 3,4` , `INVERSE_SINE SINE 45`
- Inline Comments: `ADD 4,5 %% add two numbers`


## 🎈🎉 MmQLC v2.3 Has Been Released ! 🎉🎈 
Click To Read [**ChangeLog v2.3**](DetailedDocs/Change_Log.md).

---

## Too Many Commits! 😁
- **Most commits are for fixing markdown files.**
- **As a solo developer, it's a challenge to manage both markdown and source code! 😢**

---

## License
This Project is licensed under the CC0-1.0 License - See The LICENSE file for more details.

---
