#This is a makefile

CC = clang
CFLAGS = -c -w -Wall
OBJ = motus
all:	$(OBJ)
$(OBJ):	console.o
	$(CC) console.o -o $(OBJ)

console.o: console.c
	$(CC) $(CFLAGS) console.c prototype.h
exec:
	./motus
clean:
	rm -rf motus
	rm -rf *.exe
	rm -rf *.o
