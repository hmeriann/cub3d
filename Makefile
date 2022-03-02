NAME	= cub3d

HEADER	= ./includes/cub3d.h

CFLAGS	= -g -Wall -Wextra -Werror -I.
INCLUDES = -I includes/libft/libft.a 
# INCLUDES = -I includes/libft/libft.a -I/usr/local/opt/readline/include
# INCLUDES = -I./includes -I./libs/libft/ -I /usr/local/include/readline

LIBFT		= ./includes/libft/libft.a
# RDLINE		= -lreadline -L ~/.brew/opt/readline/lib
# RDLINE		= -lreadline -L /usr/local/opt/readline/lib

CC		= cc

RM		= rm -f

SRCS	= ./src/main.c \
		# ./src/logic/logic.c \
		
OBJS	= ${SRCS:.c=.o}

$(NAME):	$(OBJS) $(HEADER)
			@$(MAKE) -C ./includes/libft
			@$(CC) $(OBJS) $(CFLAGS) includes/libft/libft.a -o $(NAME) $(INCLUDES)


.c.o:	Makefile ./includes/cub3d.h
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

clean:
		@$(RM) $(OBJS)
		@$(MAKE) fclean -C ./includes/libft
		# @echo "$(NAME): $(YEL)Object files deleted$(DEF)"

fclean:	clean
		@$(RM) $(NAME)
		# @echo "$(NAME): $(YEL)Executable file deleted$(DEF)"

re:		fclean all

.PHONY:	all clean fclean re
