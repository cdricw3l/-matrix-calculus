#https://www.gnu.org/software/make/manual/html_node/Options-Summary.html
CC = cc
GFLAGS = -Wall -Wextra -Werror -g
PARENT_DIR = $(shell dirname $(shell pwd))
NAME = libft_dirty_report
SRCS = ${wildcard *.c}
LIB = -L../. -lft
OBJETS_SRCS = ${SRCS:.c=.o}

%.o:%.c
	@${CC} ${GFLAGS} -c $^ -o $@

#whithout argument make call the first target
${NAME}: lib ${OBJETS_SRCS}  
ifeq (${shell uname} , Darwin)
	${CC} ${GFLAGS} ${OBJETS_SRCS} ${LIB} -lbsd  -o ${NAME}
	${shell export MallocStackLogging=1}
	@leaks -list  --atExit -- ./${NAME}
else
	${CC} ${GFLAGS} ${OBJETS_SRCS} ${LIB} -lbsd  -o ${NAME}
	@valgrind --child-silent-after-fork=yes --leak-check=full --show-leak-kinds=all -s ./${NAME}
endif
	rm -f *.o
lib:
	@make re -C ${PARENT_DIR}

clean:
	@rm -f ${OBJETS_SRCS}
	@make clean -C ${PARENT_DIR}

fclean: clean
	@rm -f ${NAME}
	@make fclean -C ${PARENT_DIR}

.PHONY: ${NAME} lib clean fclean