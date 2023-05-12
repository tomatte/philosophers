SRC			=	main.c \


INCLUDES	=	-I./includes

HEADERS		=	./includes/philo_bonus.h

VPATH		=	./src \

OBJS_DIR	=	./objects

OBJS		=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(SRC))

CFLAGS		=	-Wall -Wextra -pthread -g3 ##-Werror removeeeeeeeeeeeeeeeeed!!!!!!!!!!!!!

LIBFT_DIR	=	./libft

LIBFT		=	$(LIBFT_DIR)/libftprintf.a

NAME		=	philo_bonus

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
