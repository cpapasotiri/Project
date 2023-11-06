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
    cout << "destrustor of vertex " << endl;
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
    cout << "destructor of graph " << endl;

    // delete adjacency_list;
}

// save vertex to vector and create a adjacency list for its neighbors
template <typename T>
void Graph<T>::add_vertex(Vector<T> *p) // CHECK if vertex pushed in the vectors & return boolean
{
    // cout << "bika mesa" << endl;
    Vertex<T> *vertex = new Vertex<T>();
    vertex->id = number_of_vertices;
    vertex->point = new Vector<T>(*p);
    // cout << "adding vertex " << vertex->id << endl;
    // vertex->point->display_vector();
    // cout << "Vertex " << number_of_vertices << " added" << endl;
    vertices->push_back(*vertex);
    // cout << "number of vertices " << vertices->get_size() << endl;
    // for (size_t i = 0; i < vertices->get_size(); i++)
    // {
    //     // cout << "Vertex " << i << " point" << endl;
    //     get_vertex(i).point->display_vector();
    // }

    // cout << "pushback done" << endl;
    DLL<T> *list = new DLL<T>();
    adjacency_list->push_back(*list);
    // // cout << "pushback adjacecny done" << endl;
    number_of_vertices++;
    // cout << "number of vertices: " << number_of_vertices << endl;
}

// create K random unique edges for each vertex
template <typename T>
void Graph<T>::add_edges(int K)
{ // create K edges for each vertex
    // for (size_t i = 0; i < vertices->get_size(); i++)
    // {
    //     cout << "Vertex " << i << " point" << endl;
    //     get_vertex(i).point->display_vector();
    // }
    for (int i = 0; i < number_of_vertices; i++)
    {                                               // for each vertex
        //Vertex<T> *current_vertex = &get_vertex(i); // i is the id of current vertex
        // cout << "get current vertex " << endl;
        Vector<T> *current_point = get_vertex(i).point;
        // cout << "get current point" << endl;
        // cout << "current point: ";
        // current_point->display_vector();
        DLL<T> *current_list = &get_adjacent_list(i);
        // cout << "get current list " << endl;
        // current_list->print();
        // cout << &(current_vertex) << endl;
        // cout << "get current list" << endl;
        int edges_count = 0;
        while (edges_count < K)
        { // select K random numbers
            int random_vertex_id = generate_random_vertex_number(0, number_of_vertices - 1);
            // cout << "random vertex id: " << random_vertex_id << endl;
            // cout << "current vertex number: " << i << endl;
            //Vertex<T> *random_vertex = &get_vertex(random_vertex_id);

            Vector<T> *random_point = get_vertex(random_vertex_id).point;

            // cout << "get rendom vertex" << endl;
            //cout << "random vertex id: " << random_vertex_id << endl;
            DLL<T> *random_list = &get_adjacent_list(random_vertex_id);
            // cout << "get random list " << endl;

            // avoid self-connections and dublicate connections
            bool in_current_list = current_list->search(random_point);
            // cout << "search returns " << in_current_list << endl;
            // cout << "random point is ";
            // random_point->display_vector();
            // cout << "current_point is " ;
            // current_point->display_vector();
            if ((i != random_vertex_id) && in_current_list == false)
            {
                // cout << "vertex id:" << random_vertex_id << "random point is ";
                // random_point->display_vector();
                // cout << "vertex id:" << i << "current_point is ";
                // current_point->display_vector();
                // cout << "in random if " << endl;
                current_list->addFirst(*random_point, random_vertex_id);
                // random_list->addFirst(*current_point, i);

                edges_count++; // edge added
                // cout << "In vertex_id " << i << " added the " << random_vertex_id << endl;
            }
            // cout << "HERE " << endl;
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
            // cout << "Vertex " << i << " has " << list->size() << " neighbors" << endl;
            for (size_t j = 0; j < list->size(); j++) // for every neighbor
            {
                int id = list->getNode(j)->id;                  // get the id of every neighbor
                float distance = (&get_vertex(i))->point->euclideanDistance(*(list->getNode(j)->Data));
                // cout << "Distance " << distance << endl;
                DLL<T> *neighborsList = &get_adjacent_list(id); // get the list of neighbors
                for (size_t k = 0; k < neighborsList->size(); k++)
                {
                    // cout << "distance between " << (&get_vertex(i))->point->get_size() << " and " << neighborsList->getNode(k)->Data->get_size() << endl;
                    
                    // cout << "Distance " << distance << endl;
                    //    (&get_vertex(i))->point->display_vector();
                    //    cout << endl << "and" << endl;
                    //   neighborsList->getNode(k + 1)->Data->display_vector();
                    // cout << "distance between " << (&get_vertex(i))->point->get_size() << " and " << neighborsList->getNode(k+1)->Data->get_size() << endl;
                    float newDistance = (&get_vertex(i))->point->euclideanDistance(*(neighborsList->getNode(k)->Data));
                    //  cout << "New Distance " << newDistance << endl;


                    if (newDistance < distance && newDistance != 0 && distance != 0)
                    {   // update neighbors
                        // cout << "BEFORE" << endl;
                        if (list->search(neighborsList->getNode(k)->Data) == false)
                        {
                            // cout << "HAVE to change neighbor" << endl;
                            list->addBefore(list->getNext(j), *(neighborsList->getNode(k)->Data), neighborsList->getNode(k)->id);
                            list->remove(list->getNode(j));
                            // neighborsList->remove_by_id(get_vertex(i).id);
                            // get_adjacent_list(neighborsList->getNode(k)->id).addLast(*(neighborsList->getNode(k)->Data), neighborsList->getNode(k)->id);

                            // add neighbor of neighbor to current list of neighbors
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
        // return nullptr;
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
        cout << endl;
    }
}

template <typename T>
int Graph<T>::generate_random_vertex_number(int min, int max)
{   
    return min + rand() % (max - min + 1);
}