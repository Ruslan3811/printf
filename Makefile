NAME = libftprintf.a
SRC = ft_printf.c\
	for_d_i_u.c\
	for_x_p.c\
	for_str_char.c\
	utils.c\
	processor.c\
	processor2.c\
	processor3.c\
	main_processor.c
OBJ = $(SRC:.c=.o)
all: $(NAME)
%.o: %.c
		gcc -c $< -o $@ -I
$(NAME):$(OBJ)
					ar rc $(NAME) $^
					ranlib $(NAME)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re:		fclean all
.PHONY: clean fclean all re
