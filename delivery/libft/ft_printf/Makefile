NAME = libftprintf.a
SRCF = ft_printf.c ft_utils_char.c ft_utils_int.c
OBJF = $(SRCF:.c=.o)

all: $(NAME)

$(NAME): $(OBJF)
	ar -cr $@ $^

clean:
	rm -rf $(OBJF)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: re
	cc -Wall -Werror -Wextra main.c libftprintf.a -o test
	./test

setup: 
	@make
	@echo
	@make clean
	@clear
	@echo "make successfull: libftprintf.a created 🫧"
	@echo "In order to use libftprintf.a, compile your code with libftprintf.a"
	@echo "Don't forget your .c files must have #include \"[path_to_libftprintf.h]\"."