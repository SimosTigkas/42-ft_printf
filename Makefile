NAME = libftprintf.a

FUNC = \
	ft_printf.c \
	print_format.c \
	print_digit.c

LIBFTA = libfta

INC = includes

OBJ = $(FUNC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc $(CFLAGS) -I$(INC) -c $< -o $@ 

$(NAME): $(OBJ)
	@make -C $(LIBFTA)
	@cp libfta/libft.a .
	@mv libft.a $(NAME)
	ar crs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(LIBFTA)/libft.a

re:	fclean all

.PHONY: all clean fclean re