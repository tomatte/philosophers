SRC			=	ft_bzero.c ft_isalnum.c ft_isalpha.c \
				ft_isdigit.c ft_isprint.c ft_memcpy.c \
				ft_memset.c ft_strlen.c ft_isascii.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_memchr.c ft_memcmp.c \
				ft_strncmp.c ft_strnstr.c ft_atoi.c \
				ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_lowest.c ft_highest.c \


BONUS_SRC	=	ft_lstnew.c ft_lstadd_front.c \
				ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c \


MORE_SRC	=	ft_putchar.c ft_putstr.c \
				ft_putnbr.c ft_put_uint.c \
				ft_itohex.c ft_strtoupper.c \
				ft_uitoa.c ft_abs.c \
				ft_isnumber.c ft_isspace.c \
				ft_issign.c \
				ft_str_push_char.c \
				ft_pow.c \
				ft_streq.c \

GNL_SRC		=	get_next_line_bonus.c \
				get_next_line_utils_bonus.c \


ALL_SRC		=	$(SRC) $(MORE_SRC) $(GNL_SRC) $(BONUS_SRC)

HEADERS		=	./includes/libft.h

INCLUDES	=	-I./includes

VPATH		=	./src \
				./get_next_line \

OBJS_DIR	=	./objects

OBJS		=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(ALL_SRC))

NAME		=	libft.a

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -rf

all: ${NAME}
	make -C ./ft_printf bonus

$(OBJS_DIR)/%.o:	%.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(OBJS_DIR):
	mkdir -p $@

$(NAME):	$(OBJS_DIR) $(OBJS) $(HEADERS)
	ar -rcs $@ $(OBJS)

clean:
		$(RM) $(OBJS_DIR)
		make -C ./ft_printf clean

fclean:	clean
		$(RM) $(NAME)
		make -C ./ft_printf fclean

re:		fclean all

.PHONY:	all clean fclean re bonus
