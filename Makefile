CFLAGS = -Wall -Werror -Wextra

NAME = fractol

CC = gcc

SRC = main.c algebra.c image_proc.c

OBJS = $(SRC:.c=.o)
INCL = fractol.h
MLX		= ./mlx_linux/
MLX_LNK	= -L $(MLX) -lmlx_Linux  -L/usr/lib -I $(MLX) -lXext -lX11 -lm -lz -o $(NAME)

MLX_LIB	= $(addprefix $(MLX),mlx.a)

all : $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJS) $(INCL)
	$(CC) $(OBJS) $(INCL) $(MLX_LNK) -lm -o $(NAME)

clean :
	@rm -rf $(OBJS)
	make -C $(MLX) clean

fclean : clean
	@rm -rf $(NAME)

re : fclean all