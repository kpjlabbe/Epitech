##
## Makefile for 42sh in /media/data/all/projects/42sh-v1
## 
## Made by kevin labbe
## Login   <labbe_k@epitech.net>
## 
## Started on  Tue Apr 23 09:30:54 2013 kevin labbe
## Last update Sun Nov  2 06:06:46 2014 Kevin Labbe
##

NAME		=	42sh

CC		=	cc

D_LIB		=	lib/

MK_LIB		=	make -C $(D_LIB)

F_LIB		=	lib/libmy.a

CFLAGS		+=	-Wall -W
CFLAGS		+=	-Iinclude/

LDFLAGS		=	-Llib/ -lmy

SRC		=	src/main.c \
			src/variables/init_vars.c \
			src/commands/get_commands.c \
			src/others/print_prompt.c \
			src/parsing/delimiters.c \
			src/others/signals.c \
			src/builtins/builtins.c \
			src/builtins/builtin_cd.c \
			src/builtins/builtin_vars.c \
			src/builtins/builtin_setvars.c \
			src/builtins/builtin_unsetvars.c \
			src/builtins/builtin_env.c \
			src/builtins/builtin_local.c \
			src/builtins/builtin_exit.c \
			src/commands/cmd_processing.c \
			src/utils/my_execvp.c \
			src/commands/cmd_get_args.c \
			src/commands/cmd_show.c \
			src/commands/cmd_add.c \
			src/commands/cmd_del.c \
			src/variables/vars_get.c \
			src/others/env_fill.c \
			src/variables/vars_set.c \
			src/variables/vars_del.c \
			src/variables/vars_show.c \
			src/redirections/redir_right.c \
			src/redirections/redir_left.c \
			src/redirections/exec_redir.c \
			src/variables/vars_add.c \
			src/alias/alias_add.c \
			src/alias/alias_del.c \
			src/alias/alias_get.c \
			src/alias/alias_show.c \
			src/builtins/builtin_alias.c \
			src/builtins/builtin_setalias.c \
			src/builtins/builtin_unalias.c \
			src/builtins/builtin_source.c \
			src/redirections/redir_add.c \
			src/redirections/redir_del.c \
			src/redirections/redir_show.c \
			src/redirections/redir_get.c \
			src/parsing/parsing_file.c \
			src/parsing/parsing_line.c \
			src/parsing/parsing_commands.c \
			src/parsing/parsing_alias.c \
			src/parsing/parsing_redir.c \
			src/parsing/parsing_vars.c \
			src/parsing/parsing_globing.c \
			src/others/free_all.c \
			src/redirections/pipes.c \
			src/utils/xdirectory.c \
			src/utils/xmemory.c \
			src/utils/xredir.c \
			src/utils/xstring.c


OBJ		=	$(SRC:.c=.o)

CP		=	cp -f

RM		=	rm -f

all: 			create_lib $(NAME)

create_lib:
			@$(MK_LIB) all

$(NAME):		$(OBJ)
			@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
			@$(MK_LIB) clean
			@$(RM) $(OBJ)

fclean:			clean
			@$(MK_LIB) fclean
			@$(RM) $(F_LIB)
			@$(RM) $(NAME)

re:			fclean all

.PHONY: 		all create_lib clean fclean re
