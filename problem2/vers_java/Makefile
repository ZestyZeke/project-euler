# Makefile for Java Files
#
JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
		  Fib.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
