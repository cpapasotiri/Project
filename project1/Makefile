INCLUDE := include/
SOURCE := src/
TESTS := tests/
INPUT := input/
LOGS := logs/

CXX := g++
CFLAGS := -Wall -Wextra -c -g -I $(INCLUDE)
LIBS := -lm 

EXEC := project
OBJS := main.o 
ARGS := -f ../project1/datasets/00000020.bin -d 100 -k 2
# ARGS := -f ../project1/datasets/points.csv -d 2 -k 2

EXEC_TESTS := project_tests
INPUT_TESTS := input_test.o input.o
GRAPH_TESTS := graph_test.o graph.o
VECTOR_TESTS := vector_test.o 
POINT_TESTS := point_test.o 
ARGS_TESTS := -#

.PHONY: run leaks debug tests clean

run: $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	./$(EXEC) $(ARGS)


main.o: $(SOURCE)main.cpp
	$(CXX) $(CFLAGS) $(SOURCE)main.cpp $(LIBS)



input.o: $(SOURCE)input.cpp
	$(CXX) $(CFLAGS) $(SOURCE)input.cpp $(LIBS)

graph.o: $(SOURCE)graph.cpp
	$(CXX) $(CFLAGS) $(SOURCE)graph.cpp $(LIBS)

input_test.o: $(TESTS)input_test.cpp
	$(CXX) $(CFLAGS) $(TESTS)input_test.cpp $(LIBS)

graph_test.o: $(TESTS)graph_test.cpp
	$(CXX) $(CFLAGS) $(TESTS)graph_test.cpp $(LIBS)

vector_test.o: $(TESTS)vector_test.cpp
	$(CXX) $(CFLAGS) $(TESTS)vector_test.cpp $(LIBS)

point_test.o: $(TESTS)point_test.cpp
	$(CXX) $(CFLAGS) $(TESTS)point_test.cpp $(LIBS)


tests: $(INPUT_TESTS) $(GRAPH_TESTS)
	$(CXX) -o $(EXEC_TESTS) $(INPUT_TESTS) $(LIBS)
	./$(EXEC_TESTS) 

	$(CXX) -o $(EXEC_TESTS) $(GRAPH_TESTS) $(LIBS)
	./$(EXEC_TESTS) 

	$(CXX) -o $(EXEC_TESTS) $(VECTOR_TESTS) $(LIBS)
	./$(EXEC_TESTS) 

	$(CXX) -o $(EXEC_TESTS) $(POINT_TESTS) $(LIBS)
	./$(EXEC_TESTS) 


leaks: $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	valgrind ./$(EXEC) $(ARGS)


debug: $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(LIBS)
	gdb ./$(EXEC) $(ARGS)


clean:
	-rm -f $(EXEC) $(EXEC_TESTS) *.o