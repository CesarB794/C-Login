CC=gcc -Wall
HEADER=headers/user.h
MAIN=sources/main.c
all:
	$(CC) $(HEADER) $(MAIN) -o bin/registro

