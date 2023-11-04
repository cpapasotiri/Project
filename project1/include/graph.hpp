#pragma once

#include <iostream>
#include <string>
#include "DLL.hpp"
#include "vector.hpp"

using namespace std;

template <typename T>
struct Vertex {
    int id;
    const Vector<T>& point;

    Vertex(int id, const Vector<T>& point); 
};

template <typename T>
class Graph
{
private:
    int number_of_vertices;
    Vertex<T>* vertex;
    Vector<DLL<T>> adjacency_list;

public:
    Graph();
    ~Graph();
    void add_edge(const Vertex<T>& vertex_a,const Vertex<T>& vertex_b);
    Vertex<T> *add_vertex(const Vector<T>& point);
    void display_graph();   // CHANGE IMPLEMENTATION
};

#include "../templates/graph.tpp"