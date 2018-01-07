JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
		  P11.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
