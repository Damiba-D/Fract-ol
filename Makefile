# =========================
#     Master Makefile
# =========================

# Project Name
NAME        = fractol

# Sources and Objects
SRC_DIR     = .
SRC         = fractol.c
OBJ         = $(SRC:.c=.o)

# Compiler Settings
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Ilibft -Iminilibx-linux -I/usr/include -I/usr/include/X11

# Libft Configuration
LIBFT_DIR   = ./libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

# MiniLibX Configuration
MLX_DIR     = ./minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# =========================
#       Build Targets
# =========================

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "🔧 Building minilibx..."
	@$(MAKE) -C $(MLX_DIR)
	@echo "🏗  Linking executable..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	@echo "🧹 Removing executable..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
