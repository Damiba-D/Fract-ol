# Fractol

*This project has been created as part of the 42 curriculum by ddamiba.*

## Description

Fractol is a graphical project that explores the fascinating world of fractals through interactive visualization. The project implements a fractal rendering program using the MiniLibX graphics library, allowing users to explore and interact with beautiful mathematical patterns in real-time.

The program renders two main types of fractals:
- **Mandelbrot Set**: A classic fractal discovered by Benoit Mandelbrot, showcasing infinite complexity and self-similarity
- **Julia Set**: A related family of fractals with customizable parameters that produce varying patterns

Users can zoom, pan, adjust colors, and modify rendering parameters to explore these mathematical structures in detail. The project demonstrates the intersection of mathematics, computer graphics, and interactive programming.

## Instructions

### Compilation

The project uses a Makefile for compilation. Simply run:

```bash
make
```

This will compile the project along with its dependencies (libft and minilibx).

### Execution

The program accepts different arguments depending on the fractal type:

**For Mandelbrot Set:**
```bash
./fractol mandelbrot
```

<img width="1008" height="640" alt="image" src="https://github.com/user-attachments/assets/6d24e1a6-fa7c-4eb9-bfe9-aeb89233aeb2" />

**For Julia Set:**
```bash
./fractol julia <real_part> <imaginary_part>
```

Where `<real_part>` and `<imaginary_part>` are floating-point numbers between -1 and 1.

**Example:**
```bash
./fractol julia −0.70176 −0.3842
```

<img width="818" height="505" alt="image" src="https://github.com/user-attachments/assets/acbb2379-69d9-4cc8-9b58-b1c461887b2e" />

### Controls

- **Arrow Keys**: Pan the fractal view (Up, Down, Left, Right)
- **Mouse Scroll**: Zoom in (scroll up) / Zoom out (scroll down)
- **Left Mouse Click**: Reset view to default position and zoom
- **Right Mouse Click**: Toggle smooth color interpolation
- **Keypad +/-**: Increase/decrease iteration depth (detail level)
- **1 Key**: Switch to Black & White color scheme
- **2 Key**: Switch to Purple & Orange color scheme
- **ESC**: Close the window and exit the program

### Requirements

- Linux operating system (Ubuntu 24 or similar)
- X11 development libraries
- GCC compiler
- Make

**Installing Dependencies (Debian/Ubuntu):**
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

## Features

- Real-time fractal rendering with the Mandelbrot and Julia sets
- Interactive zoom and pan functionality with mouse-centric zooming
- Adjustable iteration depth for varying levels of detail
- Multiple color schemes with smooth interpolation options
- Optimized rendering using direct pixel manipulation
- Custom parameter support for Julia sets
- Responsive window management and event handling

## Technical Details

The project is structured with the following key components:

- **fractal_init.c**: Initializes the fractal structure, window, and event handlers
- **render.c**: Core rendering logic for computing and drawing fractals
- **math_utils.c**: Mathematical utilities including complex number operations and coordinate mapping
- **events.c**: Event handling for mouse and keyboard interactions
- **parsing.c**: Input validation and argument parsing

The rendering uses the escape-time algorithm to determine whether points belong to the fractal set, with color mapping based on the number of iterations before escape.

## Resources

### Documentation & Tutorials
- [Fractol Tutorial by CodeVault](https://youtu.be/ANLW1zYbLcs?si=ydH8yKkz4gZrtS63) - Comprehensive video guide on implementing fractol
- [Mandelbrot Set - Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set) - Mathematical background and theory
- [Julia Set - Wikipedia](https://en.wikipedia.org/wiki/Julia_set) - Detailed explanation of Julia sets
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Graphics library reference
- [42 Docs - Fractol](https://harm-smits.github.io/42docs/projects/fract-ol) - Project-specific documentation

### AI Usage

AI assistance was utilized in a limited capacity during the development of this project:

- **Logic Verification**: AI was used to check and verify the mathematical logic behind certain rendering functions, particularly in the escape-time algorithm implementation and complex number operations
- **Code Review**: Minor assistance in reviewing function logic for correctness and efficiency

All core algorithms, project architecture, and implementation decisions were developed independently. AI was not used for code generation or structural design of the project.

## Project Structure

```
.
├── fractol.c              # Main program entry point
├── fractol.h              # Header file with structures and prototypes
├── fractal_init.c         # Initialization functions
├── render.c               # Fractal rendering logic
├── math_utils.c           # Mathematical operations and utilities
├── events.c               # Event handlers for user interaction
├── parsing.c              # Argument parsing and validation
├── Makefile               # Build configuration
├── libft/                 # Custom C library
├── minilibx/              # Graphics library
└── README.md              # This file
```
