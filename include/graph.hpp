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
    bool operator==(Pair<T> &other);
};

template <typename T>
class Graph
{
private:
    int number_of_vertices;
    Vector<Vertex<T>> *vertices;    // vector of vertices
    Vector<DLL<T>> *neighbors_list; // vector of adjacency lists
    Vector<DLL<T>> *reverseNeighbors_list; // vector of reverse neighbors

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
    DLL<T> &get_neighbors_list(int id) const;           // get neighbors
    DLL<T> &get_reverseNeighbors_list(int id) const;    //get reverse neighbors
    int get_neighbors_list_size(int id) const;          // get neightbors crowd
    int get_reverseNeighbors_list_size(int id) const;   // get reverse neightbors crowd
    void display_graph();           // print graph
    void bruteForce(int K);
    int store_neighbors(int fd);    // store neighbors in file, returns true if successful or false otherwise
    int compare_neighbors(int fd);  // read & compare neighbors from file, returns count of same neighbors if successful or -1 otherwise
};

#include "../templates/graph.tpp"