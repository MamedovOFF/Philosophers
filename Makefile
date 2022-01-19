NAME			= philo

SRCS			= main.c

SRCS_B			= bonus.c

HEADER			= philo.h

LIBFT			= libft/libft.a

OBJ				= $(SRCS:.c=.o)

OBJ_B			= $(SRCS_B:.c=.o)

CC				= gcc

RM				= @rm -f

FLAGS			= -Wall -Wextra -Werror

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJ) $(HEADER)
				@$(MAKE) -C ./libft
				$(CC) $(FLAGS) $(OBJ) -I${HEADER} ${LIBFT} -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC) -I${HEADER} -c $< -o $@

bonus:
				make OBJ="$(OBJ_B)" all

clean:
				$(RM) $(OBJ) $(OBJ_B)

fclean:			clean
				@$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)