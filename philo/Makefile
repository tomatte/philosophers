SRC			=	main.c \
				validation.c \
				clst_new.c \
				clst_last.c \
				clst_add_back.c \
				clst_clear.c \
				fill_data.c \
				create_philos.c \
				utils.c \
				create_forks.c \
				clst_iter.c \
				execute_threads.c \
				routine.c \
				eat.c \
				start_guardian.c \
				aux.c \
				aux2.c \
				ft_itoa.c \
				ft_isnumber.c \


INCLUDES	=	-I./includes

HEADERS		=	./includes/philosophers.h

VPATH		=	./src \
				./src/list \
				./src/aux \

OBJS_DIR	=	./objects

OBJS		=	$(patsubst %.c,$(OBJS_DIR)/%.o, $(SRC))

CFLAGS		=	-Wall -Wextra -Werror -pthread -g3

NAME		=	philosophers

CC			=	cc

RM			=	rm -rf

all:	$(NAME)

$(OBJS_DIR)/%.o:	%.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(OBJS_DIR):
	mkdir -p $@

$(NAME):	$(OBJS_DIR) $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -lreadline -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	fclean clean re
