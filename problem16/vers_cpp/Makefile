#TARGET	= p16

CC 		= g++
CFLAGS  = -g -Wall
LDFLAGS = -g
LDLIBS  =

#$(TARGET):

test: test.o bigint.o

test.o: bigint.h

bigint.o: bigint.h

clean:
	rm -f a.out *o $(TARGET)
