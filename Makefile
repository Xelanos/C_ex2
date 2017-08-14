GCC = gcc
CFLAGS = -g -DNDEBUG -std=c99 -Wall -Wextra -Wvla

run: MyStringExample
	./MyStringExample

MyStringExample: MyStringExample.o MyString.o
	$(GCC) -g -o MyStringExample  MyStringExample.o MyString.o

MyStringExample.o: 	MyStringExample.c MyString.h
	$(GCC) $(CFLAGS) -c -o MyStringExample.o MyStringExample.c
	
	
LineSeparator: LineSeparator.o
	$(GCC) -g -o LineSeparator  LineSeparator.o


clean:
	rm LineSeparator MyStringExample *.o

.PHONY: clean, run