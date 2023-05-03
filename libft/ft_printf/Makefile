SRC			=		fill.c  ft_convert.c  \
					ft_printf.c printf_utils.c  \
					print_hex.c  print_int.c  \
					print_pointer.c  print_uint.c \
					fill_zeros.c

H_SRC	=	./src/ft_printf.h

VPATH	=	./src

OBJS_DIR	=	objects

OBJS	=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(SRC))

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf


all: 		${NAME}
	mv ./$(NAME) ../$(NAME)

$(OBJS_DIR)/%.o:	%.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(OBJS_DIR):
	mkdir -p $@

$(NAME):	$(OBJS_DIR) $(OBJS) $(H_SRC)
			mv ../libft.a ./$(NAME)
			ar -rcs $@ $(OBJS) $(H_SRC)

bonus:		${NAME}
	mv ./$(NAME) ../$(NAME)

clean:
			${RM} ${OBJS_DIR}

fclean:		clean
			${RM} ../${NAME}

re:			fclean all

.PHONY:		all clean fclean re
