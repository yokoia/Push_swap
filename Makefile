NAME = push_swap
NAME_B = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c  stack.c  helpers.c  errors.c  operations1.c  operations2.c \
	   special_sort.c  ft_split.c   algo_helpers.c   main_algo.c

SRCS_B = main.c  stack.c  helpers.c  errors.c  operations1.c  operations2.c \
        special_sort.c  ft_split.c   algo_helpers.c   main_algo.c \
        z_gnl_utils.c   z_gnl   checker.c   checker_utils.c


OBJ = $(SRCS:.c=.o)
 
OBJ_B = $(SRCS_B:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(NAME_B): $(OBJ_B)
    $(CC) $(CFLAGS) -o $(NAME_B) $(OBJ_B)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJ) $(OBJ_B)

bonus: $(NAME) $(NAME_B)

fclean: clean
    rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY:    all clean fclean re bonus