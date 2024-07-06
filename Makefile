# Makefile for fdf project

# Variables
NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./srcs
PRINTF_DIR = ./utils/ft_printf
LIBFT_DIR = ./utils/libft
GNL_DIR = ./utils/get_next_line
MLX_DIR = ./minilibx-linux

# Source files
SRCS_FILES = fdf.c draw.c read_file.c exit.c math.c my_mlx_pixel_put.c get_file_data.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

# Object files
OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL =  $(GNL_DIR)/get_next_line.a
MLX = $(MLX_DIR)/libmlx.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(MAKE) -C $(MLX_DIR)
	# MacOS: need to add include mlx.h
	# $(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) -lm -lXext -lX11 -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT) $(GNL) $(MLX)

gdb: $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(MAKE) -C $(MLX_DIR)
	gcc -g $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT) $(GNL) $(MLX) -lXext -lX11 -lm -lbsd -lXrandr

#  --show-leak-kinds=all --track-origins=yes
valgrind: gdb
	valgrind --leak-check=full ./fdf test_maps/42.fdf

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

# Dependencies
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
