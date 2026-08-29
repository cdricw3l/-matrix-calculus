CC= cc
AR= ar -rcs
GFLAGS =-Wall -Wextra -Werror -g
NAME= libft.a
SRCS=	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_split_clean.c \
		ft_split_clean.c \
		ft_split_len.c \
		ft_split_display.c
		
OBJETS_SRCS = ${SRCS:.c=.o}



%.o:%.c
	${CC} -c  ${GFLAGS} $^ -o $@

all: ${NAME}

${NAME}: ${OBJETS_SRCS}
	${AR} ${NAME} ${OBJETS_SRCS}

clean:
	rm -f ${OBJETS_SRCS}

fclean: clean
	rm -f ${NAME}


re: fclean ${NAME}

COM= libft_add
git: fclean
	git add .
	git commit -m $(COM)
	git push origin $(shell git branch --show-current)

.PHONY: re all clean fclean 
