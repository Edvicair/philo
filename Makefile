
SRC =	main.c \
		parsing.c \
		itoa.c \
		lib.c \
		fill.c \
		thread.c \
		loop.c \
		fork.c \
		action.c \
		write.c \

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,${SRC})
OBJ_DIR	= objs/
INIT_DIR = init/
LIBFT_DIR = libft/
INCLUDES_DIR = includes/

VPATH	= $(INIT_DIR) $(LIBFT_DIR)

FLAGS = -Wall -Wextra -Werror #-fsanitize=thread

THREAD_FLAGS = -lpthread -D_REENTRANT

$(OBJ_DIR)%.o	: %.c
				mkdir -p $(OBJ_DIR)
				cc $(FLAGS) -c $< -I$(INCLUDES_DIR) -o $@

NAME = philo

$(NAME): $(OBJ)
	cc $(FLAGS) -o $(NAME) $(OBJ) $(THREAD_FLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
