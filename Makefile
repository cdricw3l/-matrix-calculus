CC=gcc
CFLAGS= -Werror -Wall -Wextra
NAME=	matrice_calculus
SRCS=	utils/ft_split.c \
		utils/ft_strlen.c \
		utils/ft_substr.c \
		utils/ft_strdup.c \
		tokeniser/tokenizer.c \
		matrice.c

SRCS_OBJS = $(SRCS:*.c=*.o)

%.o:%.c
	$(CC) -c  $(CFLAGS) $^ -o $@

$(NAME): $(SRCS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	rm -f $(NAME)