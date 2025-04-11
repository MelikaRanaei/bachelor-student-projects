# Polynomial Operations (Poly Class) 📐

This C++ program defines a class `Poly` for representing polynomials and performing operations like addition, multiplication, and comparison on them. The class allows users to input polynomials, display them, and perform various operations such as addition and multiplication. 🚀

## Features ⚙️

- **Polynomial Representation**: The `Poly` class uses an array to represent polynomial coefficients. 📊
- **Polynomial Addition**: You can add two polynomials using the `+` operator. ➕
- **Polynomial Multiplication**: You can multiply two polynomials using the `*` operator. ✖️
- **Equality and Inequality Checks**: The `==` and `!=` operators are overloaded to compare two polynomials. ⚖️
- **Indexing**: You can access polynomial coefficients using the `[]` operator. 🔢

## Code Structure 🛠️

### Poly Class

- **Constructor**: 
  - Initializes the polynomial degree and coefficients. 
  - Sets coefficients to zero by default. 🔧
  
- **Methods**:
  - `set(int d, int list[])`: Sets the degree and coefficients for the polynomial. 📝
  - `print()`: Prints the polynomial in human-readable form. 📜
  - `isMember(int)`: Checks if a coefficient exists within the polynomial. 🔍
  - Overloaded operators:
    - `==`: Checks if two polynomials are equal. ✅
    - `!=`: Checks if two polynomials are not equal. ❌
    - `+`: Adds two polynomials. ➕
    - `*`: Multiplies two polynomials. ✖️
    - `[]`: Accesses a polynomial coefficient by index (both const and non-const). 🔢

### Main Function

The `main()` function reads two polynomials, performs operations on them, and prints the results:

1. Polynomial input. 🖊️
2. Print the polynomials. 🖨️
3. Perform addition and multiplication. ➕✖️
4. Check for equality and inequality between the polynomials. ⚖️<br>

## Example Usage 📥

### Input

3 2 5 3 1 2 1 3 2 1 2 3<br>

### Output

3x^3+5x^2+3x+1 x^2+3x+2 2 5 3x^5+8x^4+11x^3+9x^2+8x+3 no yes


