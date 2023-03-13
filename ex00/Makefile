NAME = rush-02

SRC = srcs/rush.c srcs/ft_itoa.c  srcs/ft_split.c srcs/ft_create_elem.c \
		srcs/ft_list_add_back.c srcs/ft_list_find.c srcs/ft_list_clear.c srcs/ft_str_cat_dup.c \
		srcs/ft_reader.c srcs/ft_is_numeric.c srcs/ft_split_frier.c srcs/ft_split_to_list.c \
		srcs/ft_atoi.c srcs/ft_list_size.c srcs/ft_dict_checker.c srcs/ft_printing.c

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

%.o: %.c
		@gcc -g ${CFLAGS} -c -o $@ $?

${NAME}: ${OBJ}
		@cc ${CFLAGS} -I includses/ -fsanitize=address -g ${OBJ} -o ${NAME}
		# @cc ${CFLAGS} -I includes/ ${OBJ} -o ${NAME}
		
all: ${NAME}

clean:
		@rm -f ${OBJ}
		
fclean: clean
		@rm -f ${NAME}

re: fclean all

test: re
		./$(NAME)

.PHONY: clean re all fclean
