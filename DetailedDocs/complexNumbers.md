# Queries For Calculation Involving Complex Numbers
## Arithmetic Operations
- **Addition**: $ z_1+z_2 $ --> `CMPLX_ADD a+bi,c+di`
- **Subtraction**: $ z_1-z_2 $ --> `CMPLX_SUBTRACT a+bi,c+di`
- **Multiplication**: $ z_1\cdot z_2 $ --> `CMPLX_MULTIPLY a+bi,c+di`
- **Division**: $ \large \frac{z_1}{z_2} $ --> `CMPLX_DIVIDE a+bi,c+di`
- **Modulus**: $ \left|z\right| $ --> `CMPLX_MODULUS a+bi`
- **Argument**: $ \arg(z) $ --> `CMPLX_ARGUMENT a+bi`
- **Complex Conjugate**: $ \overline{z} $ --> `CMPLX_CONJUGATE a+bi`
## Algebraic Operations
- **Exponentiation**: $ z^n $ --> `CMPLX_POWER a+bi,n+0i`
- **Nth Root**: $ \sqrt[n]{z} $ --> `CMPLX_ROOT a+bi,n+0i`
- **Complex Exponentiation**: $ {z_1}^{z_2} $ --> `CMPLX_POWER a+bi,c+di`
- **Complex Root**: $ \sqrt[z_1]{z_2} $ --> `CMPLX_ROOT a+bi,c+di`
- **Complex Natural Logarithm**: $ \ln(z) $ --> `CMPLX_NATURAL_LOGARITHM a+bi`
- **Base $e$ Exponentiation**: $ e^{z} $ --> `CMPLX_EXP a+bi`
## Trigonometric Operations
-  **Sin(z)**: $ \sin(z) --> `CMPLX_SINE a+bi`
-  **Cos(z)**: $ \cos(z) $ --> `CMPLX_COSINE a+bi`
-  **Tan(z)**: $ \tan(z) $ --> `CMPLX_TANGENT a+bi`
- **Cot(z)**: $ \cot(z) $ --> `CMPLX_COTANGENT a+bi`
- **Sec(z)**: $ \sec(z) $ --> `CMPLX_SECANT a+bi`
- **Csc(z)**: $ \csc(z) $ --> `CMPLX_COSECANT a+bi`
## Inverse Trigonometric Operations
-  **Arc Sin(z)**: $ \sin^{-1}(z) $ --> `CMPLX_INVERSE_SINE a+bi`
-  **Arc Cos(z)**: $ \cos^{-1}(z) $ --> `CMPLX_INVERSE_COSINE a+bi`
-  **Arc Tan(z)**: $ \tan^{-1}(z) $ --> `CMPLX_INVERSE_TANGENT a+bi`
- **Arc Cot(z)**: $ \cot^{-1}(z) $ --> `CMPLX_INVERSE_COTANGENT a+bi`
- **Arc Sec(z)**: $ \sec^{-1}(z) $ --> `CMPLX_INVERSE_SECANT a+bi`
- **Arc Csc(z)**: $ \csc^{-1}(z) $ --> `CMPLX_INVERSE_COSECANT a+bi`
## Hyperbolic Trigonometric Operations
- **Sinh(z)**: $ \sinh(z) $  --> `CMPLX_HYP_SINE a+bi`
- **Cosh(z)**: $ \cosh(z) $ --> `CMPLX_HYP_COSINE a+bi`
- **Tanh(z)**: $ \tanh(z) $ --> `CMPLX_HYP_TANGENT a+bi`
- **Coth**: $ \coth(z) $ --> `CMPLX_HYP_COTANGENT a+bi`
- **Sech**: $ \text{sech}(z) $ --> `CMPLX_HYP_SECANT a+bi`
- **Csch**: $ \text{csch}(z) $ --> `CMPLX_HYP_COSECANT a+bi`
## Inverse Hyperbolic Trigonometric Operations
- **Arc Sinh(z)**: $ \sinh^{-1}(z) $ --> `CMPLX_INVERSE_HYP_SINE a+bi`
- **Arc Cosh(z)**: $ \cosh^{-1}(z) $ --> `CMPLX_INVERSE_HYP_COSINE a+bi`
- **Arc Tanh(z)**: $ \tanh^{-1}(z) $ --> `CMPLX_INVERSE_HYP_TANGENT a+bi`
- **Arc Coth**: $ \coth(z) $ --> `CMPLX_INVERSE_HYP_COTANGENT a+bi`
- **Arc Sech**: $ \text{sech}(z) $ --> `CMPLX_INVERSE_HYP_SECANT a+bi`
- **Arc Csch**: $ \text{csch}(z) $ --> `CMPLX_INVERSE_HYP_COSECANT a+bi`
<!--> [!IMPORTANT]
> You can invoke any of these queries with variables as `QUERY $a,$b` where a and b are two distinct variables, although they can be the same like `QUERY $a,$a`.-->