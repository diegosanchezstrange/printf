NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -c

SRCS	= ft_printf.c \
			printf_conversions.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

all: ${NAME}

%o: %c
	@${CC} ${CFLAGS} $< -o ${<:.c=.o}

$(NAME) : ${OBJS} 
	@make bonus -C libft/
	@cp libft/libft.a ./${NAME}
	@ar rc ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS} ${OBJS_B}

fclean:		clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:	clean re fclean bonus all
