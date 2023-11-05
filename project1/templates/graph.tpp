#include <iostream>
#include <cmath>
#include "graph.hpp"

using namespace std;

template <typename T>
Vertex<T>::Vertex(int id, Vector<T> &point) : id(id), point(new Vector<T>(point))
{
}

template <typename T>
Vertex<T>::Vertex() : id(0), point(new Vector<T>()) {}

template <typename T>
Vertex<T> &Vertex<T>::operator=(const Vertex<T> &other)
{
    if (this != &other)
    {
        this->id = other.id;
        this->point = other.point; 
    }
    return *this;
}

template <typename T>
Vertex<T>::~Vertex() {
    // cout << "destrustor of vertex " << endl;
}

// template <typename T>
// void Vertex<T>::add_point(Vector<T> point) {
//     this->point = point;
// }

template <typename T>
Vector<T>& Vertex<T>::get_point() const{
    // cout << "den adexw allo" << endl;
    // cout << "MY ID IS " << this->id << endl;
    return *this->point;
}

template <typename T>
Graph<T>::Graph()
{
    vertices = new Vector<Vertex<T>>();
    adjacency_list = new Vector<DLL<T>>();
}

template <typename T>
Graph<T>::~Graph()
{   
    // delete vertices;
    // cout << "destructor of graph " << endl;

    // delete adjacency_list;
}

// save vertex to vector and create a adjacency list for its neighbors
template <typename T>
void Graph<T>::add_vertex(Vector<T> &point) // CHECK if vertex pushed in the vectors & return boolean
{   
    // cout << "bika mesa" << endl;
    Vertex<T> *vertex = new Vertex<T>(number_of_vertices, point);
    // cout << "Vertex " << number_of_vertices << " added" << endl;
    vertices->push_back(*vertex);
    // cout << "pushback done" << endl;
    DLL<T> *list = new DLL<T>();
    adjacency_list->push_back(*list);
    // cout << "pushback adjacecny done" << endl;
    number_of_vertices++;
    // cout << "number of vertices: " << number_of_vertices << endl;
    
}

// create K random unique edges for each vertex
template <typename T>
void Graph<T>::add_edges(int K)
{   // create K edges for each vertex
    for (int i = 0; i < number_of_vertices; i++)
    { // for each vertex
        Vertex<T> current_vertex = get_vertex(i);  // i is the id of current vertex
        // cout << "get current vertex " << endl;
        Vector<T> current_point =  current_vertex.get_point();
        // cout << "get current point" << endl;
        DLL<T> current_list = get_adjacent_list(i);
        // cout << "get current list" << endl;
        int edges_count = 0;
        while (edges_count < K) 
        { // select K random numbers
            int random_vertex_id = generate_random_vertex_number(0, number_of_vertices - 1);       
            Vertex<T> random_vertex = get_vertex(random_vertex_id);
            // cout << "get rendom vertex" << endl;
            Vector<T> random_point =  random_vertex.get_point();
            // cout << "get random point" << endl;
            DLL<T> random_list = get_adjacent_list(random_vertex_id);
            // cout << "get random list " << endl;

            // avoid self-connections and dublicate connections
            bool in_current_list = current_list.search(&random_point);
            // cout << "search returns " << in_current_list << endl;
            if (i != random_vertex_id && in_current_list == false) {
                // cout << "in random if " << endl;
                current_list.addFirst(random_point);
                random_list.addFirst(current_point);
                edges_count++;      // edge added
                cout << "In vertex_id " << i << " added the " << random_vertex_id << endl;
            }
            // cout << "HERE " << endl;
        }
    }
}

template <typename T>
int Graph<T>::get_number_of_vertices() const
{
    return number_of_vertices;
}

template <typename T>
Vertex<T>& Graph<T>::get_vertex(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid vertex id" << endl;
        //return nullptr;
    }
    return vertices->operator[](id);
}

template <typename T>
DLL<T>& Graph<T>::get_adjacent_list(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid adjacency list id" << endl;
        // return nullptr;
    }
    return adjacency_list->operator[](id);
}

// TODO print each vertex id and adjacency list
template <typename T>
void Graph<T>::display_graph()
{ // for each vertex print adjacency graph
    for (int i = 0; i < number_of_vertices; i++)
    {
        cout << "Vertex " << i << ": ";
        vertices[i].display_vector();
        cout << "adjacency list: " << i << ": ";
        adjacency_list[i].print();
        cout << endl;
    }
}

template <typename T>
int Graph<T>::generate_random_vertex_number(int min, int max) {
    return min + rand() % (max - min + 1);
}