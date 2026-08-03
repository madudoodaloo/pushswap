_This project has been created as part of the 42 curriculum by masilva-c._

# ft_printf
The project where I learned about variadic function, fell in love with recursion and was blessed by static variables.

## Description
```c
int		ft_printf(const char *, ...);
```
Write a library that contains **`ft_printf()`**, a function that will mimic the original `printf()`, from libc, included in `<stdio.h>` _(man 3 man printf)_ .

### Arguments
* **const char \***: a string, as the fixed argument
* *...* : a variable number of arguments.

### Return Value
* **int**: returns the number of bytes printed (excluding the null byte used to end output to strings)

### External Functions Allowed
* `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`

### Technical Requirements
* Do not implement the buffer management of the original printf().
* Your function has to handle the following conversions: cspdiuxX%
* Your function will be compared against the original printf().
* You must use the command ar to create your library.
Using the libtool command is forbidden.
* Your libftprintf.a has to be created at the root of your repository.
* Your header file must be named ft_printf.h and must contain the prototype of
your ft_printf() function.

---

## Instructions
The function `ft_printf` takes the following conversions:
* %c Prints a single character.
* %s Prints a string (as defined by the common C convention).
* %p The void * pointer argument has to be printed in hexadecimal format.
* %d Prints a decimal (base 10) number.
* %i Prints an integer in base 10.
* %u Prints an unsigned decimal (base 10) number.
* %x Prints a number in hexadecimal (base 16) lowercase format.
* %X Prints a number in hexadecimal (base 16) uppercase format.
* %% Prints a percent sign.

### Usage
#### Integration on your Source Code

To use `ft_printf` in your code, make sure to include the path to the header in your source files that call the function or on your own header:

```c
#include "path/to/ft_printf.h"
```

#### Compilation

Simply compile your code with the libftprintf.a archive.
Considering it is at the root of your directory, you may use this cmdline:

```bash
cc -Wall -Wextra -Werror libftprintf.a your_files.c
```

#### Function Calling Usage
```c
#include "ft_printf.h"

int main(void)
{
    char    c = 'C';
    char    *s = "Moulinette";
    int     d = 42;
    int     i = INT_MIN; // -2147483648
    unsigned int u = UINT_MAX; // 4294967295U
    int     x = 3735928559U; // 0xdeadbeef

    ft_printf("Norm Error %c: %s stole %p to turn %d & %i into %u%% pure %x or %X!\n", 
           c, s, (void *)&s, d, i, u, x, x);
    return (0);
}
```

## Algorithm and Data Structures
`ft_printf` is a variadic function.

*what is the difference between the printf buffer management and my ft_printf?*
This means it receives a certain first argument (in this case, a string), followed by a variable number os arguments.
Unlike libc printf, my ft_printf prints on terminal the content as it goes through the variables - instead of redirecting it to a buffer that is only flushed upon error, '\n', when it's full, before input is read and on the end of the program. Despite not managing it the same way, it does have the behaviour as printf upon error - it just prints the output faster on the terminal, as it doesn't pile up information in the buffer.

*Data structure wise*, i implemented a static variable to keep track of all printed characters on stdout, depending on write() return value - making sure it only increments when a byte was written onto the terminal.


## Resources
### Online documentation
#### Buffering & Output Stream Controls
* [Medium — Understanding Buffers in C: Why Your Printf Might Not Show Up Immediately](https://medium.com/@sreehema2025/understanding-buffers-in-c-why-your-printf-might-not-show-up-immediately-98c4d9d60d75)
* [Linux Manual Pages — printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html)
* [GeeksforGeeks — Buffer in C Programming](https://www.geeksforgeeks.org/c/buffer-in-c-programming/)

#### Makefile Rules & File Pattern Matching
* [Earthly — Using Makefile Wildcards](https://earthly.dev/blog/using-makefile-wildcards/)
* [Wikipedia — Glob (Programming)](https://en.wikipedia.org/wiki/Glob_(programming))

#### Variadic Architecture & Argument Parsing
* [GeeksforGeeks — Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
* [Linux Manual Pages — stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html)
* [Tutorialspoint — C Standard Library: Macro va_arg](https://www.tutorialspoint.com/c_standard_library/c_macro_va_arg.htm)
* [Gustedt — va_arg Functions and Macros](https://gustedt.wordpress.com/2010/08/04/va_arg-functions-and-macros/)
* [Quora — How does the va_arg macro in C know the bounds of the variable arguments passed](https://www.quora.com/How-does-the-va_arg-macro-in-C-know-the-bound-of-the-variable-arguments-passed-I-try-to-implement-my-own-version-of-va_arg-but-I-am-not-able-to-determine-the-last-argument-to-be-pointed-by-va_list-AP-Mine-goes)
* [Stack Overflow — How does va_arg actually work in variadic functions](https://stackoverflow.com/questions/68514906/how-does-va-arg-actually-work-in-variadic-functions)
* [Stack Overflow — How are variadic variables represented on the stack](https://stackoverflow.com/questions/63056235/how-are-variadic-variables-represented-on-the-stack)
### AI Usage
I used AI to help me format this `Readme.md` .
In regards to code development, no AI was used.