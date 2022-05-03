NAME		=	cub3d

SRCS_FILES	= 	main.c \
				utils/ft_common_checks.c \
				parser/ft_parser.c \
				parser/ft_checks.c \
				parser/ft_print_error.c \
				parser/ft_gets.c \
				parser/ft_map.c \
				logic/window.c \
				logic/game.c \
				logic/hooks.c \
				logic/rays.c \
				logic/rays_checks.c \
				logic/get_img.c \
				logic/get_img_helpers.c \
				logic/mooving.c \
				logic/save.c \
				utils/utils.c \
				utils/utils_0.c \
				utils/utils_1.c \
				utils/utils_2.c \
				utils/utils_3.c \
				utils/utils_4.c \
				utils/utils_5.c \

OBJS	= ${SRCS:.c=.o}

SRCS_FOLDER	=	src/

HEADER		=	../../include/cub3d.h

SRCS		= 	$(addprefix $(SRCS_FOLDER),$(SRCS_FILES))
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

INCLUDE		=	-I./../../include/cub3d.h -I./src/libft/ -I./src/mlx/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD
FRAMEWORK	=	-framework OpenGL -framework AppKit
RM			=	rm -f

LIBC		=	ar rcs

MLX = ./src/mlx/libmlx.a
LIB = ./src/libft/libft.a

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C $(dir $(MLX)) 2> /dev/null
			@$(MAKE) -C $(dir $(LIB))
			@$(CC) $(INCLUDE) $(FRAMEWORK) $(MLX) $(LIB) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(OBJS:.o=.d)
			@make -C $(dir $(MLX)) clean
			@make -C $(dir $(LIB)) clean

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			@$(RM) $(MLX)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
-include	$(OBJS:.o=.d)
