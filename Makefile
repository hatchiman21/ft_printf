LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS_DIR = obj
SRCS_DIR = src

SRCS = ft_printf.c ft_printf_special.c ft_printf_utils.c
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) inc/ft_printf.h
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS) 

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
