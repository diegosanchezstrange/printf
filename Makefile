NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -c

CFLAGSR	= -Wall -Werror -Wextra -g3 -fsanitize=address

SRCS	= ft_printf.c \
			ft_printf_string.c \
			ft_printf_num.c \
			ft_printf_hex.c 

OBJS	= ${SRCS:.c=.o}

RM		= rm -f

all: ${NAME}

%o: %c
	@${CC} ${CFLAGS} $< -o ${<:.c=.o}

$(NAME) : ${OBJS} 
	@make bonus -C libft/
	@cp libft/libft.a ./${NAME}
	@ar rc ${NAME} ${OBJS}

run: 
	@cd libft && make bonus
	${CC} ${CFLAGSR} ${SRCS} main.c -lft -Llibft -o printf && ./printf

clean:
		@${RM} ${OBJS} ${OBJS_B}

fclean:		clean
		@${RM} ${NAME}

bonus: all

re:		fclean all

.PHONY:	clean re fclean bonus all
