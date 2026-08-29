CC=gcc
CFLAGS= -Werror -Wall -Wextra
NAME=	matrice_calculus
SRCS=	tokeniser/tokenizer.c \
		matrice.c

DRAFT = draft/draft.c

SRCS_OBJS = $(SRCS:.c=.o)
DRAFT_OBJS = $(DRAFT:.c=.o)

%.o:%.c
	$(CC) -c  $(CFLAGS) $^ -o $@

$(NAME): $(SRCS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -Llibft -lft -o $(NAME)

test: $(NAME)
	echo $(shell uname)
ifeq ($(shell uname),Darwin)
	echo hello
	leaks -atExit -- ./$(NAME)
endif

run: $(NAME)
	./$(NAME)

lib:
	make -C libft

libc:
	make -C libft clean

draft: $(DRAFT_OBJS)
	$(CC) $(CFLAGS) $(DRAFT_OBJS) -o draft/draft
	./draft/draft

libre:
	make -C libft re

clean:
	rm -f $(SRCS_OBJS) $(DRAFT_OBJS)

fclean: clean libc
	rm -f $(NAME) draft/draft

.PHONY: test