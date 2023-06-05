SRC			=	main.c \
				validation.c \
				fill_data.c \
				routine.c \
				finalize.c \
				aux.c \
				aux2.c \
				aux3.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstsize.c \
				utils.c \
				philo_eat.c \
				exec_routine.c \


INCLUDES	=	-I./includes

HEADERS		=	./includes/philo_bonus.h

VPATH		=	./src \
				./src/aux \
				./src/lst \

OBJS_DIR	=	./objects

OBJS		=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(SRC))

CFLAGS		=	-Wall -Wextra -Werror -pthread -g3

NAME		=	philo_bonus

CC			=	cc

RM			=	rm -rf

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(OBJS_DIR):
	mkdir -p $@

$(NAME):	$(OBJS_DIR) $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	fclean clean re
