# MmQL Based Calculator  ( CLI - Command Line Interface )

MmQL based calculator is a custom lightweight but advanced calculator built with C++23, that works on custom compiled language called **MmQL**.

## MmQL

**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is a compiled language as well as a case sensitive **where uppercase and  lowercase matters**. The compiler (**MmQLC**) is a custom and a very simple compiler. Advanced techniques like Tokenization , Lexical Analysis and IR (**I**ntermediate **R**epresentations) are not used by this custom compiler. Moreover this is just a simple expression / attribute evaluator.

## MmQLC

**MmQLC** stands for **M**athe**m**atical **Q**uery **L**anguage **C**ompiler. This compiler is used by calculator to generate answers.

## How  To  Build:

##### 	Build is supported by CMakeLists.txt as well as Makefile.<br/>

1. CMakeLists.txt<br/>You can use CMakeLists.txt by using CMake build system to generate binaries.<br/> Click to read more about the [**CMake build system**](https://cmake.org/documentation/)

2. Makefile<br/>Use the following simple shell command to compile the source code. There is no included Makefile script you have to generate it using CMake-CLI or GUI.

   ```makefile
   make
   ```

   Click to read more on how to use the [**make build system**.](https://www.gnu.org/software/make/manual/make.html)

## How  To  Use:

Using this calculator is pretty simple  , just download the either the release or the source code **(If you want to build it for yourself.)** 

- First of all write queries by using included editor **MmQL.exe**. You can also use **Notepad++** or any text editor. 

- Now for generation of answer file then you should run **MmQLC.exe .** *The method for compilation of query file is explained [**Here.**](DetailedDocs/MmQLC_Usage.md).*
- To view or see the answers use **MmQL.exe .** *The method for writing the query file OR reading the answer file is explained [**Here.**]()*
- Consider adding **MmQLC.exe** and **MmQL.exe** to your environment variables for running both executables from the shell directly. Click [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.
- In  the case if you prefer the installer over manual build process then the installer wizard will take care of the above step.

## Syntax  For  Queries  Of  The  Supported  Calculations:

- #### Addition: --> `ADD num1,num2`

- #### Subtraction --> `SUBTRACT num1,num2`

- #### Multiplication --> `MULTIPLY num1,num2`

- #### Division --> `DIVIDE num1,num2`

- #### Nth Root Of Number --> `ROOT num1,index`

- #### Number Raised To Nth Power --> `POWER num1,index`

- #### Factorial Of A Number --> `FACTORIAL num1` $\large\ num1\ \in\ (-1,1754] \\ \text{ because this support approximations to 1754! only greater number than that will return } \infty$

- #### Permutation --> `PERMUTATION n,r`

- #### Combination --> `COMBINATION n,r`

- #### Logarithm To  Any Base--> ` LOGARITHM param,base`

- #### Base 10 Log: --> `LOGARITHM param,10`

- #### Base 2 Log --> `LOGARITHM param,2`

- #### Natural Log --> `LOGARITHM param,2.171828`

- #### GCD --> `GCD num1,num2`

- #### LCM --> `LCM num1,num2`

- #### Sin(x)  --> `SINE degrees`

- #### Cos(x) --> `COSINE degrees`

- #### Tan(x) --> `TANGENT degrees`

- #### Arc Tan(x)  --> ` INVERSE_TANGENT param`

- #### Arc  Cos(x) --> `INVERSE_COSINE param`

- #### Arc Sin(x) --> `INVERSE_SINE param`

- #### Sinh(x)   --> `HYP_SINE param`

- #### Cosh(x) --> `HYP_COSINE param`

- #### Tanh(x) --> `HYP_TANGENT param`

- #### Arc Tanh(x) --> `INVERSE_HYP_TANGENT param`

- #### Arc Cosh(x) --> `INVERSE_HYP_COSINE param`

- #### Arc Sinh(x) --> `INVERSE_HYP_SINE param`

- #### Absolute --> `ABSOLUTE num1`

- #### Mod --> `MODULUS num1,num2`

- #### Floor --> `FLOOR num1`

- #### Ceil --> `CEILING num1`

## Contributions  

#### 	 Contributions are welcome but once I learn how to submit a pull request.

## License

#### 	This Project is licensed under the CC0-1.0 License - See The LICENSE file for more details.
