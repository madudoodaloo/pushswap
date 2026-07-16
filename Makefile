NAME = push_swap
CCFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
INCLUDE = push_swap.h

# libft handler
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# pushswap srcf handler
SRCF = $(wildcard *.c) $(wildcard utils/*.c)  $(wildcard ft_fprintf/*.c)
OBJF = ${SRCF:.c=.o}

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	cc $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJF) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJF) $(LIBFT) -o $(NAME)

clean: 
	rm -rf $(OBJF)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
