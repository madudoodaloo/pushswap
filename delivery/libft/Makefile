NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
INCLUDES = libft.h ft_printf/ft_printf.h
LIBFT_SRCF = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

PRINTF_DIR = ft_printf/
PRINTF_SRCF = $(PRINTF_DIR)ft_printf.c \
				$(PRINTF_DIR)ft_printf_utils_int.c \
				$(PRINTF_DIR)ft_printf_utils_char.c

ALL_SRCF = $(LIBFT_SRCF) $(PRINTF_SRCF)
OBJF = $(ALL_SRCF:.c=.o)

%.o : %.c $(INCLUDES)
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJF)
	ar -cr $@ $^

clean:
	$(RM) $(OBJF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

setup: 
	@make
	@echo
	@make clean
	@clear
	@echo "make successfull: libft.a created 🫧"
	@echo "In order to use libft.a, compile your code with libft.a"
	@echo "Don't forget your .c files must have #include \"[path_to_libft.h]\"."