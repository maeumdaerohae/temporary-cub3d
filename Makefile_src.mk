# **************************************************************************** #
# NAME & DIRS #
NAME        			:= 	cub3D
SRC_DIR 				:= 	src
BUILD_DIR 				:= 	.build
DEPS_DIR 				:= 	.deps
# **************************************************************************** #
# PATHS #
SOURCES 				:= 	$(SRC_DIR)/exec/game/visual.c				\
							$(SRC_DIR)/exec/mlx/mlx.c				\
							$(SRC_DIR)/exec/mlx/error_mlx.c			\
							$(SRC_DIR)/exec/mlx/my_pixel.c			\
							$(SRC_DIR)/exec/mlx/clear_image.c		\
							$(SRC_DIR)/exec/mlx/handle.c			\
							$(SRC_DIR)/exec/minimap/grid.c			\
							$(SRC_DIR)/exec/minimap/ray.c			\
							$(SRC_DIR)/exec/world/init_map.c		\
							$(SRC_DIR)/exec/world/print_map.c		\
							$(SRC_DIR)/exec/main.c					\

# **************************************************************************** #
# SRCS #
SRCS 					:= 	$(SOURCES)	
OBJS 					:= 	$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS 					:= 	$(patsubst $(SRC_DIR)/%.c,$(DEPS_DIR)/%.d,$(SRCS))
# **************************************************************************** #
# INCLUDES #
INCS        			:= 	inc  												\
							inc/exec											\
							$(LIBS)/inc				
						   
# **************************************************************************** #
# LIBRARIES #
LIBS       				:= 	libft
LIBS_TARGET 			:= 	libft/libft.a
MLX_TARGET 				:= 	minilibx_opengl_20191021/libmlx.a
# **************************************************************************** #
# CC & FLAGS #
CC					    := 	cc -g3
CFLAGS					:= 	-Wall -Wextra -Werror 
CPPFLAGS 				:= 	-Iinc -Ilibft/inc -Iminilibx_opengl_20191021 -MMD -MP
LDFLAGS 				:= 	$(addprefix -L,$(dir $(LIBS_TARGET)))	 \
             				$(addprefix -L,$(dir $(MLX_TARGET)))
LDLIBS  				:= 	-L$(LIBS) -lmlx -lm -lft -framework OpenGL -framework AppKit
# **************************************************************************** #
# UTILS #
RM          			:= 	rm -f

# **************************************************************************** #