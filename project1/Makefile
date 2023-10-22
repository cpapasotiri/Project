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


.PHONY: all project1 leaks debug tests clean
all: project1

project1: clean main.o hello.o add.o
	$(CC) -o $(EXEC) main.o hello.o add.o $(LIBS)
	./$(EXEC) $(ARGS)


main.o: $(SOURCE)main.cpp
	$(CC) $(CFLAGS) $(SOURCE)main.cpp $(LIBS)

hello.o: $(SOURCE)hello.cpp
	$(CC) $(CFLAGS) $(SOURCE)hello.cpp $(LIBS)

add.o: $(SOURCE)add.cpp
	$(CC) $(CFLAGS) $(SOURCE)add.cpp $(LIBS)

add_test.o: $(TESTS)add_test.cpp
	$(CC) $(CFLAGS) $(TESTS)add_test.cpp $(LIBS)


leaks: clean main.o hello.o add.o
	$(CC) -o $(EXEC) main.o hello.o add.o $(LIBS)
	valgrind ./$(EXEC) $(ARGS)


debug: clean main.o hello.o add.o
	$(CC) -o $(EXEC) main.o hello.o add.o $(LIBS)
	gdb ./$(EXEC) $(ARGS)


tests: clean add.o add_test.o
	$(CC) -o $(EXEC) add.o add_test.o $(LIBS)
	./$(EXEC) $(ARGS)


clean:
	-rm -f $(EXEC) *.o