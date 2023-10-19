INCLUDE := include/
SOURCE := src/
TESTS := tests/
INPUT := input/
LOGS := logs/

CC := g++
CFLAGS := -Wall -Wextra -c -I $(INCLUDE)
LIBS := -lm 

EXEC := project
ARGS :=


.PHONY: all project1 leaks debug clean
all: project1

project1: clean main.o hello.o
	$(CC) -o $(EXEC) main.o hello.o $(LIBS)
	./$(EXEC) $(ARGS)


main.o: $(SOURCE)main.cpp
	$(CC) $(CFLAGS) $(SOURCE)main.cpp $(LIBS)

hello.o: $(SOURCE)hello.cpp
	$(CC) $(CFLAGS) $(SOURCE)hello.cpp $(LIBS)


leaks: clean main.o hello.o 
	$(CC) -o $(EXEC) main.o hello.o  $(LIBS)
	valgrind ./$(EXEC) $(ARGS)


debug: clean main.o hello.o 
	$(CC) -o $(EXEC) main.o hello.o  $(LIBS)
	gdb ./$(EXEC) $(ARGS)


clean:
	-rm -f $(EXEC) *.o