This project has been created as part of 42 curriculum by masilva-

# LIBFT  
#### developed by masilva- @ 42 Lisboa

## Description:  
Common core's very first project consists on creating a library of useful functions.
This project was developed in 3 parts, each containing a set of functions to later on use on 42
projects and to better understand memory manipulation and iteration on diferent data types.
The ft_*.c files (were the functions are defined) must be delivered alongside a header file, containing all function declaration, and a Makefile, that creates the libft archive with the .o's.

## Details:
### part 1: libc functions  
mostly basic manipulation of memory and strings, the challenge was to study standard libc functions 
and to reproduce them accordingly. the only extern function allowed was malloc().  

_aspects to point:_  
unsigned char vs char; size_t vs int; static vs dinamic variables;  
libraries glibc vs libc vs bsd libc vs <bsd/string.h>  
compiling with -std=c99 flag vs -lbsd flag  
restrict qualifier; static function declaration;  
seg fault; stuck on loop;  
undefined reference to; linking errors; pre-compilation errors; function not defined;  
memory leaks; read of size x; write size x; uninitialized variable;  
  
### part 2: additional functions  
develop a set of functions that are either not included in the libc, or exist in a different form.
basically, write a function from scratch, given their prototypes and description.  
string utils: substr; strjoin; strtrim; split;  
char to str utils: itoa;  
pointer to function utils: strmapi; striteri;  
write to fd utils: ft_putchar_fd; ft_putstr_fd; ft_putendl_fd; ft_putnbr_fd;  
  
### part 3: linked lists  
learning how to declare and manipulate lists safely, as well as developing a set of util functions
to handle lists, given the prototype.

## Tester  
I've developed a tester for my libft as I wrote the functions, counter-testing their result with the expected one, in the case of part 1, with glibc and bsd functions, or simply test cases.
you can find it on [libft_tester](https://github.com/madudoodaloo/libft_tester), for usage info, refer to its readme.md  

## Instructions:  
to create libft.a  
```bash
git clone git@github.com:madudoodaloo/libft.git masilva-libft && cd masilva-libft && make setup  
```
to use libft functions on your code, you just need to make sure that on the files that call functions from libft, that you have **#include "path_to/libft.h"** on your file. of course, you'll need to compile your code with the libft.a archive, as the example:  
```bash
cc -Wall -Werror -Wextra libft.a [*.c]
```

## Resources:  
• make gnu  
• man, man man, man 3 man  
• geeksforgeeks  
• stackoverflow  
• man again  
  
• Makefile resources ([automatic variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html) | [make for archives](https://www.gnu.org/software/make/manual/html_node/Archives.html))  
• [memcpy() vs memmove()](https://stackoverflow.com/questions/4415910/memcpy-vs-memmove)  
• [constants in c](https://www.geeksforgeeks.org/c/constants-in-c/)  
• [readme formatting](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)  

GNU C Library (glibc)  
• [libc](https://www.gnu.org/software/libc/)  
• [iso c](https://developer.arm.com/documentation/dui0282/b/the-c-and-c---libraries/iso-implementation-definition/iso-c-library-implementation-definition)  
_System Standard BSD (BSD libc) needs compiling with the -lbsd flag_

---------------------
#### extra:
to test the project, i developed a set of tests as i was going [read tester], which were crucial for eficient mass testing of this huge libft. after that, on school, i asked around about the code, and tested and used trippouille's tester, as well as francinette - really helpful, and improved my tester with missing edge cases.

#### ai usage:  
not in the project, but on the tester, used ai to get cleaner prints for my testers and in some functions to write a simple tester with prompted test cases by me.  

nonetheless, _**i am able to test every single ft autonomously**_, and some of them were fully coded by me - it was just a more productive way to push further on the project and even to learn how to do a proper formated printf. also learned how to create a struct of tests and to have it running on cmdline input, and all using ft pointers, really cool.
oh, and also for the makefile .c SRCF list, wildcards should be allowed, but i get it.