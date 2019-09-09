#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 18:41:04 by gmelisan          #+#    #+#              #
#    Updated: 2019/09/09 19:41:37 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

all:
	clang -Wall -Wextra -Werror -g -I./../42sh/libft/includes/ \
	ft_getopt.c main.c -o ft_getopt -L./../42sh/libft -lft
