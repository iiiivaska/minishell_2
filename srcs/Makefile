
NAME	=	minishell

SRCS	= 	main/minishell.c main/init_term.c main/init_all.c \
			utils/ft_strcmp.c utils/ft_strlen.c utils/ft_putchar.c utils/ft_putint.c \
			utils/ft_strlcpy.c utils/ft_strjoin.c utils/ft_calloc.c utils/ft_bzero.c \
			utils/is_escape.c utils/skip_quotes.c utils/is_spec.c utils/ft_isspace.c \
			utils/ft_strdup.c utils/ft_lstadd_back.c utils/ft_lstnew.c utils/ft_lstlast.c \
			utils/ft_lstclear.c utils/ft_itoa.c utils/ft_free_path.c utils/ft_isnum.c\
			utils/ft_putend_fd.c utils/ft_putstr_fd.c utils/ft_lstnew_pipe.c utils/is_valid_env_name.c\
			utils/ft_atoi.c utils/ft_strchr.c utils/ft_delay.c utils/is_valid_en.c\
			parser/parser.c parser/preparser.c parser/enviroment.c parser/quot.c parser/cut_commands.c \
			parser/cut_space.c parser/cut_param.c parser/cut_com.c parser/parse_path.c parser/enviroment_2.c\
			parser/syntax.c parser/cut_commands_2.c parser/cut_commands_3.c parser/cut_commands_4.c\
			parser/enviroment_3.c parser/enviroment_4.c parser/check_quotes.c parser/cut_quot_2.c\
			parser/cut_commands_5.c parser/update_cmd.c\
			pipe/pipe.c \
			executable/executable.c executable/find_path.c executable/executable_2.c executable/executable_3.c executable/executable_4.c\
			exit/ft_exit.c exit/clean.c exit/clean_2.c\
			signals/ft_signals.c signals/ft_signals_2.c \
			enviroment/env.c enviroment/env_2.c\
			redirect/redirect.c redirect/redirect_2.c redirect/redirect_3.c\
			buildins/echo.c buildins/pwd.c buildins/cd.c buildins/exit.c buildins/env.c buildins/export.c buildins/unset.c \
			shel_lvl/increment_shell_lvl.c

UNAME_S := $(shell uname -s)

GCC = clang

NEWFLAGS = -g -Wall -Wextra -Werror

OBJ		=	$(SRCS:.c=.o)

%.o: %.c $(HEADER)
	$(GCC) $(NEWFLAGS) -c $< -o $@

all		:	$(NAME)

HEADER	=	includes/minishell.h

ifeq ($(UNAME_S),Darwin)
FLAGS	=	-Wall -Wextra -Werror -lreadline -L/usr/local/Cellar/readline/8.1/lib -L/usr/local/Cellar/readline/8.1/include -ltermcap
endif

ifeq ($(UNAME_S),Linux)
FLAGS = -g -Wall -Wextra -Werror -lreadline -ltermcap -lncurses
endif

$(NAME)	:	$(OBJ) $(HEADER)
			$(GCC) $(FLAGS) -g -o $(NAME) $(OBJ)

clean	:	
			rm -f $(OBJ)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all

run		:	$(NAME)
			./minishell

.PHONY	: all clean fclean re