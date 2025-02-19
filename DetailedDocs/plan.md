# Updates Regarding MmQL
These are the future plans are the updates that will be pushed to this repository in future.
## Feature 1: Support for Description Comments or Inline Comments.
`ADD 3,4 %% Adds the numbers 3 and 4 and then print result`
## Feature 2: Batch REPL Execution.
`ADD 3,2; ADD 3e+3,3e-2; SIN 45; ........ ; nth QUERY `
## Feature 3: More Robust Support For Variables
Over the passage of time variables will develop in more robust manner.
## Feature 4: Custom Arguments for `ADD` , `SUBTRACT` and `MULTIPLY`:
You can now pass 'n' number of arguments to query by specifying number of parameters next to query name.
```mmql
QUERY[n] arg1,arg2,.....,arg_n; where QUERY = ADD || SUBTRACT || MULTIPLY
```
## Feature 5: Extended Parameter Recognition:
When working with real and complex numbers, you now dont need to specify the imaginary part for real numbers as `a+0i`.
## Feature 6: Multiline Comments Support:
```mmql
%%<
... Comment Line 1
... Comment Line 2
...    .     .   .
...    .     .   .
...    .     .   .
... Comment Line n
>%%
```
## Feature 7: Support For Graphing via gnuplot.
You can now plot functions in mmql via gnuplot
## Feature 8: Linear Algebra Support.

