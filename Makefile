DIRSRC		= ./srcs/

SRC			= write.c mutexes.c parsing.c philo.c threads.c utils.c dead.c

SRCS		= $(addprefix ${DIRSRC}, ${SRC})

OBJS		= ${SRCS:.c=.o}

NAME		= philo

CC			= gcc
RM			= rm -f
RN			= ranlib
LP			= -lpthread

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LP}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re