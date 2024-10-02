
# MmQL Based Calculator  ( CLI - Command Line Interface )

MmQL based calculator is a custom lightweight but advanced calculator built with C++23, that works on custom compiled language called **MmQL**.

## MmQL

**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is a compiled language as well as a case sensitive **where uppercase and  lowercase matters**. The compiler (**MmQLC**) is a custom and a very simple compiler. Advanced techniques like Lexing and Parsing are used by this custom compiler.

## MmQLC

**MmQLC** stands for **M**athe**m**atical **Q**uery **L**anguage **C**ompiler. This compiler is used by calculator to generate answers.

## How  To  Build:

##### 	Build is supported only via CMake<br/>

- CMake<br/>Use the included CMakeLists.txt by using CMake build system to generate binaries.<br/> Click to read more about the [**CMake build system**](https://cmake.org/documentation/)


## How  To  Use:

Using this calculator is pretty simple  , just download either the release or the source code **(If you want to build it for yourself.)** 

- First of all write queries by using  **Notepad++ , VS Code** or any text editor.
- Now for generation of answer file then you should run **MmQLC.exe .** *The method for compiling a query file is explained [**Here.**](DetailedDocs/MmQLC_Usage.md).*
- To view or see the answers use also **Notepad++ , VS Code**.Right Click the ans file and choose open with **Notepad++ , VSCode**.
- > Note: This all can also be done on the OS included **notepad** as well.
- Consider adding **MmQLC.exe** to your environment variables for running it from the shell directly. Click [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.
- In  the case if you prefer the installer over manual build process then the installer wizard will take care of the above step.
## Supported Queries
Following types of queries are supported by **MmQL**.
- ### Queries For Calculations Involving Real Numbers. Click [**Here**](DetailedDocs/realNumbers.md) to see.
- ### Queries For Calculations Involving Complex Numbers. Click [**Here**](DetailedDocs/complexNumbers.md) to see.
- ### Queries For Calculations Involving Matrices *(Under **Construction**.)* Click [**Here**](DetailedDocs/matrices.md) to see.
- ### Queries For Calculations Involving Vectors *(Under **Construction**.)* Click [**Here**](DetailedDocs/vectors.md) to see.
## Comments in MmQL
The MmQL language only support single-line comments.
**Comment Declaration**: Comments looks like this
- `%% Comment`
>## Possible Errors
> Compound queries or **stacking more than one query on a single line** may throw an error.
> Nesting two or more than two queries will also the same compilation error.
> Inline comments can throw error.
> Leaving a line empty will not throw an error. In this latest update comments and empty lines are supported.
>### Examples
>- #### Compound Queries
> > - `ADD 3,4 FACTORIAL 43`
> - #### Nested Queries
> > 1. `FACTORIAL ADD 3,4`
> > 2. `INVERSE_SINE SINE 45`
> - #### Inline Comments
> > - `ADD 4,5 %% add two numbers`

## License

#### This Project is licensed under the CC0-1.0 License - See The LICENSE file for more details.
