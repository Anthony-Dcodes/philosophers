NAME = philo_bonus
CC = cc
CC_FLAGS = -Wall -Wextra -Werror -pthread

SRCS = \
	child_execution.c \
	child_init.c \
	child_monitoring.c \
	child_termination.c \
	cleanup_mallocs.c \
	cleanup_process.c \
	cleanup_sem.c \
	error_messages.c \
	helpers_get.c \
	helpers_set.c \
	init.c \
	init_flag.c \
	init_sem.c \
	logger.c \
	main.c \
	parser_validate.c \
	parser.c \
	philosopher_actions.c \
	philosopher_loop.c \
	philosopher_loop_init.c \
	philosopher_monitoring.c \
	time.c

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

