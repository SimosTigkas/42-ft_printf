NAME = libftprintf.a

FUNC = \
	ft_printf.c

INC =.

OBJ = $(FUNC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc $(CFLAGS) -I$(INC) -c $< -o $@ 

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all