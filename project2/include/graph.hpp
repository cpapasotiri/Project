#pragma once

#include <iostream>
#include <string>
#include "DLL.hpp"
#include "vertex.hpp"

using namespace std;

template <typename T>
class Graph
{
private:
    int number_of_vertices;
    Vector<Vertex<T>> *vertices;    // vector of vertices
    Vector<DLL<T>> *adjacency_list; // vector of adjacency lists
    // use srand(time()) in main.cpp
    int generate_random_vertex_number(int min, int max);

public:
    Graph();
    ~Graph();
    void add_vertex(Vector<T> *p); // TODELETE    // create a vertex
    void add_edges(int K);         // create K edges for each vertex
    DLL<T> &KNN(Vector<T> *p);     // K nearest neighbors for a given point
    Vector<DLL<T>> &K_NN();        // K nearest neighbors for all points
    void NNDescent();
    int get_number_of_vertices() const;
    Vertex<T> &get_vertex(int id);
    DLL<T> &get_adjacent_list(int id) const;  // get neighbors // IDK NECESSERY OR NOT
    int get_adjacent_list_size(int id) const; // get neightbors crowd // IDK NECESSERY OR NOT
    void display_graph();                     // CHANGE IMPLEMENTATION
};

#include "../templates/graph.tpp"