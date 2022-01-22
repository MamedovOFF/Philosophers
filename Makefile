NAME			= philo

SRCS			= src/main.c src/monitoring.c src/time.c src/philo.c src/validator.c src/untils.c

SRCS_B			= bonus.c

HEADER			= ./includes/

OBJ				= $(SRCS:.c=.o)

OBJ_B			= $(SRCS_B:.c=.o)

CC				= gcc

RM				= @rm -f

FLAGS			= -Wall -Wextra -Werror

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJ) $(HEADER)
				$(CC) $(FLAGS) $(OBJ)  -pthread -o $(NAME)

%.o:			%.c $(HEADER)
				$(CC) -g $(FLAGS) -I${HEADER} -c $< -o $@

bonus:
				make OBJ="$(OBJ_B)" all

clean:
				$(RM) $(OBJ) $(OBJ_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)