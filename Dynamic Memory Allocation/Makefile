##
## Makefile for Makefile in /home/marcha_s/rendu/PSU_2013_malloc
## 
## Made by Christophe Marchand
## Login   <marcha_s@epitech.net>
## 
## Started on Sun Feb 16 17:35:14 2014 Kevin Labbe
## Last update Sun Feb 16 20:50:55 2014 Kevin Labbe

NAMELIB		=	libmy_malloc_$(HOSTTYPE).so

NAMELINK	=	libmy_malloc.so

CC		=	gcc

LN		=	ln -s

CFLAGS		=	-fpic -Iinclude/

LDFLAGS		=	-shared -lpthread

SRC		=	src/malloc.c \
			src/calloc.c \
			src/free.c \
			src/realloc.c \
			src/show_alloc_mem.c \
			src/header.c \
			src/blocks.c \
			src/address.c \

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

all:			$(NAMELIB) $(NAMELINK)

$(NAMELIB):		$(OBJ)
			$(CC) -o $(NAMELIB) $(OBJ) $(LDFLAGS)

$(NAMELINK):
			$(LN) $(NAMELIB) $(NAMELINK)

clean:			
			@$(RM) $(OBJ)

fclean:			clean
			@$(RM) $(NAMELIB)
			@$(RM) $(NAMELINK)

re:			fclean all
