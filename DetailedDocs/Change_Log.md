# 🎉 MmQLC v2.2 Released 🎉
## Change Log:
### New Queries Added
- **24 New Queries Has Been Added to MMQL Language and are well recognized by MmQLC v2.2.**
> [!NOTE]
> - 12 Trigonometric Queries Added for Real Numbers
> - 12 Trigonometric Queries Added for Complex Numbers
### Arbitrary Number Precision Supported !
- ***MmQLC* now support arbitrary precision for both integers and floating point numbers**.
### New Command Line Options Added
- **MmQLC v2.2 Supports Following Command Line Options.**
1. `mmqlc --htc`: **Show The Command For Invoking Compilation Process.**
2. `mmqlc --version`: **Show Current Version of MmQLC.**
3. `mmqlc --help`: **Show List of All Available MmQLC Command-Line Options.**
4. `mmqlc --live`: **Launch a Real Time Query Interpretation Session.**
### Scientific Notation Support
- **Complex and Real Queries Support Numerical Arguments In Both Standard and Scientific Notation.**

**For Example (Scientific Notation)**
1. `QUERY 7e+10`
2. `QUERY 0.45e+123,3.456e+5`
3. `QUERY 3e-5+2e+5i`
4. `QUERY 0.45e+123+3.456e+5i,3e-5+2e+5i`
### Dynamic Query Type Deduction
- **MmQLC now automatically deduce the query type based on argument**
### GCC Style Error Handling
- **MmQLC mimics nearly all of the gcc/g++ error handling styles.**
