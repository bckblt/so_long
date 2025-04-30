NAME = so_long

SRCS = so_long.c ctl_utils.c map_ctl.c map_cfg.c utils.c ./ft_printf/ft_printf.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c game_start.c game_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBRARY = -Lminilibx-linux -lmlx -lXext -lX11 -lm

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@make clean -C minilibx-linux

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
