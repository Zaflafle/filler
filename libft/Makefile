# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macuguen <macuguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 07:34:48 by macuguen          #+#    #+#              #
#    Updated: 2018/04/21 11:39:53 by macuguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_atoi.c \
		get_next_line.c \
		ft_strlen_tp.c \
		ft_strlen_dp.c  \
		ft_strdup_other.c \
		ft_search_one_carac.c \
		ft_search_tow_carac.c \
		ft_strlen_search_tow.c \
		ft_realloc.c \
		ft_bzero.c \
		ft_is_neg.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c\
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c\
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_print_words_tables.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_putendl_fd.c\
		ft_putendl.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_swap_int.c \
		ft_swap_char.c \
		ft_strrev.c \
		ft_div_mod.c \
		ft_nputstr.c \
		ft_strlen_w.c \
		ft_strdel_w.c \
		ft_putstr_w.c \
		ft_strdup_wchar.c \
		ft_strupper.c \
		ft_count_bit_w.c 
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./includes/libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
%.o: %.c ./includes/libft.h
	$(CC) $(CFLAGS) -I./includes/libft.h -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
