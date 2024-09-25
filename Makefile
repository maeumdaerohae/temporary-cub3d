# **************************************************************************** #
# START #
# **************************************************************************** #
# **************************************************************************** #
# NAME & DIRS #
NAME        			:= 	cub3D
SRC_DIR 				:= 	src
BUILD_DIR 				:= 	.build
DEPS_DIR 				:= 	.deps
# **************************************************************************** #
# PATHS #
SOURCES 				:= 	$(SRC_DIR)/exec/game/visual.c			\
							$(SRC_DIR)/exec/game/ceiling_floor.c	\
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

OS	= $(shell uname -s)

MINILIBX_PATH = lol.
# LIBRARIES #
LIBS       				:= 	libft
LIBS_TARGET 			:= 	libft/libft.a

ifeq ($(OS), Linux)
	MINILIBX_PATH		=	 minilibx-linux/
	MLX_TARGET			= 	 minilibx-linux/libmlx_Linux.a
	CPPFLAGS 				:= 	-Iinc -Ilibft/inc -Iminilibx-linux -MMD -MP
	LDLIBS  				:= 	-L$(LIBS) -lmlx_Linux -lft -lX11 -lXext -lm 
endif

ifeq ($(OS), Darwin)
	MINILIBX_PATH			=	minilibx_opengl_20191021/
	MLX_TARGET				=	minilibx_opengl_20191021/libmlx.a
	CPPFLAGS 				:= 	-Iinc -Ilibft/inc -Iminilibx_opengl_20191021 -MMD -MP
	LDLIBS  				:= 	-L$(LIBS) -lmlx -lm -lft -framework OpenGL -framework AppKit
endif


# **************************************************************************** #
# CC & FLAGS #
CC					    := 	cc -g3
CFLAGS					:= 	-Wall -Wextra -Werror
# CPPFLAGS 				:= 	-Iinc -Ilibft/inc -Iminilibx_opengl_20191021 -MMD -MP
LDFLAGS 				:= 	$(addprefix -L,$(dir $(LIBS_TARGET)))	 \
             				$(addprefix -L,$(dir $(MLX_TARGET)))
# LDLIBS  				:= 	-L$(LIBS) -lmlx -lm -lft -framework OpenGL -framework AppKit
# **************************************************************************** #
# UTILS #
RM          			:= 	rm -f

# **************************************************************************** #
# **************************************************************************** #

# RULES #
all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET) $(MLX_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

force:

$(LIBS_TARGET): force
	@$(MAKE) -C $(@D) --no-print-directory

$(MLX_TARGET): force
	@$(MAKE) -C $(MINILIBX_PATH) --no-print-directory

-include $(DEPS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@mkdir -p $(DEPS_DIR)/$(patsubst $(SRC_DIR)/%,%,$(dir $<))
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@find $(BUILD_DIR) -name '*.d' | while read -r file; do \
		dest=$$(echo "$$file" | sed "s|^$(BUILD_DIR)|$(DEPS_DIR)|"); \
		mkdir -p "$$(dirname "$$dest")"; \
		mv "$$file" "$$dest"; \
	done

clean:
	@DIRS="$(CLEAN_DIRS) "; \
	while [ -n "$$DIRS" ]; do \
		CUR_DIR=$$(echo "$$DIRS" | cut -d' ' -f1); \
		if [ -e "$$CUR_DIR/Makefile" ]; then \
			$(MAKE) -C $$CUR_DIR clean --no-print-directory; \
		fi; \
		DIRS=$$(echo "$$DIRS" | sed 's/^[^ ]* *//'); \
		if [ "$$CUR_DIR" = "$$DIRS" ]; then break; fi; \
	done
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR)

	# Clean the minilibx_opengl build
	@$(MAKE) -C $(MINILIBX_PATH) clean --no-print-directory

fclean:
	@DIRS="$(CLEAN_DIRS) "; \
	while [ -n "$$DIRS" ]; do \
		CUR_DIR=$$(echo "$$DIRS" | cut -d' ' -f1); \
		if [ -e "$$CUR_DIR/Makefile" ]; then \
			$(MAKE) -C $$CUR_DIR fclean --no-print-directory; \
		fi; \
		DIRS=$$(echo "$$DIRS" | sed 's/^[^ ]* *//'); \
		if [ "$$CUR_DIR" = "$$DIRS" ]; then break; fi; \
	done
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR) $(NAME) $(BONUS)
	# Full clean the minilibx_opengl build
	@$(MAKE) -C $(MINILIBX_PATH) clean --no-print-directory || true

re: fclean all

.PHONY: all clean fclean re force