# Overview:
This project is a custom implementation of the printf function in the C programming language. The printf function is a standard library function in C used for formatted output. This project aims to replicate the basic functionality of printf while providing some additional features.

# Features:
*Modular Design:* The implementation is divided into smaller functions for better code organization and readability.
Variable Argument Handling: Utilizes the <stdarg.h> library to handle variable numbers of arguments.
Format Specifiers: Supports a subset of format specifiers commonly used in the standard printf function, including "%c" , "%s", "%d", "%i", "%u", "%x", "%X", "%p", and "%%".
Error Handling: Checks for invalid inputs and returns -1 in case of errors, allowing for better error management.

## Usage:
To use this printf implementation, include the printf.h header file in your C program. The ft_printf function can then be called with a format string and variable arguments.

'''

#include "printf.h"

int main() {
    ft_printf("Hello, %s! The answer is %d.\n", "World", 42);
    return 0;
}

'''

## Function Descriptions
*int ft_printf(const char *format, ...)**
The main function responsible for parsing the format string and printing formatted output. It calls helper functions for handling different format specifiers.

*int pr_format(char spec, va_list lst_args)*
Handles individual format specifiers and calls corresponding functions to print the formatted output.

*int print_u(unsigned int n)*
Prints an unsigned integer.

*int print_hex(unsigned long n, char spec)*
Prints an unsigned long integer in hexadecimal format. Supports both uppercase and lowercase letters for hex digits.

*int print_ptr(unsigned long ptr)*
Prints a pointer address in hexadecimal format with a '0x' prefix.

**Error Handling**
The functions return -1 in case of invalid inputs or errors during execution. It is recommended to check the return values for error handling.
