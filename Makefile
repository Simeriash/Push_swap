NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror -g

HEADER := push_swap.h

LIBFT := srcs/libft/libft.a


SOURCES := ft_push_swap.c ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c ft_make_list.c ft_split_ps.c ft_atoi_ps.c ft_format_stack.c


SRCS_DIR := srcs/
SRCS := $(addprefix $(SRCS_DIR), $(SOURCES))

OBJS_DIR := objs/
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))


.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(MAKE) -C srcs/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)$(SRCS_DIR)

$(OBJS_DIR)%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean : 
	rm -rf $(OBJS)
	rm -rf $(OBJS_DIR)
	$(MAKE) -C srcs/libft -B clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C srcs/libft -B fclean

re : fclean all
