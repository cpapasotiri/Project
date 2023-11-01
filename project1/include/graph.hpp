#pragma once

#include <iostream>
#include <string>
#include <list>     // CHANGE THIS to DLL.hpp
#include <iterator>

using namespace std;


class Graph {
    private:
        int number_of_vertices;
        list<int>* adjacency_list;
        
    public:
        Graph(int vertices);
        ~Graph();
        void add_edge(int v, int w);
        void add_vertex();
        void display_graph();
};