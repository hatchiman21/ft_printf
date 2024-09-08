LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c ft_itoa_hex.c ft_put.c print_special.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ar rcs $(NAME) $(LIBFT_DIR)/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
