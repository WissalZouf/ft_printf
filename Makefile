SRCS =	ft_printf.c \
		extra_function.c \
		


NAME = libftprintf.a

OBJECT = $(SRCS:.c=.o)


HEADER =	./ft_printf.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJECT) $(HEADER)
			ar -rcs $(NAME) $(OBJECT)
%.o : %.c
			gcc $(FLAGS) -c $<

clean :
			rm -rf $(OBJECT)

fclean : clean
			rm -rf $(NAME)
norm:
	norminette $(SRCS) $(HEADER)
re : fclean all

