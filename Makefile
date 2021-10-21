SRCS		=	src/push_swap.c\
				src/atoi_no_overflow.c\
				src/fundamental_operation_1.c\
				src/fundamental_operation_2.c\
				src/init_steck_a.c\
				src/parsing.c\
				src/utilit_1.c\
				src/up_cycles.c\
				src/sort.c\
				src/score_logic.c\
				src/pre_sort_2.c\
				src/pre_sort_1.c\
				src/operation_3.c\
				src/operation_2.c\
				src/operation_1.c\
				src/mini_sort.c\
				src/mini_sort_logic.c\
				src/math_function.c\
				src/init_b_and_score.c\
				src/down_cycles.c

SRCS_LIBFT	=	libft/ft_atoi.c			libft/ft_isdigit.c		libft/ft_memmove.c		libft/ft_strlen.c\
				libft/ft_bzero.c		libft/ft_isprint.c		libft/ft_memset.c		libft/ft_strncmp.c\
				libft/ft_calloc.c		libft/ft_memccpy.c		libft/ft_strchr.c		libft/ft_strnstr.c\
				libft/ft_isalnum.c		libft/ft_memchr.c		libft/ft_strdup.c		libft/ft_strrchr.c\
				libft/ft_isalpha.c		libft/ft_memcmp.c		libft/ft_strlcat.c		libft/ft_tolower.c\
				libft/ft_isascii.c		libft/ft_memcpy.c		libft/ft_strlcpy.c		libft/ft_toupper.c\
				libft/ft_substr.c		libft/ft_strjoin.c		libft/ft_strtrim.c		libft/ft_itoa.c\
				libft/ft_split.c		libft/ft_strmapi.c		libft/ft_putchar_fd.c	libft/ft_putstr_fd.c\
				libft/ft_putendl_fd.c	libft/ft_putnbr_fd.c	libft/get_next_line.c 	libft/ft_atoi_base.c\
				libft/ft_lstnew.c		libft/ft_lstadd_front.c	libft/ft_lstsize.c		libft/ft_lstlast.c\
				libft/ft_lstadd_back.c	libft/ft_lstdelone.c	libft/ft_lstclear.c		libft/ft_lstiter.c\
				libft/ft_lstprint_content.c
CHECK_NAME	=	checker

CHECK_SRCS	=	src/atoi_no_overflow.c\
				src/fundamental_operation_1.c\
				src/fundamental_operation_2.c\
				src/init_steck_a.c\
				src/parsing.c\
				src/utilit_1.c\
				src_checker/checker.c\
				src_checker/checker_operation_1.c\
				src_checker/checker_operation_2.c\
				src_checker/checker_operation_3.c\
				src_checker/end.c\
				src_checker/start.c

CHECK_OBJS	= ${CHECK_SRCS:.c=.o}

OBJS_LIBFT	= ${SRCS_LIBFT:.c=.o}

OBJS		= ${SRCS:.c=.o}

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

RM			= rm -f

NAME		= push_swap

CHECK_HEDR	= include/checker.h

HDR			= include/push_swap.h

HDR_LIBFT	= libft/libft.h



all: $(NAME) $(OBJS) $(HDR)

$(NAME):	$(OBJS) $(OBJS_LIBFT)
		make -C libft
		$(CC) $(FLAGS)  -Llibft -lft  $(SRCS) libft/libft.a -o push_swap

$(CHECK_NAME):	$(OBJS) $(OBJS_LIBFT) $(CHECK_OBJS)
		make -C libft
		$(CC) $(FLAGS)  -Llibft -lft  $(CHECK_SRCS) libft/libft.a -o checker


%.o: %.c $(HDR) $(HDR_LIBFT) $(CHECK_HEDR)
		$(CC) $(FLAGS) -c $< -o $@

bonus:	$(CHECK_NAME)

clean:
		$(RM) $(OBJS) $(CHECK_OBJS)
		$(MAKE) clean -C ./libft 

fclean:		clean
		$(RM) $(NAME) $(CHECK_NAME)
		$(MAKE) fclean -C ./libft

re:		fclean all clean