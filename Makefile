NAME = push_swap
CCFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
INCLUDES = push_swap.h

SRCF = $(wildcard *.c)
OBJF = ${SRCF:.c=.o}

%.o: %.c
	cc $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJF)
	cc $(CCFLAGS) $(INCLUDES) $(OBJF) -o $(NAME)

clean: 
	rm -rf $(OBJF)

fclean: clean
	rm -rf $(NAME)