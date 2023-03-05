NAME = so_long
CC   = cc -Wall -Wextra -Werror
RM = rm -f
AR = ar -rc
flg_mlx = -lmlx -framework OpenGL -framework AppKit
NAME_B = so_long_bonus

SRC = get_next_line.c get_next_line_utils.c check_evt.c check_map.c utils.c graph.c check_key.c so_long.c

B_SRC = bonus/check_evt.c bonus/get_next_line.c bonus/get_next_line_utils.c \
 		bonus/check_map.c bonus/utils.c bonus/graph.c \
		 bonus/check_key.c bonus/so_long.c bonus/graph_1.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(OBJ) $(flg_mlx) -o $(NAME)

./bonus/%.o : bonus/%.c so_long.h
	$(CC) -Imlx -c $< -o $@

%.o : %.c so_long.h
	$(CC) -Imlx -c $<

bonus: $(B_OBJ)
	$(CC) $(B_OBJ) $(flg_mlx) -o $(NAME_B)

clean:
	$(RM) $(B_OBJ)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME_B)
	$(RM) $(NAME)

re: fclean all