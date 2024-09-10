SRCS			=	ft_strlcpy.c
OBJS			= $(SRCS:.c=.o)


CC				= @cc
RM				= @rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

$(OBJS) $(BONUS_OBJS): %.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
