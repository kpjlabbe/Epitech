##
## Makefile for 42shlib in /media/data/all/projects/42sh-v1/lib
## 
## Made by kevin labbe
## Login   <labbe_k@epitech.net>
## 
## Started on  Tue Apr 23 11:57:27 2013 kevin labbe
## Last update Fri May 10 14:19:11 2013 pierre-antoine urvoy
##

NAME		=	libmy.a

AR		=	ar rc

D_INC		=	include/

D_SRC		=	src/

D_ROOT		=	../

CFLAGS		=	-Wall -W -Werror

LDFLAGS		=	-I$(D_INC:%=my/%) -I$(D_INC:%=t_list/%)

F_MY		=	my_alloc \
			my_realloc \
			free_array \
			get_next_line \
			in_str \
			match \
			my_fprintf \
			my_printf \
			my_putchar \
			my_putstr \
			my_strcpy_to \
			my_strlen_to \
			trim \
			convert_base \
			is_number \
			my_atoi_base \
			my_atoi \
			my_itoa_base \
			my_itoa \
			my_putnbr_base \
			my_putnbr \
			my_pow \
			my_sqrt \
			count \
			explode \
			implode \
			in_array \
			str_replace

F_LIST		=	list_create \
			list_delete \
			list_get \
			list_insert \
			list_foreach

S_MY		=	$(F_MY:%=$(D_SRC:%=my/%)%.c)

S_LIST		=	$(F_LIST:%=$(D_SRC:%=t_list/%)%.c)

OBJ		=	$(F_MY:%=%.o) $(F_LIST:%=%.o)

CP		=	cp -f

RM		=	rm -f

all: 			$(NAME) cp_inc

$(NAME):
			@cc -c $(S_MY) $(S_LIST) $(CFLAGS) $(LDFLAGS)
			@$(AR) $(NAME) $(OBJ)

cp_inc:
			@$(CP) $(D_INC:%=my/%)my.h $(D_ROOT)$(D_INC)
			@$(CP) $(D_INC:%=my/%)my_struct.h $(D_ROOT)$(D_INC)
			@$(CP) $(D_INC:%=t_list/%)t_list.h $(D_ROOT)$(D_INC)
			@$(CP) $(D_INC:%=t_list/%)t_list_struct.h $(D_ROOT)$(D_INC)

clean:
			@$(RM) $(OBJ)

fclean: 		clean
			@$(RM) $(NAME)
			@$(RM) $(D_ROOT)$(D_INC)my.h
			@$(RM) $(D_ROOT)$(D_INC)my_struct.h
			@$(RM) $(D_ROOT)$(D_INC)t_list.h
			@$(RM) $(D_ROOT)$(D_INC)t_list_struct.h

re: 			fclean all
