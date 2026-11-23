# MY PREPROCESSOR

## Project Description

MY PREPROCESSOR is a basic C preprocessor developed using C programming.

The main objective of this project is to understand how preprocessing works before the compilation of a C program.

The program accepts a C source file as input and generates a preprocessed output file with the `.i` extension.

## Features

- Removal of single-line comments (`//`)
- Removal of multi-line comments (`/* */`)
- Header file inclusion
- Object-like macro replacement
- One-argument function-like macro replacement
- Automatic generation of `.i` output file

## Technologies Used

- C Programming
- GCC Compiler
- Ubuntu Linux
- Makefile

## Project Structure

```text
my-preprocessor/
│
├── main.c
├── comment_removal.c
├── comment_removal.h
├── file_inclusion.c
├── file_inclusion.h
├── macro_handler.c
├── macro_handler.h
├── myheader.h
├── sample.c
├── sample.c.i
├── Makefile
└── README.md
```

## Working Principle

The preprocessor performs three main operations:

1. Comment Removal
2. Header File Inclusion
3. Macro Processing

### Processing Flow

```text
Input C File
     |
     v
Comment Removal
     |
     v
Header File Inclusion
     |
     v
Macro Processing
     |
     v
Output .i File
```

## Compilation

Compile the project using:

```bash
make
```

## Execution

Run the preprocessor by providing a C source filename:

```bash
./mypreprocessor sample.c
```

The generated output file will be:

```text
sample.c.i
```

## Compile and Run the Output

```bash
gcc -x c sample.c.i -o test
./test
```

## Concepts Used

- Functions
- Pointers
- Arrays and strings
- File handling
- Command-line arguments
- Header files
- String handling functions
- Modular programming
- Makefile

## Limitations

- Supports basic macro replacement.
- Supports only one-argument function-like macros.
- Does not support nested header file inclusion.
- Does not implement all features of the standard C preprocessor.

## Author

Ashvin CT

Electronics and Communication Engineering
