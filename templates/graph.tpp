#include <iostream>
#include <cmath>
#include "graph.hpp"

using namespace std;

template <typename T>
Pair<T>::Pair(float dist, Vertex<T> &vertex):distance(dist), v(new Vertex<T>(vertex))
{}

template <typename T>
Pair<T>::Pair():distance(0), v(new Vertex<T>())
{}

template <typename T>
Pair<T>::~Pair() 
{}

template <typename T>
Graph<T>::Graph(char* distance)
{
    number_of_vertices = 0;
    vertices = new Vector<Vertex<T>>();
    adjacency_list = new Vector<DLL<T>>();
    if (strcmp(distance, "e") == 0)
    {
        cout << "Euclidean distance selected" << endl;
        distance_function = &Vector<T>::euclideanDistance;
    }
    else if (strcmp(distance, "m") == 0)
    {
        cout << "Manhattan distance selected" << endl;
        distance_function = &Vector<T>::manhattanDistance;
    }
    else
    {
        cerr << "Invalid distance type. Select e for euclidean or m for manhattan." << endl;
    }
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
    Vertex<T> *vertex = new Vertex<T>(number_of_vertices, p);
    vertices->push_back(*vertex);
    DLL<T> *list = new DLL<T>();
    adjacency_list->push_back(*list);
    number_of_vertices++;
    delete list;
    delete vertex;
}

// create K random unique edges for each vertex
template <typename T>
void Graph<T>::add_edges(int K)
{ // create K edges for each vertex
    for (int i = 0; i < number_of_vertices; i++)
    { // for each vertex
        DLL<T> *current_list = &get_adjacent_list(i);

        int edges_count = 0;
        while (edges_count < K)
        { // select K random numbers
            int random_vertex_id = generate_random_vertex_number(0, number_of_vertices - 1);

            // avoid self-connections and dublicate connections
            bool in_current_list = current_list->search(&get_vertex(random_vertex_id));
            if ((i != random_vertex_id) && in_current_list == false)
            {
                current_list->addFirst(get_vertex(random_vertex_id));
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
        for (int i = 0; i < number_of_vertices; i++) 
        { // for every vertex
            DLL<T> *list = &get_adjacent_list(i);   // get the list of neighbors
            for (int j = 0; j < list->size(); j++) 
            { // for every neighbor
                int id = list->getNode(j)->Data->id;    // get the id of every neighbor
                float distance = ((&get_vertex(i))->point->*distance_function)(*(list->getNode(j)->Data->point));
                DLL<T> *neighborsList = &get_adjacent_list(id);     // get the list of neighbors
                for (int k = 0; k < neighborsList->size(); k++)
                {
                    if (list->search(neighborsList->getNode(k)->Data) == false)
                    {
                        float newDistance = ((&get_vertex(i))->point->*distance_function)(*(neighborsList->getNode(k)->Data->point));
                        if (newDistance < distance && newDistance != 0 && distance != 0)
                        { // update neighbors
                            list->addBefore(list->getNext(j), *(neighborsList->getNode(k)->Data));
                            list->remove(list->getNodeById(id));
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
int Graph<T>::get_adjacent_list_size(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid adjacency list id" << endl;
    }
    return adjacency_list->operator[](id).size();
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

template <typename T>
void Graph<T>::bruteForce(int K, int fd)
{   
    Vector<Pair<T>> *pairs;
    Pair<T> *p;
    for (int i = 0; i < number_of_vertices; i++)
    { // for every vertex
        pairs = new Vector<Pair<T>>();
        for (int j = 0; j < number_of_vertices; j++)
        { // for every vertex except itself
            if (j != i)
            { // calculate distance and save it as Pair
                float dist = ((&get_vertex(i))->point->*distance_function)(*(get_vertex(j)).point);
                p = new Pair<T>(dist, get_vertex(j));
                pairs->push_back(*p);
            }
        }
        
        for (size_t t = 0; t < pairs->get_size(); t++)
        { // sort pairs by distance            
            for (size_t k = 0; k < pairs->get_size()-t-1; k++)
            {   
                if (pairs->operator[](k).distance > pairs->operator[](k+1).distance)
                {
                    float temp = pairs->operator[](k).distance;
                    Vertex<T> *tempVertex = pairs->operator[](k).v;

                    pairs->operator[](k).distance = pairs->operator[](k+1).distance;
                    pairs->operator[](k).v = pairs->operator[](k+1).v;
                    pairs->operator[](k+1).distance = temp;
                    pairs->operator[](k+1).v = tempVertex;
                }
            }
        }

        for (int count = 0; count < K; count++)
        { // insert the first K pairs into the adjacency list & write vertex into file
            int id = get_vertex(i).id;
            adjacency_list->operator[](id).addLast(*(pairs->operator[](count).v));
            write_to_filepath(fd, pairs->operator[](count).v, sizeof(pairs->operator[](count).v));
        }
        delete pairs;
    }
    delete p;
}