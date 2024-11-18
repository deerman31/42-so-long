NAME			:= so_long
CC 				:= cc
CFLAGS			:= -Wall -Wextra -Werror
INC				:= -I ./includes
PRINTF_DIR		:= ./ft_printf
PRINTF			:= libftprintf.a
MINILIBX_DIR	:= ./minilibx-linux
MINILIBX		:= libmlx.a
MLX_FLAG		:= -L/usr/X11R6/lib -lX11 -lX11 -lXext -framework OpenGL -framework AppKit

SRCS			:= ./src/so_long.c \
./src/map/map_generate.c ./src/map/map_info_set.c ./src/map/free_map.c \
./src/error/ber_check.c ./src/error/error_message.c ./src/error/map_error_check.c ./src/error/playable_check.c ./src/error/map_size_check.c \
./src/game/play_display.c ./src/game/move_all.c \
./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

OBJS			:= $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all : $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) re
	$(MAKE) -C $(MINILIBX_DIR) all
	$(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) $(PRINTF_DIR)/$(PRINTF) $(MINILIBX_DIR)/$(MINILIBX) -o $(NAME)

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all leak clean fclean re
