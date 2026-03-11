NAME = philo_bonus
CC = cc
CC_FLAGS = -Wall -Wextra -Werror -pthread

SRCS = \
	main.c \
	error_messages.c \
	parser.c \
	logger.c \
	philosopher_actions.c \
	cleanup.c \
	utils.c \
	init.c \
	monitoring.c \
	philosopher_loop.c \
	sem_init.c \
	get_helpers.c \
	set_helpers.c

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

