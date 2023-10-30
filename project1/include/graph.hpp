#pragma once

#include <iostream>
#include <string>

using namespace std;

// stores adjacency list items
struct node {
    int value;
    node* next;
};

// store a graph edge
struct edge {
    int source;
    int destination;
};

class Graph {
    private:
        int number_of_nodes;
        
    public:
        Graph();
        ~Graph();
        node* get_adjacent_list_node(int destination, node* head_node);
        void add_vertex();
        void add_edge();
        void display_graph();
};