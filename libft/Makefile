# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 11:05:17 by tmichel-          #+#    #+#              #
#    Updated: 2022/12/28 15:44:01 by tmichel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c\
		  ft_bzero.c\
		  ft_calloc.c\
		  ft_isalnum.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_strlen.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strdup.c\
		  ft_strjoin.c\
		  ft_strlcat.c\
		  ft_strlcpy.c\
		  ft_strncmp.c\
		  ft_strnstr.c\
		  ft_substr.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_strtrim.c\
		  ft_split.c\
		  ft_itoa.c\
		  ft_strmapi.c\
		  ft_striteri.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_printf.c\
		  ft_printf_utils.c\
		  ft_printhexa.c\
		  ft_printptr.c\
		  ft_printunsigned.c\
		  get_next_line.c\
		  get_next_line_utils.c\
		  ft_atoi_long.c\
		  ft_swap.c\
		  ft_strcmp.c\

OBJS		= ${SRCS:.c=.o}

BONUS		=	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\

BONUS_OBJS	= ${BONUS:.c=.o}

INCS	= libft.h

LIB		= ar rcs

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${BONUS_OBJS} ${INCS}
			${LIB} ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
			rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean
			@make all

bonus:		${OBJS} ${BONUS_OBJS}
			${LIB} ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY:		all clean fclean re .c .o bonus