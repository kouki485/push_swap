CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
INCLUDES = includes

SRCS_FILES = main.c compression.c error_treat.c \
			op_list.c op_push.c op_r_rotate.c \
			op_rotate.c op_swap.c sort_case_other.c\
			utils_one.c utils_two.c sort_case.c
SRCS		= $(addprefix ./, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAG) -o $(NAME)

.c.o :
		$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME) $(SRCS_OBJS)
re : fclean all