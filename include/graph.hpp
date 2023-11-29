#pragma once

#include <iostream>
#include <cstring>
#include "DLL.hpp"
#include "vertex.hpp"

using namespace std;

template <typename T>
struct Pair
{
    float distance;
    Vertex<T> *v;

    Pair(float dist, Vertex<T> &v);
    Pair();
    ~Pair();
};

template <typename T>
class Graph
{
private:
    int number_of_vertices;
    Vector<Vertex<T>> *vertices;    // vector of vertices
    Vector<DLL<T>> *adjacency_list; // vector of adjacency lists

    // use srand(time()) in main.cpp
    int generate_random_vertex_number(int min, int max);
    float (Vector<T>::*distance_function)(const Vector<T>&); // pointer to distance function

public:
    Graph(char* distance);
    ~Graph();
    void add_vertex(Vector<T> *p); // create a vertex
    void add_edges(int K);         // create K edges for each vertex
    DLL<T> &KNN(Vector<T> *p);     // K nearest neighbors for a given point
    Vector<DLL<T>> &K_NN();        // K nearest neighbors for all points
    void NNDescent(int K);
    int get_number_of_vertices() const;
    Vertex<T> &get_vertex(int id);
    DLL<T> &get_adjacent_list(int id) const;  // get neighbors
    int get_adjacent_list_size(int id) const; // get neightbors crowd
    void display_graph();
    void bruteForce(int K, int fd);
};

#include "../templates/graph.tpp"