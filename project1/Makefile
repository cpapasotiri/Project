INCLUDE := include/
SOURCE := src/
TESTS := tests/
INPUT := input/
LOGS := logs/

CXX := g++
CFLAGS := -Wall -Wextra -c -g -I $(INCLUDE)
LIBS := -lm 

EXEC := project
OBJS := main.o hello.o add.o input.o 
ARGS :=

EXEC_TESTS := project_tests
OBJS_TESTS := add_tests.o input_tests.o
ARGS_TESTS :=

.PHONY: run leaks debug tests clean

run: $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	./$(EXEC) $(ARGS)

main.o: $(SOURCE)main.cpp
	$(CXX) $(CFLAGS) $(SOURCE)main.cpp $(LIBS)

hello.o: $(SOURCE)hello.cpp
	$(CXX) $(CFLAGS) $(SOURCE)hello.cpp $(LIBS)

add.o: $(SOURCE)add.cpp
	$(CXX) $(CFLAGS) $(SOURCE)add.cpp $(LIBS)

input.o: $(SOURCE)input.cpp
	$(CXX) $(CFLAGS) $(SOURCE)input.cpp $(LIBS)


tests: clean $(OBJS_TESTS)
	$(CXX) -o $(EXEC_TESTS) $(OBJS_TESTS) $(LIBS)
	./$(EXEC_TESTS) $(ARGS_TESTS)

add_test.o: $(TESTS)add_test.cpp
	$(CXX) $(CFLAGS) $(TESTS)add_test.cpp $(LIBS)

input_test.o: $(TESTS)input_test.cpp
	$(CXX) $(CFLAGS) $(TESTS)input_test.cpp $(LIBS)


leaks: clean $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	valgrind ./$(EXEC) $(ARGS)


debug: clean $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	gdb ./$(EXEC) $(ARGS)


clean:
	-rm -f $(EXEC) $(EXEC_TESTS) *.o