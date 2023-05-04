SRC			=	main.c \
				validation.c \
				clst_new.c \


INCLUDES	=	-I./includes

HEADERS		=	./includes/philosophers.h

VPATH		=	./src \
				./src/list \

OBJS_DIR	=	./objects

OBJS		=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(SRC))

CFLAGS		=	-Werror -Wall -Wextra -pthread

LIBFT_DIR	=	./libft

LIBFT		=	$(LIBFT_DIR)/libftprintf.a

NAME		=	philosophers

CC			=	cc

RM			=	rm -rf

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(OBJS_DIR):
	mkdir -p $@

$(NAME):	$(OBJS_DIR) $(OBJS) $(LIBFT) $(HEADERS)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(INCLUDES) -lreadline -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	$(RM) $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean:	clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:	fclean clean re
