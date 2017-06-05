# Makefile for generating libraries

CC		= gcc
CXX		= g++

INCLUDES=
CFLAGS  = -g -Wall $(INCLUDES)
CXXFLAGS= -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS	=

libbigint: bigint.o
	ar rc libbigint.a bigint.o
	ranlib libbigint.a

bigint.o:

.PHONY: clean
clean:
	rm -f *.o a.out libbigint.a
