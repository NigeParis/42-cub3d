###############################################################################
## ARGUMENTS

NAME= cub
CFLAGS=  -Wall -Wextra -Werror -g3
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 

SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:.c=.o)
OBJS=$(addprefix $(OBJ_DIR), $(OBJ))

CC=cc
###############################################################################
## SOURCES 

SRC_DIR=src/
OBJ_DIR=build/
FOLDER=game_setup/

SRC= main.c  get_next_line.c \
	 get_next_line_utils.c game_setup/init_data.c
	 
LIBFT= ./libft/libft.a
FT_PRINTF=./ft_printf/libftprintf.a

INCLUDE= -I ./include/ -Imlx
###############################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating FILE .......\n"
	@make -C ./mlx/ all
	@make -C ./libft/ all
	@make -C ./ft_printf/ all
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT) $(FT_PRINTF)  $(MLX_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(FOLDER)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

lib:
	@make -C ./ft_printf/ re
	@make -C ./libft/ re
	@make -C ./mlx/ re

libclean:
	@make -C ./ft_printf/ clean
	@make -C ./libft/ clean

libfclean:
	@make -C ./ft_printf/ fclean
	@make -C ./libft/ fclean
	@make -C ./mlx/ clean

clean: libclean
	@rm -rf $(OBJ_DIR)

fclean:clean libfclean	
	@echo "FCLEAN all .o et .a files .......\n"
	@rm -f $(NAME)

re: fclean libfclean lib all
	@echo "All erased and re-compiled .......\n"

.PHONY: all lib libclean clean fclean re