#pragma once

#include <iostream>
#include <string>
#include <list> // CHANGE THIS to DLL.hpp
#include <iterator>
#include "vector.hpp"

using namespace std;

class Graph
{
private:
    int number_of_vertices;
    list<int> *adjacency_list;

public:
    Graph(int vertices);
    ~Graph();
    void add_edge(int v, int w);
    void add_vertex();
    void display_graph();
};

template <typename T>
double euclideanDistance(const Vector<T> &point1, const Vector<T> &point2);

template <typename T>
double manhattanDistance(const Vector<T> &point1, const Vector<T> &point2);