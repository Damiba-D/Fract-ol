# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 17:35:12 by ddamiba           #+#    #+#              #
#    Updated: 2025/06/20 18:20:34 by ddamiba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library Name
NAME = libft.a

# Compiler & Tools
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Submodules
GNL_DIR = get_next_line
PRINTF_DIR = ft_printf

# Source Files
SRC = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_base.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
	

OBJ = $(SRC:.c=.o)
HEADER = libft.h

# Default rule
all: submodules $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)

# Build GNL and printf submodules
submodules:
	@$(MAKE) -C $(GNL_DIR)
	@$(MAKE) -C $(PRINTF_DIR)

# Cleaning rules
clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re submodules

# Library Name
NAME = libft.a

# Compiler & Tools
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Submodules
GNL_DIR = get_next_line
PRINTF_DIR = ft_printf

# Source Files
SRC = ${wildcard *.c}
	
OBJ = $(SRC:.c=.o)
HEADER = libft.h

# Default rule
all: submodules $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)

# Build GNL and printf submodules
submodules:
	@$(MAKE) -C $(GNL_DIR)
	@$(MAKE) -C $(PRINTF_DIR)

# Cleaning rules
clean:
	$(RM) $(OBJ)
	@$(MAKE) -C $(GNL_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(GNL_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re submodules

