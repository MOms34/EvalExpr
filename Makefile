##
## EPITECH PROJECT, 2021
## InfinAdd
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-c -I./include/

SRC 		=	eval_exper.c \

OBJ 		= 	eval_exper.o \

TARGET		= 	eval_expr \

all: $(TARGET)

$(TARGET): $(OBJ)
	make -C ./lib/my
	$(CC) -o $(TARGET) $(OBJ) -L./lib/ -lmy

clean:
	rm -rf $(OBJ)
	make clean -C ./lib/my

fclean:clean
	rm -rf $(TARGET)

re:fclean all