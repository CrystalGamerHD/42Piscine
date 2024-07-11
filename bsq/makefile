NAME = bsq

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
TEST = src/250.0%

UTILSDIR = utils

INCDIR = $(UTILSDIR)

SRCS = main.c \
		$(UTILSDIR)/read_map.c \
		$(UTILSDIR)/memory.c \
		$(UTILSDIR)/utils.c \
		$(UTILSDIR)/utils2.c \
		$(UTILSDIR)/utils3.c \
		$(UTILSDIR)/print_map.c \
		$(UTILSDIR)/algo_dp.c \
		$(UTILSDIR)/process_map.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(foreach DIR,$(INCDIR),-I$(DIR))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: $(NAME)
	lldb $(NAME) $(TEST)

.PHONY: all clean fclean re debug