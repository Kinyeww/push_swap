NAME = push_swap
CC = cc
CCFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c push_swap_utils1.c push_swap_utils2.c rotate_algo.c create_nodes.c ft_split.c sort_small_num.c sort_small_utils.c

OBJS := $(SRC:.c=.o)
# CPPFLAGS = -I$(INC_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) 
		$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re