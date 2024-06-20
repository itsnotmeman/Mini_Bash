NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

SRC		= ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putunbr_fd.c \
		  ft_print_hex_fd.c \
		  ft_nbrlen.c \
		  ft_hexlen.c \
		  ft_putnstr_fd.c \
		  get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c \
		  ft_printf/ft_printf.c \
		  ft_printf/ft_check_format.c \
		  ft_printf/ft_count_len.c \
		  ft_printf/ft_format_d_i.c \
		  ft_printf/ft_format_hex.c \
		  ft_printf/ft_format_uscpp.c \
		  ft_printf/ft_padding.c \
		  ft_free_2d_array.c \
		  ft_new_2d_array.c \
		  ft_strcmp.c \
		  ft_isspace.c \
		  ft_abs.c

OBJ		= $(SRC:.c=.o)

%.o : %.c	libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			ar rc $@ $^

all: 		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
