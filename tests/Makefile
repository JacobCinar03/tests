NAME = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRCS	= ft_isdigit.c  ft_strchr.c   ft_strnstr.c \
ft_atoi.c     ft_isprint.c  ft_strdup.c   ft_strrchr.c \
ft_bzero.c    ft_memchr.c   ft_strjoin.c  ft_substr.c \
ft_calloc.c   ft_memcmp.c   ft_strlcat.c  ft_tolower.c \
ft_isalnum.c  ft_memcpy.c   ft_strlcpy.c  ft_toupper.c \
ft_isalpha.c  ft_memmove.c  ft_strlen.c  ft_isascii.c \
ft_memset.c   ft_strncmp.c  


OBJS	= ft_isdigit.o ft_strchr.o ft_strnstr.o \
ft_atoi.o ft_isprint.o ft_strdup.o ft_strrchr.o \
ft_bzero.o ft_memchr.o ft_strjoin.o ft_substr.o \
ft_calloc.o ft_memcmp.o ft_strlcat.o ft_tolower.o \
ft_isalnum.o ft_memcpy.o ft_strlcpy.o ft_toupper.o \
ft_isalpha.o ft_memmove.o ft_strlen.o ft_isascii.o \
ft_memset.o ft_strncmp.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re