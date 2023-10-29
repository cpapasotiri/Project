INCLUDE := include/
SOURCE := src/
TESTS := tests/
INPUT := input/
LOGS := logs/

CXX := g++
CFLAGS := -Wall -Wextra -c -g -I $(INCLUDE)
LIBS := -lm 

EXEC := project
OBJS := main.o input.o
ARGS :=

EXEC_TESTS := project_tests
OBJS_TESTS := input_test.o input.o
ARGS_TESTS := -#

.PHONY: run leaks debug tests clean

run: $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	./$(EXEC) $(ARGS)

main.o: $(SOURCE)main.cpp
	$(CXX) $(CFLAGS) $(SOURCE)main.cpp $(LIBS)

input.o: $(SOURCE)input.cpp
	$(CXX) $(CFLAGS) $(SOURCE)input.cpp $(LIBS)


tests: $(OBJS_TESTS)
	$(CXX) -o $(EXEC_TESTS) $(OBJS_TESTS) $(LIBS)
	./$(EXEC_TESTS) 

input_test.o: $(TESTS)input_test.cpp
	$(CXX) $(CFLAGS) $(TESTS)input_test.cpp $(LIBS)


leaks: $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	valgrind ./$(EXEC) $(ARGS)


debug: $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	gdb ./$(EXEC) $(ARGS)


clean:
	-rm -f $(EXEC) $(EXEC_TESTS) *.o