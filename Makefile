###############################################################################
## ARGUMENTS

NAME= cub3D
CFLAGS=  -Wall -Wextra -Werror -Unused -g3
MLX_FLAGS = -lm -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
	INCLUDE= -I./include/
else
	INCLUDES = -I/opt/X11/include -Imlx
	INCLUDE= -I./include
endif

SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:.c=.o)
OBJS=$(addprefix $(OBJ_DIR), $(OBJ))
CC=cc
###############################################################################
## SOURCES 

SRC_DIR = src/
OBJ_DIR = build/
MINI_MAP = game_mini_map/
PARSING = game_map_parsing/
SETUP = game_setup/
MAP = game_map_setup/
ERROR=game_errors/
MAP_PARSER= map_parser/
PLAYER_SETUP = player_setup/
CLEANUP = game_cleanup/
DEBUG = game_debug/
MLX_OPEN_WINDOW_R = game_window/
DRAW = pixel_tools/
DRAW_MAP = draw_map/
PARSE_TOOLS = game_parsing_tools/
TOOLS = game_tools/

SRC= main.c  \
	game_map_parsing/game_parsing_tools/get_next_line.c game_map_parsing/game_parsing_tools/get_next_line_utils.c \
	game_errors/display_error.c \
	game_cleanup/free_exit.c \
	game_map_parsing/game_setup/init_data.c game_map_parsing/game_setup/check_map_has_valid_extension.c \
	game_map_parsing/game_setup/get_line.c game_map_parsing/game_setup/build_map_values_from_raw.c \
	game_map_parsing/game_setup/create_directional_textures.c game_map_parsing/game_setup/build_map_textures.c \
	game_map_parsing/game_setup/build_final_map_data.c game_map_parsing/game_setup/create_floor_ceiling_textures.c \
	game_map_parsing/game_setup/floor_ceil_rgb.c game_map_parsing/game_setup/open_close_file_setup.c \
	game_map_parsing/game_setup/trim_textures_data.c game_mini_map/game_map_setup/map_setup.c \
	game_mini_map/game_map_setup/floodfill_map_check.c game_mini_map/game_map_setup/map_rezise_tool.c \
	game_mini_map/game_map_setup/map_tools.c \
	player_setup/player_starting_pos.c player_setup/get_player_starting_angle.c \
	game_map_parsing/map_parser/parse_map.c game_map_parsing/map_parser/treat_first_last_line_properly_configured.c \
	game_map_parsing/map_parser/check_map_char_validity.c game_map_parsing/map_parser/check_map_lines.c \
	game_map_parsing/map_parser/check_zero_char_properly_closed.c game_map_parsing/map_parser/check_map_spaces_closed_off_by_walls.c \
	game_map_parsing/map_parser/horizontal_map_check.c \
	game_mini_map/pixel_tools/draw_line.c game_mini_map/pixel_tools/draw_circle.c game_mini_map/pixel_tools/check_pixel.c\
	game_debug/print_debug_map.c game_debug/print_debug.c \
	game_window/open_window.c game_mini_map/draw_map/draw_2d_map.c game_mini_map/draw_map/draw_map_setup.c \
	game_mini_map/draw_map/draw_lines_setup.c  game_mini_map/pixel_tools/wall_detection_pixel.c \
	game_mini_map/draw_map/cast_several_rays.c game_mini_map/pixel_tools/draw_line_two_points.c \
	player_setup/move_player.c player_setup/rotate_player.c \
	game_tools/general_game_tools.c
	
LIBFT= ./libft/libft.a
FT_PRINTF=./ft_printf/libftprintf.a

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

ifeq ($(shell uname), Linux)
	MLX_FLAGS = -lm -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -lm -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

###############################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating FILE .......\n"
	@make -C ./mlx/ all > /dev/null
	@make -C ./libft/ all > /dev/null
	@make -C ./ft_printf/ all > /dev/null
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(MINI_MAP)
	@mkdir -p $(OBJ_DIR)/$(TOOLS)
	@mkdir -p $(OBJ_DIR)/$(PARSING)/$(SETUP)
	@mkdir -p $(OBJ_DIR)/$(PARSING)/$(PARSE_TOOLS)
	@mkdir -p $(OBJ_DIR)/$(MINI_MAP)/$(MAP)
	@mkdir -p $(OBJ_DIR)/$(ERROR)
	@mkdir -p $(OBJ_DIR)/$(PARSING)/$(MAP_PARSER)
	@mkdir -p $(OBJ_DIR)/$(PLAYER_SETUP)
	@mkdir -p $(OBJ_DIR)/$(CLEANUP)
	@mkdir -p $(OBJ_DIR)/$(DEBUG)
	@mkdir -p $(OBJ_DIR)/$(MLX_OPEN_WINDOW_R)
	@mkdir -p $(OBJ_DIR)/$(MINI_MAP)/$(DRAW)
	@mkdir -p $(OBJ_DIR)/$(MINI_MAP)/$(DRAW_MAP)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) $(INCLUDES) 

lib:
	@make -C ./ft_printf/ re > /dev/null
	@make -C ./libft/ re > /dev/null
	@make -C ./mlx/ re > /dev/null

libclean:
	@make -C ./ft_printf/ clean > /dev/null
	@make -C ./libft/ clean > /dev/null

libfclean:
	@make -C ./ft_printf/ fclean > /dev/null
	@make -C ./libft/ fclean > /dev/null
	@make -C ./mlx/ clean > /dev/null

clean: libclean
	@echo "CLEAN all .o files .......\n"
	@rm -rf $(OBJ_DIR)

fclean:clean libfclean	
	@echo "FCLEAN all .o et .a files .......\n"
	@rm -f $(NAME) > /dev/null

re: fclean libfclean lib all
	@echo "All erased and re-compiled .......\n"

.PHONY: all lib libclean clean fclean re