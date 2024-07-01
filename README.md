# System Programming with C

This repository contains implementations of various Linux commands using the C programming language. It serves as a practical guide and reference for understanding system programming concepts and how to interact with the Linux operating system through C code.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

System programming involves developing software that directly interacts with the underlying hardware and operating system. In this repository, we explore Linux system calls and commands implemented in C to gain a deeper understanding of how operating systems function at a low level.

## Features

- Implemented Linux commands:

- **ls**: List directory contents.
- **cp**: Copy files 
- **rmdir**: Remove empty directories.
- **rm**: Remove files
- **cat**: Concatenate files and print on the standard output.
- **grep**: Print lines matching a pattern.
- **pwd**: Print name of current/working directory.
- **echo**: Display a line of text.
- **nano**: Terminal-based text editor
- **touch**: Create new empty files.
- **wc**: Count words, lines, and characters in files
- **mkdir**:  Creates a new directory.
- **date**:  Display the current date and time
- **sleep**:  Pause the execution of a program for a specified number of seconds.
- **chmod**: Changes the permissions of a file or directory to the specified mode.
- **uname**: Get basic information about the OS
- **clear**: Clear terminal

## Installation

To run the programs in this repository, you'll need a Linux environment with a C compiler installed, such as GCC.

1. Clone this repository:
   ```bash
   git clone https://github.com/OsamaRab3/system-programming.git

2. Navigate to the repository directory:
    ```bash
        cd system-programming
3. Compile the programs:
    ```bash 
        gcc program_name.c -o program_name

## Usage

To use any of the implemented commands, follow these steps:

1. **Example**:
    ```bash
        gcc ls.c -o Ls
        ./Ls 
2. **Example**:
    ```bash 
        gcc cat.c -o cat
        ./cat file.text

## Contributing

1. Fork the repository.
2. Create your feature branch (git checkout -b feature/YourFeature).
3. Commit your changes (git commit -am 'Add some feature').
4. Push to the branch (git push origin feature/YourFeature).
5. Create a new Pull Request.



