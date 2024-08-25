# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavier <afavier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 15:00:52 by afavier           #+#    #+#              #
#    Updated: 2024/02/13 13:17:59 by afavier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_DIR = src
BUILD_DIR = .build
DEPS_DIR = .deps
INC = inc/libft.h \
	inc/get_next_line.h\
	inc/ft_printf.h \
	inc/ft_dprintf.h
# LIBFT ********************************************************************* #  
LIBFT_FT_IS				:= 	$(SRC_DIR)/ft_is/ft_isalnum.c		\
							$(SRC_DIR)/ft_is/ft_isalpha.c	\
							$(SRC_DIR)/ft_is/ft_isascii.c		\
						   	$(SRC_DIR)/ft_is/ft_isdigit.c		\
						   	$(SRC_DIR)/ft_is/ft_isprint.c
			
LIBFT_FT_LST			:= 	$(SRC_DIR)/ft_lst/ft_lstadd_back.c	\
						   	$(SRC_DIR)/ft_lst/ft_lstadd_front.c	\
						   	$(SRC_DIR)/ft_lst/ft_lstclear.c		\
						   	$(SRC_DIR)/ft_lst/ft_lstdelone.c	\
						   	$(SRC_DIR)/ft_lst/ft_lstiter.c		\
						   	$(SRC_DIR)/ft_lst/ft_lstlast.c		\
						   	$(SRC_DIR)/ft_lst/ft_lstmap.c		\
						  	$(SRC_DIR)/ft_lst/ft_lstnew.c		\
						  	$(SRC_DIR)/ft_lst/ft_lstsize.c

LIBFT_FT_MEM			:= 	$(SRC_DIR)/ft_mem/ft_bzero.c		\
							$(SRC_DIR)/ft_mem/ft_calloc.c		\
							$(SRC_DIR)/ft_mem/ft_memchr.c		\
							$(SRC_DIR)/ft_mem/ft_memcmp.c		\
							$(SRC_DIR)/ft_mem/ft_memcpy.c		\
							$(SRC_DIR)/ft_mem/ft_memmove.c		\
							$(SRC_DIR)/ft_mem/ft_memset.c
					
LIBFT_FT_PUT			:=	$(SRC_DIR)/ft_put/ft_putchar_fd.c	\
							$(SRC_DIR)/ft_put/ft_putendl_fd.c	\
							$(SRC_DIR)/ft_put/ft_putnbr_fd.c	\
							$(SRC_DIR)/ft_put/ft_putstr_fd.c

LIBFT_FT_STR			:=	$(SRC_DIR)/ft_str/ft_split.c 		\
							$(SRC_DIR)/ft_str/ft_strchr.c 		\
							$(SRC_DIR)/ft_str/ft_strncmp.c 		\
							$(SRC_DIR)/ft_str/ft_strdup.c 		\
							$(SRC_DIR)/ft_str/ft_striteri.c 	\
							$(SRC_DIR)/ft_str/ft_strjoin.c 		\
							$(SRC_DIR)/ft_str/ft_strlcat.c 		\
							$(SRC_DIR)/ft_str/ft_strlcpy.c 		\
							$(SRC_DIR)/ft_str/ft_strlen.c 		\
							$(SRC_DIR)/ft_str/ft_strmapi.c 		\
							$(SRC_DIR)/ft_str/ft_strncmp.c 		\
							$(SRC_DIR)/ft_str/ft_strnstr.c 		\
							$(SRC_DIR)/ft_str/ft_strrchr.c 		\
							$(SRC_DIR)/ft_str/ft_strtrim.c 		\
							$(SRC_DIR)/ft_str/ft_substr.c
					
LIBFT_FT_TO				:= 	$(SRC_DIR)/ft_to/ft_atoi.c	\
							$(SRC_DIR)/ft_to/ft_itoa.c	\
							$(SRC_DIR)/ft_to/ft_tolower.c 	\
							$(SRC_DIR)/ft_to/ft_toupper.c	
							
LIBFT_GET_NEXT_LINE		:= 	$(SRC_DIR)/getnextline/get_next_line.c	 	\
							$(SRC_DIR)/getnextline/get_next_line_utils.c
# FT_PRINTF ***************************************************************** #
LIBFT_FT_PRINTF 		:= 	$(SRC_DIR)/printf/ft_printf_printf.c						\
							$(SRC_DIR)/printf/ft_putchar_printf.c\
							$(SRC_DIR)/printf/ft_putnbr_add_printf.c\
							$(SRC_DIR)/printf/ft_putnbr_base_printf.c\
							$(SRC_DIR)/printf/ft_putnbr_printf.c\
							$(SRC_DIR)/printf/ft_putnbr_unsip_printf.c\
							$(SRC_DIR)/printf/ft_putstr_printf.c
							
LIBFT_FT_DPRINTF		:=  $(SRC_DIR)/ft_dprintf/ft_dprintf.c \
							$(SRC_DIR)/ft_dprintf/ft_dputchar.c \
							$(SRC_DIR)/ft_dprintf/ft_dputnbr_add.c \
							$(SRC_DIR)/ft_dprintf/ft_dputnbr_base.c \
							$(SRC_DIR)/ft_dprintf/ft_dputnbr.c \
							$(SRC_DIR)/ft_dprintf/ft_dputnbr_unsi.c \
							$(SRC_DIR)/ft_dprintf/ft_dputstr.c \
							$(SRC_DIR)/ft_dprintf/ft_dstrlen.c 

SRCS 					:= 	$(LIBFT_FT_IS) \
							$(LIBFT_FT_LST)			\
							$(LIBFT_FT_MEM)									\
							$(LIBFT_FT_PRINTF) 								\
							$(LIBFT_FT_PUT)								\
							$(LIBFT_FT_STR)									\
							$(LIBFT_FT_TO)								\
							$(LIBFT_GET_NEXT_LINE) 	 	\
							$(LIBFT_FT_DPRINTF)

							
OBJS 					:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS 					:= $(patsubst %.o, %.d,$(OBJS))	

CC          			:= cc
CFLAGS      			:= -Wall -Wextra -Werror
CPPFLAGS    			:= -MMD -MP -I include
AR          			:= ar
ARFLAGS     			:= -rcs

RM := rm -f

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS);

-include $(DEPS)
# **************************************************************************** #
clean:
	$(RM) -r $(BUILD_DIR) $(DEPS_DIR)
# **************************************************************************** #
fclean: clean
	$(RM) $(NAME)
# **************************************************************************** #
re: fclean all
# **************************************************************************** # # .PHONY #
.PHONY: all clean fclean re
# *****************************