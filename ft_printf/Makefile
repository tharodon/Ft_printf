NAME 		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc
OBJS	 	= ${SRCS:.c=.o}
LIBFT_OBJS	= ${LIBFT:.c=.o}
INCLUDE 	= ft_printf.h
SRCS 		= 	ft_flags.c ft_flags_unsigned.c ft_hexal.c ft_putnbr.c ft_putnbr_unsigned.c \
				ft_putstr.c ft_lennbr.c ft_parser_count.c ft_parser_count_s.c \
				ft_parser_count_t.c ft_parser_s.c ft_parser_s_t.c ft_parser_scount_t.c ft_parser_t.c \
				ft_parser_tcount_s.c ft_printf.c ft_atoi.c ft_strlen.c ft_strchr.c ft_checker.c ft_struct_zero.c\
				ft_parser_percent.c ft_parser_zero.c ft_itoa.c ft_input_s.c ft_input_t.c ft_input_s_t.c ft_input_cs.c ft_input_ct.c
# LIBFT		= ./libft/ft_atoi.c ./libft/ft_strlen.c  ./libft/ft_strchr.c

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${INCLUDE}
	@ar rcs ${NAME} $?

norm:
	norminette .

test_lib: all clean
	@$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

test_c:
	@$(CC) test3.c $(SRCS) -I $(INCLUDE) && ./a.out | cat -e

clean:
	@/bin/rm -f ${OBJS}
	@/bin/rm -f a.out

fclean: clean
	@rm -f ${NAME}

re: fclean all

main:
		gcc -o a.out *.o

.PHONY: all clean fclean re bonus
