SRCS	=	$(wildcard $(SRCDIR)/*.c)	
SRCDIR	=	./src
OBJS	=	${SRCS:.c=.o}
NAME	=	bsq	
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -g

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} -o ${NAME} ${OBJS}
	${RM} *.o

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean	all

.PHONY: all clean fclean re
