TARGET   = p13-bigint

CC 		 = gcc
CXX 	 = g++

INCLUDES = -I../../libs
CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS  = -g -L../../libs
LDLIBS 	 = -lbigint

$(TARGET):

.PHONY: clean
clean:
	rm -f a.out *.o $(TARGET)
