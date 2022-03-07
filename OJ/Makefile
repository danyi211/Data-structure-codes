CC  = gcc
CXX = g++

INCLUDES =
CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS = 

.PHONY: default
default: main

main: main.o

# header dependency

main.o:
	$(CC) -c $(CFLAGS) 1014.c -o main.o

.PHONY: clean
clean:
	rm -f *.o *~ a.out core main

.PHONY: all
all: clean default
