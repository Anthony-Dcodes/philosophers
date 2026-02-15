NAME = philo
CC = cc
CC_FLAGS = -Wall -Wextra -Werror -pthread

SRCS = \
	philo.c \
	error.c \
	parser.c \
	logs.c \
	mutex_init.c \
	philo_state.c \
	clean_up.c \
	utils.c

OBJS = $(SRCS:.c=.o)

# --- Rebuild if headers change ---
%.o: %.c philo.h
	$(CC) $(CC_FLAGS) -c $< -o $@

# --- Build rules ---

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

