 
# Project: Die Comparison
# File: Makefile
# Purpose: Makefile for Die Comparison project

CC = cc
CFLAGS = -Wall
DEPS = die_comp_lib.h
OBJ = die_comp.o die_comp_lib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

die_comp: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o die_comp
