#include <iostream>
#include <cmath>
#include "graph.hpp"

using namespace std;

template <typename T>
Vertex<T>::Vertex() : id(0), point(new Vector<T>()) {}

template <typename T>
Vertex<T>::Vertex(const Vertex<T> &other) : id(other.id), point(new Vector<T>(*other.point)) {}

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
Vertex<T>::~Vertex()
{
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
}

// save vertex to vector and create a adjacency list for its neighbors
template <typename T>
void Graph<T>::add_vertex(Vector<T> *p) // CHECK if vertex pushed in the vectors & return boolean
{
    Vertex<T> *vertex = new Vertex<T>();
    vertex->id = number_of_vertices;
    vertex->point = new Vector<T>(*p);
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
    {                                               // for each vertex
        Vector<T> *current_point = get_vertex(i).point;
        DLL<T> *current_list = &get_adjacent_list(i);

        int edges_count = 0;
        while (edges_count < K)
        { // select K random numbers
            int random_vertex_id = generate_random_vertex_number(0, number_of_vertices - 1);

            //Vertex<T> *random_vertex = &get_vertex(random_vertex_id);     // TODO

            Vector<T> *random_point = get_vertex(random_vertex_id).point;
            DLL<T> *random_list = &get_adjacent_list(random_vertex_id);

            // avoid self-connections and dublicate connections
            bool in_current_list = current_list->search(random_point);
            if ((i != random_vertex_id) && in_current_list == false)
            {
                current_list->addFirst(*random_point, random_vertex_id);
                // random_list->addFirst(*current_point, i);        // TODO
                edges_count++; // edge added
            }
        }
    }
}

template <typename T>
void Graph<T>::NNDescent(Vector<T> *p)
{

}

template <typename T>
void Graph<T>::NNDescent()
{
    int count = -1;
    while (count != 0) {    // loop stops when the graph isnt changed
    // for (int t = 0; t < 1; t++){
        count = 0;
        for (size_t i = 0; i < number_of_vertices; i++) // for every vertex
        {
            DLL<T> *list = &get_adjacent_list(i); // get the list of neighbors
            for (size_t j = 0; j < list->size(); j++) // for every neighbor
            {
                int id = list->getNode(j)->id;                  // get the id of every neighbor
                float distance = (&get_vertex(i))->point->euclideanDistance(*(list->getNode(j)->Data));
                DLL<T> *neighborsList = &get_adjacent_list(id); // get the list of neighbors
                for (size_t k = 0; k < neighborsList->size(); k++)
                {
                    float newDistance = (&get_vertex(i))->point->euclideanDistance(*(neighborsList->getNode(k)->Data));
                    if (newDistance < distance && newDistance != 0 && distance != 0)
                    {   
                        if (list->search(neighborsList->getNode(k)->Data) == false)
                        {   // update neighbors
                            list->addBefore(list->getNext(j), *(neighborsList->getNode(k)->Data), neighborsList->getNode(k)->id);
                            list->remove(list->getNode(j));
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

// TODO print each vertex id and adjacency list
template <typename T>
void Graph<T>::display_graph()
{ // for each vertex print adjacency graph
    for (int i = 0; i < number_of_vertices; i++)
    {
        cout << "Vertex " << i << ": " << endl; 
        vertices->operator[](i).point->display_vector();
        cout << endl;
        cout << "adjacency list: " << i << ": " << endl;
        adjacency_list->operator[](i).print();
        cout << endl << endl;
    }
}

template <typename T>
int Graph<T>::generate_random_vertex_number(int min, int max)
{   
    return min + rand() % (max - min + 1);
}