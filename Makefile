# Directories
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files for the main project
SRCS = ft_printf.c  # Ensure to include the .c extension
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# Output library name
NAME = libftprintf.a

# Default target to build everything
all: $(LIBFT) $(NAME)

# Build the libft library
$(LIBFT):
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)

# Build the main project library (libftprintf.a)
$(NAME): $(OBJS)
	@echo "Linking libftprintf.a with libft..."
	ar rcs $(NAME) $(OBJS)
	@echo "Combining libft.a and libftprintf.a into one static library..."
	ar rcs $(NAME) $(LIBFT_DIR)/*.o

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files in the project and libft
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Remove all built files
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
