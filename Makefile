# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:05:04 by bleplat           #+#    #+#              #
#    Updated: 2018/12/04 20:25:26 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FNT = ft_atoi \
		ft_bzero \
		ft_free_vectors \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isblank \
		ft_iscntrl \
		ft_isdigit \
		ft_isprint \
		ft_isspace \
		ft_isxdigit \
		ft_itoa \
		ft_lstadd \
		ft_lstcount \
		ft_lstdel \
		ft_lstdelone \
		ft_lstfold \
		ft_lstindex \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_max \
		ft_memalloc \
		ft_memccpy \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memdel \
		ft_memdup \
		ft_memmove \
		ft_memrealloc \
		ft_memset \
		ft_min \
		ft_putchar \
		ft_putchar_fd \
		ft_putendl \
		ft_putendl_fd \
		ft_putnbr \
		ft_putnbr_fd \
		ft_putstr \
		ft_putstr_fd \
		ft_sqrt \
		ft_strcat \
		ft_strchr \
		ft_strclr \
		ft_strcmp \
		ft_strcpy \
		ft_strdel \
		ft_strdup \
		ft_strequ \
		ft_striter \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlen \
		ft_strlstsplit \
		ft_strmap \
		ft_strmapi \
		ft_strncat \
		ft_strncmp \
		ft_strncpy \
		ft_strndup \
		ft_strnequ \
		ft_strnew \
		ft_strnstr \
		ft_strrchr \
		ft_strsplit \
		ft_strstr \
		ft_strsub \
		ft_strtolower \
		ft_strtoupper \
		ft_strtrim \
		ft_tolower \
		ft_toupper \
		ft_putwchar \
		ft_putwchar_fd \
		ft_putwstr \
		ft_putwstr_fd \
		ft_wstrlen \
		ft_isstrnum \
		ft_strbegins \
		ft_strends \
		ft_lstpop \
		ft_pushpop \
		ft_lltoa \
		ft_ulltoa_basestr \
		ft_strfuse \
		ft_autofree_pushpop \
		ft_autofree_begin \
		ft_autofree \
		ft_autofree_end

INCLUDES = includes
SRC_DIR = srcs
OBJ_DIR = obj

CFLAGS = -Wall -Werror -Wextra -O3

SRC = $(patsubst %, $(SRC_DIR)/%.c, $(FNT))
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)/libft.h | $(OBJ_DIR)
	gcc $(CFLAGS) -o $@ -I $(INCLUDES) -c $<

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all
