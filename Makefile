# **************************************************************************** #
# START #
# **************************************************************************** #
# INCLUDE #
include Makefile_src.mk
# **************************************************************************** #
# RULES #
all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET) $(MLX_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

force:

$(LIBS_TARGET): force
	@$(MAKE) -C $(@D) --no-print-directory

$(MLX_TARGET): force
	@$(MAKE) -C minilibx_opengl_20191021/ --no-print-directory

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
	@$(MAKE) -C minilibx_opengl_20191021/ clean --no-print-directory

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
	@$(MAKE) -C minilibx_opengl_20191021/ fclean --no-print-directory || true

re: fclean all

.PHONY: all clean fclean re force