NAME = push_swap

LIBFT = libft/libft.a

SRCS = main.c\
		parsing.c\
		stacks.c\
		commands.c\
		quicksort.c\
		rotate.c\
		sort.c\
		utils.c\
		init.c\
		direction.c\
		smallsort.c

CC = clang

OBJS = ${SRCS:.c=.o}

CFLAGS = -g

all : $(NAME)

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

$(NAME): ${OBJS}
		make -C libft
		${CC} -o ${NAME} ${OBJS} ${LIBFT}

clean :
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re:		fclean all

.PHONY: all clean fclean re
