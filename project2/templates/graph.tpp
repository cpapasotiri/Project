#include <iostream>
#include <cmath>
#include "graph.hpp"

using namespace std;

template <typename T>
Graph<T>::Graph()
{
    number_of_vertices = 0;
    vertices = new Vector<Vertex<T>>();
    adjacency_list = new Vector<DLL<T>>();
}

template <typename T>
Graph<T>::~Graph()
{
    delete vertices;
    delete adjacency_list;
}

// save vertex to vector and create a adjacency list for its neighbors
template <typename T>
void Graph<T>::add_vertex(Vector<T> *p)
{
    // Vertex<T> *vertex = new Vertex<T>();
    // vertex->id = number_of_vertices;
    // vertex->point = new Vector<T>(*p);
    Vertex<T> *vertex = new Vertex<T>(number_of_vertices, p);
    vertices->push_back(*vertex);
    DLL<T> *list = new DLL<T>();
    adjacency_list->push_back(*list);
    number_of_vertices++;
}

// create K random unique edges for each vertex
template <typename T>
void Graph<T>::add_edges(int K)
{ // create K edges for each vertex
    for (int i = 0; i < number_of_vertices; i++)
    { // for each vertex
        Vector<T> *current_point = get_vertex(i).point;
        DLL<T> *current_list = &get_adjacent_list(i);

        int edges_count = 0;
        while (edges_count < K)
        { // select K random numbers
            int random_vertex_id = generate_random_vertex_number(0, number_of_vertices - 1);

            // Vertex<T> *random_vertex = &get_vertex(random_vertex_id);     // TODO

            DLL<T> *random_list = &get_adjacent_list(random_vertex_id);

            // avoid self-connections and dublicate connections
            bool in_current_list = current_list->search(&get_vertex(random_vertex_id));
            if ((i != random_vertex_id) && in_current_list == false)
            {
                current_list->addFirst(get_vertex(random_vertex_id));
                // random_list->addFirst(*current_point, i);        // TODO
                edges_count++; // edge added
            }
        }
    }
}

template <typename T>
DLL<T> &Graph<T>::KNN(Vector<T> *p) // after the KNNG has been created, this function will return the KNN of a given point
{
    for (size_t i = 0; i < number_of_vertices; i++)
    {
        if ((get_vertex(i).point)->operator==(*p))
        {
            return get_adjacent_list(i);
        }
    }
}

template <typename T>
Vector<DLL<T>> &Graph<T>::K_NN()
{
    return adjacency_list;
}

template <typename T>
void Graph<T>::NNDescent()
{
    int count = -1;
    while (count != 0)
    { // loop stops when the graph isnt changed
        count = 0;
        for (int i = 0; i < number_of_vertices; i++) // for every vertex
        {
            DLL<T> *list = &get_adjacent_list(i); // get the list of neighbors
            // cout << "list of neighbors of vertex " << i << ": " << endl;
            // list->print();
            for (int j = 0; j < list->size(); j++) // for every neighbor
            {
                int id = list->getNode(j)->Data->id; // get the id of every neighbor
                float distance = (&get_vertex(i))->point->euclideanDistance(*(list->getNode(j)->Data->point));
                DLL<T> *neighborsList = &get_adjacent_list(id); // get the list of neighbors
                // cout << "list of neighbor's neighbor of vertex " << i << ": " << endl;
                // neighborsList->print();
                for (int k = 0; k < neighborsList->size(); k++)
                {

                    if (list->search(neighborsList->getNode(k)->Data) == false)
                    {
                        float newDistance = (&get_vertex(i))->point->euclideanDistance(*(neighborsList->getNode(k)->Data->point));
                        // cout << "Distance: " << distance << endl;
                        // cout << "New Distance: " << newDistance << endl;
                        if (newDistance < distance && newDistance != 0 && distance != 0)
                        { // update neighbors
                            list->addBefore(list->getNext(j), *(neighborsList->getNode(k)->Data));
                            // list->addFirst(*(neighborsList->getNodeById(k)->Data));
                            list->remove(list->getNodeById(id));
                            // neighborsList->remove_by_id(get_vertex(i).id);
                            // get_adjacent_list(neighborsList->getNode(k)->id).addLast(*(neighborsList->getNode(k)->Data), neighborsList->getNode(k)->id);
                            count++;
                        }
                    }
                }
            }
        }
    }
}

template <typename T>
int Graph<T>::get_number_of_vertices() const
{
    return number_of_vertices;
}

template <typename T>
Vertex<T> &Graph<T>::get_vertex(int id)
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid vertex id" << endl;
    }
    return vertices->operator[](id);
}

template <typename T>
DLL<T> &Graph<T>::get_adjacent_list(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid adjacency list id" << endl;
    }
    return adjacency_list->operator[](id);
}

template <typename T>
void Graph<T>::display_graph()
{ // for each vertex print adjacency graph
    for (int i = 0; i < number_of_vertices; i++)
    {
        cout << "Vertex " << i << ": " << endl;
        vertices->operator[](i).point->display_vector();
        cout << endl;
        cout << "neigbors are: " << endl;
        adjacency_list->operator[](i).print();
        cout << endl << endl;
    }
}

template <typename T>
int Graph<T>::generate_random_vertex_number(int min, int max)
{
    return min + rand() % (max - min + 1);
}