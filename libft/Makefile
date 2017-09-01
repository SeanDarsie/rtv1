NAME =	libft.a
CFLAGS = -Wall -Wextra -Werror
FILES =	ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_abs_value.c \
		ft_strrev.c \
		ft_rem_ascii.c \
		ft_lstmap.c \
		ft_lstiter.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstnew.c \
		ft_strlcat.c \
		ft_itoa.c \
		ft_atoi.c \
		ft_strsplit.c \
		ft_strtrim.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_memcmp.c \
		ft_memdel.c \
		ft_memalloc.c \
		ft_memchr.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strrchr.c \
		ft_strchr.c \
		ft_strnstr.c \
		ft_strstr.c \
		ft_strnew.c \
		ft_strjoin.c \
		ft_strmap.c \
		ft_strdel.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strsub.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_striter.c \
		ft_strnequ.c \
		ft_bzero.c \
		ft_strncat.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strncpy.c \
		ft_putnbr.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_putendl.c \
		ft_strclr.c \
		ft_strequ.c \
		ft_isprint.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isupper.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c \
		get_next_line.c \

BIN =	ft_striter.o \
		ft_putnbr_fd.o \
		ft_abs_value.o \
		ft_strrev.o \
		ft_rem_ascii.o \
		ft_lstmap.o \
		ft_lstiter.o \
		ft_lstadd.o \
		ft_lstdel.o \
		ft_lstdelone.o \
		ft_lstnew.o \
		ft_strlcat.o \
		ft_itoa.o \
		ft_atoi.o \
		ft_strsplit.o \
		ft_strtrim.o \
		ft_strmapi.o \
		ft_striteri.o \
		ft_memcmp.o \
		ft_memdel.o \
		ft_memalloc.o \
		ft_memchr.o \
		ft_memccpy.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_strrchr.o \
		ft_strchr.o \
		ft_strnstr.o \
		ft_strstr.o \
		ft_strjoin.o \
		ft_strnew.o \
		ft_strdel.o \
		ft_strmap.o \
		ft_strncmp.o \
		ft_strcmp.o \
		ft_strsub.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putchar_fd.o \
		ft_strnequ.o \
		ft_bzero.o \
		ft_isprint.o \
		ft_strlen.o \
		ft_putchar.o \
	 	ft_putstr.o \
		ft_isalpha.o \
		ft_isdigit.o \
		ft_islower.o \
		ft_isupper.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_strclr.o \
		ft_strequ.o \
		ft_strcpy.o \
		ft_putendl.o \
		ft_strdup.o \
		ft_putnbr.o \
		ft_strcat.o \
		ft_strncpy.o \
		ft_memset.o \
		ft_strncat.o \
		get_next_line.o \


INCLUDES = libft.h

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(FILES) $(INCLUDES)
	ar rc $(NAME) $(BIN)

clean:
	rm -f $(BIN) libft.h.gch

fclean: clean 
	rm -f $(NAME)

re: fclean all
