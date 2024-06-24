NAME	=	get_next_line.a
SRCS	=	get_next_line.c get_next_line_utils.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS)
	ar rc $(NAME) $^
	ranlib $(NAME)

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)

re: fclean bonus
