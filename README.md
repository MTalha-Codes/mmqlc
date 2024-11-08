# MmQL - The Mathematical Query Language
**MmQL** is a very lightweight computational tool in comparison to other contenders like ***MAPLE , Wolfram Mathematica and MATLAB*** developed purely in **C++23**. Though it is not as advanced as these tools but it really do some of the calculations swiftly and perfectly. 
## What is MmQL ?
**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is a compiled ***(Read the important tip block down there !)*** language as well as a case-sensitive **where uppercase and  lowercase matters**. The compiler (**MmQLC**) is a custom and a very simple compiler. Techniques like Tokenization and Parsing are used by this custom compiler.
> [!IMPORTANT]
> **Avoid Confusion Here**
> 
> By compiled language, I am referring to a language that is processed into results, not in the traditional sense of compiling into machine code. You can think of MmQL as being evaluated, interpreted, or processed.

## What is MmQLC ?

**MmQLC** stands for **M**athe**m**atical **Q**uery **L**anguage **C**ompiler. This compiler ***(Read the important tip block down there !)*** is used to generate answer files.
> [!IMPORTANT]
> **Avoid Confusion Here**
> 
> By compiler, I mean an evaluator or processor, not a traditional language compiler like GCC, Clang, or MSVC. The MmQLC simply processes the queries and provides the results.

**MmQL** is very lightweight and fast computing tool specifically designed for students that don't want to use bloated computational tools like **MapleSoft** , **MATLAB** or **Wolfram Mathematica** for calculations that are specific to the following types.
- ***Real Numbers***
- ***Complex Numbers***
<!--- ***Matrices****
- ***Vectors*** -->

## Dependencies
This project depends upon two external libraries and an external header file. They are as follows:
- [ ]  Boost C++ Library v 1.86.0
<!--- [ ] Eigen Linear Algebra Library v 3.4.0-->
- [X] color.hpp for console coloring.

If you want to build from source, then the you should download the libraries described above. Following are the **links** to each of those unchecked libraries.

[**Boost C++ Library - Pre-Built Windows Binaries v 1.86.0**](https://sourceforge.net/projects/boost/files/boost-binaries/1.86.0/boost_1_86_0-msvc-14.1-64.exe/download)

<!--[**Eigen Linear Algebra Library v 3.4.0**](https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip)-->

 The checked library will be provided in the dependencies folder of the project inside the repository.


## Building From Source
> [!IMPORTANT]
> - [X] **Install all the required libraries before proceeding to the build procedure.**

Use the included CMakeLists.txt by using CMake build system to generate binaries.</br> Click to read more about the [**CMake build system**](https://cmake.org/documentation/)

> [!TIP]
> You Can Also Use **cmake-gui** and **mingw32-make** or simple **make** to compile 
> the source code into a fully functional binary.

## Using the MmQL Language For Calculations

**MmQL**  is pretty simple to use , just download either the installer from **Release** section or the source code **(If you want to build it for yourself.)** 

- First of all write queries by using  text editor.
- Now for generation of answer file then you should run **MmQLC.exe** with special command line **arguments** defined for **MmQLC** The method for compiling a query file is explained [**Here.**](DetailedDocs/MmQLC_Usage.md).
- To view or see the answers, open the **.ans** in any text editor.

> [!TIP]
> For Syntax Highlighting; Use **Sublime Text, if you can afford it**.

 > [!NOTE]
 > - Consider adding **MmQLC.exe** to your environment variables for running it from the shell directly. Click  [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.
 > -  In  the case if you prefer the installer over manual build process then the installer wizard will take care of the above step.

## Supported Queries
Following types of queries are supported by **MmQL**.
<!--- ### Queries For Variables. Click [**Here**](DetailedDocs/vars.md) to see.-->
- ### Queries For Calculations Involving Real Numbers. Click [**Here**](DetailedDocs/realNumbers.md) to see.
- ### Queries For Calculations Involving Complex Numbers. Click [**Here**](DetailedDocs/complexNumbers.md) to see.

##  Getting the perfect output
To always achieve the perfect output, arrange the queries in the following order:
<!--- Variables Definition.-->
- Queries Involving Real Numbers.
- Queries Involving Complex Numbers.
## FAQs - Frequently Asked Questions
**FAQ #1 : Why The Queries Needs To Be Ordered Like This ?**</br>
**Answer**: Because **MmQLC** tends to compile the easier queries first and the harder queries second. Thus, by arranging queries in the specified order , you'll always get the perfect output.</br>
**FAQ #2: What If The Queries Are Not Arranged In The Specified Order ? Will MmQLC Throw A Compilation Error ?**</br>
**Answer**: If the queries are not arranged in the above specified order then it is more like to get an unexpected output rather than a compilation error.

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
## 🎈🎉 MmQLC v2.2 Has Been Released ! 🎉🎈 
Click To Read [**ChangeLog v2.2**](DetailedDocs/Change_Log.md).
## Too Many Commits! 😁
- **Most commits are for fixing markdown files.**
- **As a solo developer, it's a challenge to manage both markdown and source code! 😢**
## License
This Project is licensed under the CC0-1.0 License - See The LICENSE file for more details.
