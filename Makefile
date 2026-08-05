NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= #-Wall -Werror -Wextra -g #-fsanitize=address 
INCLUDE 	= push_swap.h checker/checker.h


# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
         

# libft handler
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# pushswap srcf handler
SRCF = $(wildcard *.c) \
		$(wildcard parser/*.c) \
		$(wildcard utils/*.c)  \
		$(wildcard bench/*.c) \
		$(wildcard algs/*.c) \
		$(wildcard operations/*.c) \
		$(wildcard ft_fprintf/*.c) \
		$(wildcard get_next_line/*.c) 

OBJF = ${SRCF:.c=.o}

B_SRCF = $(wildcard checker/*.c)
B_OBJF = ${B_SRCF:.c=.o}


all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJF) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(B_OBJF) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf $(OBJF) $(B_OBJF)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
