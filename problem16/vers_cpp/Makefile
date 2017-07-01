TARGET	 = p16

CC 		 = gcc
CXX		 = g++

INCLUDES = -I../../libs 
CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES) -std=c++11

LDFLAGS  = -g -L../../libs
LDLIBS   = -lbigint

$(TARGET):

.PHONY: clean
clean:
	rm -f a.out *.o $(TARGET)
