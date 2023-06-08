# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 12:51:00 by abenamar          #+#    #+#              #
#    Updated: 2023/06/08 21:35:22 by abenamar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

BONUS := checker

LIBFT := $(CURDIR)/libft/libft.a

INCLUDES := -I $(CURDIR)
INCLUDES += -I $(CURDIR)/libft

LDFLAGS := -L$(CURDIR)/libft

LDLIBS := -lft

SRCS := ft_atol.c
SRCS += ft_int.c
SRCS += ft_check.c
SRCS += ft_normalize.c
SRCS += ft_swap.c
SRCS += ft_push.c
SRCS += ft_rotate.c
SRCS += ft_reverse_rotate.c
SRCS += ft_operate.c
SRCS += ft_sort.c
SRCS += push_swap.c

BSRCS := checker.c

OBJS := $(SRCS:.c=.o)

BOBJS := $(BSRCS:.c=.o)

CC := cc

CFLAGS := -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -g3

ifdef DIVIDE
CFLAGS += -DDIVIDE=$(DIVIDE)
endif

RM := rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	@$(MAKE) -C $(CURDIR)/libft $(findstring bonus, $(MAKECMDGOALS))

$(BONUS): $(LIBFT) $(BOBJS)
	$(CC) $(CFLAGS) -o $(BONUS) $(BOBJS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

bonus: $(BONUS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(BOBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean all

.PHONY: re fclean clean all bonus
