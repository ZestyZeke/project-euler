JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
		  P10.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
