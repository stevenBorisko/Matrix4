## Compiler
CC=g++
## Linker
LD=$(CC)
## Flags
CPPFLAGS = -Wall -O3 -g -std=c++11
LFLAGS = -lm -lpthread
## Executable
EXEC=runMatrix

TARGETS = $(PROGFILES:.cpp=)

PROGFILES = \
	main.cpp \
	Constructors.cpp \
	Friend.cpp \
	Miscellaneous.cpp \
	OperatorOverloads.cpp \
	Static.cpp \
	Vector.cpp \
	$(NULL)

targets default: $(TARGETS)

$(PROGFILES:.cpp=): main.o Constructors.o Friend.o Miscellaneous.o OperatorOverloads.o Static.o Vector.o
	$(CC) -o $(EXEC) main.o Constructors.o Friend.o Miscellaneous.o OperatorOverloads.o Static.o Vector.o ${LFLAGS}

depend :
	makedepend ${PROGFILES}

clean:
	rm -f *.o $(EXEC)

# DO NOT DELETE
