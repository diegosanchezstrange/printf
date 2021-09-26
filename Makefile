NAME	= printf

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

SRCS	= printf.c \
			printf_conversions.c

RM		= rm -f

all: ${NAME}

$(NAME) : ${SRCS} 
	@cd libft && make bonus
	${CC} ${CFLAGS} ${SRCS} -lft -Llibft -o ${NAME}

clean:
		@${RM} ${OBJS} ${OBJS_B}

fclean:		clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:	clean re fclean bonus all
