# Inherited Geometry Classes 

This repository contains an implementation of `Circle` and `Cylinder` classes demonstrating object-oriented programming concepts such as inheritance, constructors, destructors, and operator overloading in C++.

### Features ⚙️

- **Circle Class**:<br>
  - Represents a circle with a radius 🌍.
  - Can compute the area 🔢 and circumference (perimeter) 📏 of the circle.
  - Includes input validation for setting a positive radius ✅.<br>

- **Cylinder Class** (inherits from Circle):<br>
  - Represents a cylinder with a height and a circular base 🎲.
  - Inherits the properties of the `Circle` class, allowing access to the radius.
  - Can compute the surface area 🌐 and volume 📦 of the cylinder.
  - Has a custom implementation of the `pier()` method (overridden).
  - Supports input and output via stream operators for easy user interaction 💻.<br>


### Functionality <br>

Circle Methods:<br>

- Area(): Calculates and returns the area of the circle 🌕.

- pier(): Calculates and returns the circumference (perimeter) of the circle 🌍.

- setRadius(): Sets the radius, ensuring it's a positive value .

- print(): Prints the radius of the circle.

- Cylinder Methods:

- Area(): Calculates and returns the surface area of the cylinder .

- volume(): Calculates and returns the volume of the cylinder 📦.

- pier(): Overrides the circle's pier() method and returns 0 (not used).

- Overloaded << and >> operators for easy stream input/output operations 💬.

