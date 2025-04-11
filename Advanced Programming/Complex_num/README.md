# Complex Number Operations in C++ 🧮✨

This repository contains a C++ implementation of a class `Complex` that models complex numbers and provides various operations for performing arithmetic and polar transformations. 🔢<br>

## Overview 🌐

The `Complex` class includes the following functionalities:
- Setting and initializing a complex number. 🎯
- Performing addition, subtraction, multiplication, and division on complex numbers. ➕➖✖️➗
- Converting complex numbers to polar form. 🔄
- Printing complex numbers in both Cartesian and polar forms. 📊<br>

## Features ⚙️

- **Addition**: Add two complex numbers. ➕
- **Subtraction**: Subtract one complex number from another. ➖
- **Multiplication**: Multiply two complex numbers. ✖️
- **Division**: Divide one complex number by another. ➗
- **Polar Representation**: Convert and print complex numbers in polar form. 🌍
- **Cartesian Representation**: Print complex numbers in the standard Cartesian format. 📐<br>

## Class Definition 📚

The `Complex` class includes:
- **Private Members**: 
  - `RealPart` (double): The real part of the complex number. 💡
  - `ImagPart` (double): The imaginary part of the complex number. 🌙<br>

- **Public Methods**:
  - `Complex(double real = 0, double imag = 0)`: Constructor to initialize a complex number. 🛠️
  - `void setComplex(double real, double imag)`: Sets the real and imaginary parts of the complex number. ⚙️
  - `Complex AddComplex(Complex second)`: Adds two complex numbers. ➕
  - `Complex SubComplex(Complex second)`: Subtracts one complex number from another. ➖
  - `Complex MulComplex(Complex second)`: Multiplies two complex numbers. ✖️
  - `Complex DivComplex(Complex second)`: Divides one complex number by another. ➗
  - `void Convert(double& r, double& theta)`: Converts the complex number to polar form. 🔄
  - `void printPolar()`: Prints the complex number in polar form. 🌍
  - `void printCartesian()`: Prints the complex number in Cartesian form. 📐<br>

## Example Usage 💻

Here’s an example of how you can use the `Complex` class:

```cpp
#include <iostream>
using namespace std;

int main() {
    double R1, I1, R2, I2;
    cin >> R1 >> I1;  // Input for first complex number
    cin >> R2 >> I2;  // Input for second complex number

    Complex c1(R1, I1);  // Create first complex number
    Complex c2(R2, I2);  // Create second complex number

    Complex add = c1.AddComplex(c2);  // Add complex numbers
    add.printCartesian();  // Print result in Cartesian form

    Complex sub = c1.SubComplex(c2);  // Subtract complex numbers
    sub.printCartesian();  // Print result in Cartesian form

    Complex mul = c1.MulComplex(c2);  // Multiply complex numbers
    mul.printCartesian();  // Print result in Cartesian form

    Complex div = c1.DivComplex(c2);  // Divide complex numbers
    div.printPolar();  // Print result in Polar form
    
    return 0;
}<br>

