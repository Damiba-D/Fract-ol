# =========================
#     Master Makefile
# =========================

# Project Name
NAME        = fractol

# Sources and Objects
SRC_DIR     = .
SRCS        = fractol.c fractal_init.c math_utils.c render.c events.c parsing.c
OBJ         = $(SRCS:.c=.o)

# Compiler Settings
CC          = cc
CFLAGS      = -g -Wall -Wextra -Werror -Ilibft -Iminilibx -I/usr/include -I/usr/include/X11

# Libft Configuration
LIBFT_DIR   = ./libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# MiniLibX Configuration
MLX_DIR     = ./minilibx
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_FLAGS)

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
