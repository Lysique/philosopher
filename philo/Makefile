NAME = philo
FILES = main philo_init ft_philosopher ft_write routine ft_free
OBJS = $(SRCS:.c=.o)
DIR = ./
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = $(addprefix $(DIR), $(addsuffix .c, $(FILES)))

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
