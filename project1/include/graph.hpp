#pragma once

#include <iostream>
#include <string>
#include <list> // CHANGE THIS to DLL.hpp
#include "vector.hpp"

using namespace std;

template <typename T>
class Graph
{
private:
    int number_of_vertices;
    list<int> *adjacency_list;

public:
    Graph(int vertices);
    ~Graph();
    void add_edge(int v, int w);
    void add_vertex(const Vector<T>& point);
    void display_graph();   // CHANGE IMPLEMENTATION
};

#include "../src/graph.tpp"