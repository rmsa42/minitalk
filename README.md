# Minitalk [42 Project]
This 42 project challenges us to communicate between two processes using `signals`. All files and directories containing *_bonus are for the Bonus part

## Table of Contents
1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [Dependencies](#dependencies)
4. [How to Use](#how-to-use)
5. [Code Examples](#code-examples)
6. [Contributing](#contributing)

## Overview


## Project Structure
- `minitalk/`: Main directory containing the src and src_bonus directories, and the Makefile.
- `src`: Contains all the source code.
- `libft`: Contains libft library
- `src_bonus`: Contains all the source code for the bonus part.

## Dependencies
- Libft (it is already included, more information on how to use it [here](https://github.com/rmsa42/libft#how-to-use))

## Usage Instructions
1. Clone the repository.
2. Navigate to the `libft` directory: `cd libft`.
3. Compile the library: `make`.
4. Include the header in your source files: `#include "libft.h"`.
5. Link the library to your program: `gcc example.c -L[path_to_libft_dir] -lft`.

## Code Examples
```c
#include "libft.h"

int main() {
    ft_putstr("Hello, Libft!\n");
    return 0;
}
````

## Contributing
I welcome contributions. If you have any bug fix or improvement, feel free to submit a pull request on the repository.
