##
## Makefile for cpp_abstractvm in /var/projects/cpp_abstractvm
## 
## Made by kevin labbe
## Login   <labbe_k@epitech.net>
## 
## Started on  Tue Feb 26 23:14:41 2014 Kevin Labbe
## Last update Sun Mar  2 19:49:02 2014 kevin labbe
##

NAME		=	avm

CC			=	g++

CP			=	cp -f

RM			=	rm -f

CXXFLAGS	+=	-Iinclude/
CXXFLAGS	+=	-Wall -W -Wextra -Werror

SRC			=	src/main.cpp \
				src/Parsing/Instruction.cpp \
				src/Parsing/AvmParser.cpp \
				src/Parsing/Utils.cpp \
				src/Exception/AVMException.cpp \
				src/Exception/AssertFailedException.cpp \
				src/Exception/DivideByZeroException.cpp \
				src/Exception/ModuloByZeroException.cpp \
				src/Exception/EmptyStackException.cpp \
				src/Exception/OutOfRangeException.cpp \
				src/Exception/UnknownTypeException.cpp \
				src/Exception/UnknownInstructionException.cpp \
				src/Exception/WrongParameterException.cpp \
				src/Exception/WrongValueException.cpp \
				src/Exception/ExitMissingException.cpp \
				src/Exception/FileNotFoundException.cpp \
				src/Exception/InvalidFloatOperation.cpp \
				src/Arithmetic/OperandFactory.cpp \
				src/Arithmetic/Stack.cpp

OBJ			=	$(SRC:.cpp=.o)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
