NAME		= libftprintf.a
LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
CC			= @cc
CFLAGS		= -Wall -Wextra -Werror
RM			= @rm -f
SRCS		= ft_print_char.c	\
				ft_print_string.c	\
				ft_print_int.c	\
				ft_print_unsigned_int.c	\
				ft_print_pointer.c	\
				ft_print_hex.c	\
				ft_print_hex_upper.c	\
				ft_printf.c
OBJS		= $(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_A)
	@ar -rcs $(NAME) $(OBJS)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@make -C $(LIBFT_DIR) --no-print-directory
	@cp $(LIBFT_A) $(NAME)

clean:
	@make $@ -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(OBJS)

fclean:	clean
	@make $@ -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
