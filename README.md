# 0x16. C - Simple Shell

A UNIX command line interpreter that mimics the behavior of `/bin/sh` with a custom prompt, `#marvel$`.

![App Screenshot](https://github.com/AadelAferyad/simple_shell/blob/main/shell.jpg)

## Introduction

The Simple Shell project is a command line interpreter written in C that reproduces the behavior of `/bin/sh`. It includes features such as handling command lines with arguments, managing the `PATH`, implementing built-in commands like `exit` and `env`, and using a custom prompt, `#marvel$`.

## Compilation

To compile the Simple Shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

## Usage

Once the Simple Shell is compiled,
you can run it by typing the following command:

```bash
./simple_shell
```

This will start the shell and display the custom prompt, `#marvel$`. You can then enter commands at the prompt, just as you would with `/bin/sh`.

## Examples

```bash
#marvel$ ls
Betty
#marvel$ echo "Hello World"
Hello World
#marvel$ pwd
/home/alx
#marvel$ exit
```

## Authors

[Liams-theCreator](https://github.com/Liams-theCreator)

[Aadel Aferyad](https://github.com/AadelAferyad)
