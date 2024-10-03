
# MmQL - The Mathematical Query Language
**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is a compiled language as well as a case-sensitive **where uppercase and  lowercase matters**. The compiler (**MmQLC**) is a custom and a very simple compiler. Techniques like Lexing and Parsing are used by this custom compiler.

## What is MmQLC ?

**MmQLC** stands for **M**athe**m**atical **Q**uery **L**anguage **C**ompiler. This compiler is used to generate answer files.
## Why it was needed ?
**MmQL** is very lightweight computing tool specifically designed for students that don't want to use bloated and complex softwares like **MapleSoft** , **MATLAB** or **Mathematica** for calculations that are specific to the following types.
- ***Real Numbers***
- ***Complex Numbers***
- ***Matrices (2x2 and 3x3)***
- ***Vectors (2D and 3D)***
## Building From Source
Use the included CMakeLists.txt by using CMake build system to generate binaries.<br/> Click to read more about the [**CMake build system**](https://cmake.org/documentation/)


## Using the MmQL Language For Calculations

**MmQL**  is pretty simple to use , just download either the installer from **Release** section or the source code **(If you want to build it for yourself.)** 

- First of all write queries by using  **Notepad++ , VS Code** or any text editor.
- Now for generation of answer file then you should run **MmQLC.exe** with special command line **arguements** defined for **MmQLC** *The method for compiling a query file is explained [**Here.**](DetailedDocs/MmQLC_Usage.md).*
- To view or see the answers use also **Notepad++ , VS Code**. Right-Click the ans file and choose open with **Notepad++ , VSCode**.
- > Note: This all can also be done on the OS included **notepad** as well.
- Consider adding **MmQLC.exe** to your environment variables for running it from the shell directly. Click [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.
- > In  the case if you prefer the installer over manual build process then the installer wizard will take care of the above step.
## Supported Queries
Following types of queries are supported by **MmQL**.
- ### Queries For Calculations Involving Real Numbers. Click [**Here**](DetailedDocs/realNumbers.md) to see.
- ### Queries For Calculations Involving Complex Numbers. Click [**Here**](DetailedDocs/complexNumbers.md) to see.
- ### Queries For Calculations Involving Matrices *(Under **Construction**.)* Click [**Here**](DetailedDocs/matrices.md) to see.
- ### Queries For Calculations Involving Vectors *(Under **Construction**.)* Click [**Here**](DetailedDocs/vectors.md) to see.
##  Getting the perfect output
To always achieve the perfect output, arrange the queries in the following order:
- Queries Involving Real Numbers.
- Queries Involving Complex Numbers.
 - Queries Involving 2D Vectors.
- Queries Involving 3D Vectors.
- Queries Involving 2x2 Matrices.
- Queries Involving 3x3 Matrices.

**FAQ #1 : Why The Queries Needs To Be Ordered Like This ?**</br>
**Answer**: Because **MmQL** tends to compile the easier queries first and the harder queries second. Thus, by arranging queries in the specified order , you'll always the perfect output.</br>
**FAQ #2: What If The Queries Are Not Arranged In The Specified Order ? Will MmQLC Throw A Compilation Error ?**</br>
**Answer**: If the queries are not arranged in the above specified order then it is more like to get an unexpected output than a compilation error.

## Comments in MmQL
The MmQL language only support single-line comments.
**Comment Declaration**: Comments looks like this
- `%% Comment`
## Possible Errors
Compound queries or **stacking more than one query on a single line** may throw an error.</br>
 Nesting two or more than two queries will also the same compilation error.</br>
 Inline comments will also throw error.</br>
 Leaving a line empty will not throw an error. In this latest update comments and empty lines are supported.
 **Examples**
- **Compound Queries**
  - `ADD 3,4 FACTORIAL 43`
 - **Nested Queries**
   -    `FACTORIAL ADD 3,4`
   -    `INVERSE_SINE SINE 45`
-  **Inline Comments**
   -  `ADD 4,5 %% add two numbers`

## License
This Project is licensed under the CC0-1.0 License - See The LICENSE file for more details.
