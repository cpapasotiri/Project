#include "graph.hpp"


Graph::Graph(int vertices){
    this->number_of_vertices = vertices;
    adjacency_list = new list<int>[vertices];
}

Graph::~Graph(){
    delete[] adjacency_list;
}

void Graph::add_edge(int v, int w){
    adjacency_list[v].push_back(w);
    adjacency_list[w].push_back(v);
}

void Graph::add_vertex(){
    number_of_vertices++;
    list<int>* new_adjacency_list = new list<int>[number_of_vertices];
    for (int i = 0; i < number_of_vertices; i++) {
        new_adjacency_list[i] = adjacency_list[i];
    }
    delete[] adjacency_list;
    adjacency_list = new_adjacency_list;
}

void Graph::display_graph(){
    for (int i = 0; i < number_of_vertices; i++) {
        cout << "Adjacency list of vertex: " << i << ": " ;
        copy(adjacency_list[i].begin(), adjacency_list[i].end(), ostream_iterator<int>(cout, " "));
        cout << endl; 
    }
}

