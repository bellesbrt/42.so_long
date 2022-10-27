NAME		=	so_long

RM			=	@rm -f

LIBFT_DIR	=	libft/
PRINTF_DIR	=	${LIBFT_DIR}ft_printf/
PRNTF_A		=	${PRINTF_DIR}libftprintf.a
I_PRINTF	=	-I${PRINTF_DIR} -L${PRINTF_DIR} -lftprintf

CC			=	@cc
CF			=	-Wall -Werror -Wextra

MLX			=	-lmlx -lXext -lX11

I_DIR		=	includes/
HEADERS		=	so_long.h
INCLUDE		=	$(addprefix ${I_DIR}, ${HEADERS})

S_DIR		=	src/
SRC			=\
			so_long.c\
			print_error.c\
			validate_args.c\
			validate_walls.c\
			get_all_lines.c\
			validate_map.c\
			init_controller.c\
			load_tiles.c\
			cleanup.c\
			render_map.c\
			key_handler.c\
			init_mlx.c
SOURCES		=	$(addprefix ${S_DIR}, ${SRC})

all		:	${NAME}

${NAME}	:	${PRNTF_A} ${SOURCES}
	${CC} ${CF} ${SOURCES} -I${I_DIR} ${I_PRINTF} ${MLX} -o $@

${PRNTF_A}	:
	@make -C ${PRINTF_DIR} --no-print-directory

clean	:
	@make clean -C ${PRINTF_DIR} --no-print-directory

fclean	:	clean
	@make fclean -C ${PRINTF_DIR} --no-print-directory
	${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re

