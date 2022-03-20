#
# Makefile for lab 4 part 1
#

CC  = gcc
CXX = g++

INCLUDES = #-I../../lab3/part1
CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = #-g -L../../lab3/part1
LDLIBS = #-lmylist

.PHONY: default
default: main

main: main.o SqStack.o

# header dependency

main.o: SqStack.h

SqList.o: SqStack.h

.PHONY: clean
clean:
	rm -f *.o *~ a.out core main

.PHONY: all
all: clean default

