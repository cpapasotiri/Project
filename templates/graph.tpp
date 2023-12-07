#include <iostream>
#include <cmath>
#include "graph.hpp"
#include "IO.hpp"

using namespace std;

template <typename T>
Pair<T>::Pair(float dist, Vertex<T> &vertex) : distance(dist), v(new Vertex<T>(vertex))
{
}

template <typename T>
Pair<T>::Pair() : distance(0), v(new Vertex<T>())
{
}

template <typename T>
Pair<T>::~Pair()
{
}

template <typename T>
Graph<T>::Graph(char *distance)
{
    number_of_vertices = 0;
    vertices = new Vector<Vertex<T>>();
    neighbors_list = new Vector<DLL<T>>();
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
    delete neighbors_list;
}

// save vertex to vector and create a adjacency list for its neighbors
template <typename T>
void Graph<T>::add_vertex(Vector<T> *p)
{
    Vertex<T> *vertex = new Vertex<T>(number_of_vertices, p);
    vertices->push_back(*vertex);
    DLL<T> *list = new DLL<T>();
    neighbors_list->push_back(*list);
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
        DLL<T> *current_list = &get_neighbors_list(i);
        Vertex<T> *current_vertex = &get_vertex(i);
        int current_id = get_vertex(i).id;

        int edges_count = 0;
        while (edges_count < K)
        { // select K random numbers
            int random_vertex_id = generate_random_vertex_number(0, number_of_vertices - 1);

            DLL<T> *random_list = &get_neighbors_list(random_vertex_id);

            // avoid self-connections and dublicate connections
            bool in_current_list = current_list->search(&get_vertex(random_vertex_id));
            if ((current_id != random_vertex_id) && in_current_list == false)
            {
                current_list->addFirst(get_vertex(random_vertex_id));
                current_list->getNodeById(random_vertex_id)->flag = true; // flag of vertex initially inserting in list is true
                random_list->addFirst(*current_vertex);
                random_list->getNodeById(current_vertex->id)->flag = true; // flag of vertex initially inserting in list as reversed neighbor is true
                edges_count++;                                             // edge added
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
            return get_neighbors_list(i);
        }
    }
}

template <typename T>
Vector<DLL<T>> &Graph<T>::K_NN()
{
    return neighbors_list;
}

template <typename T>
void Graph<T>::NNDescent(int K)
{
    Vector<Pair<T>> *pairs;
    // Υλοποίηση του 1ου παραδοτέου
    // Pair<T> *p2;
    // int count = -1;
    // while (count != 0)
    Pair<T> *p1;
    DLL<T> *list;
    int count = 20;
    while (count > 10)
    { // loop stops when the graph isn't changed
        count = 0;
        for (int i = 0; i < number_of_vertices; i++)
        { // for every vertex
            pairs = new Vector<Pair<T>>();
            list = &get_neighbors_list(i);         // get the list of neighbors
            for (int j = 0; j < list->size(); j++) // for every neighbor
            {
                int id = list->getNode(j)->Data->id; // get the id of every neighbor
                float distance = ((&get_vertex(i))->point->*distance_function)(*(list->getNode(j)->Data->point));
                if (distance != 0.0)
                {
                    p1 = new Pair<T>(distance, *(list->getNode(j)->Data));
                    pairs->push_back(*p1);
                }

                DLL<T> *neighborsListOfj = &get_neighbors_list(id);
                for (int k = 0; k < list->size(); k++)
                {
                    int id2 = list->getNode(k)->Data->id;
                    DLL<T> *neighborsListOfk = &get_neighbors_list(id2);
                    if ((list->getNodeById(id)->flag == true || list->getNodeById(id2)->flag == true) && (id != id2))
                    {

                        float d1 = (list->getNodeById(id)->Data->point->*distance_function)(*(list->getNodeById(id2)->Data->point));
                        for (int counter1 = 0; counter1 < neighborsListOfj->size(); counter1++)
                        {
                            float d2 = (list->getNodeById(id)->Data->point->*distance_function)(*(neighborsListOfj->getNode(counter1)->Data->point));
                            if (d1 < d2 && d2 != 0)
                            {
                                int counterId = neighborsListOfj->getNode(counter1)->Data->id;
                                if (neighborsListOfj->search(list->getNodeById(id2)->Data) == false)
                                {
                                    neighborsListOfj->addBefore(neighborsListOfj->getNodeById(counterId), *list->getNodeById(id2)->Data);
                                }
                            }
                        }

                        d1 = (list->getNodeById(id2)->Data->point->*distance_function)(*(list->getNodeById(id)->Data->point));
                        for (int counter2 = 0; counter2 < neighborsListOfk->size(); counter2++)
                        {
                            float d2 = (list->getNodeById(id2)->Data->point->*distance_function)(*(neighborsListOfk->getNode(counter2)->Data->point));
                            if (d1 < d2 && d2 != 0)
                            {
                                int counterId = neighborsListOfk->getNode(counter2)->Data->id;
                                if (neighborsListOfk->search(list->getNodeById(id)->Data) == false)
                                {
                                    neighborsListOfk->addBefore(neighborsListOfk->getNodeById(counterId), *list->getNodeById(id)->Data);
                                }
                            }
                        }
                        list->getNodeById(id)->flag = false; // Change the flag of the vertex after Local Join
                        list->getNodeById(id2)->flag = false;
                    }
                }
            }

            //     // Υλοποίηση του 1ου παραδοτέου με γείτονες γειτόνων του current vertex
            //     DLL<T> *neighborsList = &get_neighbors_list(id); // get the list of neighbors
            //     for (int k = 0; k < neighborsList->size(); k++)
            //     {
            //         if (list->search(neighborsList->getNode(k)->Data) == false)
            //         {
            //             float newDistance = ((&get_vertex(i))->point->*distance_function)(*(neighborsList->getNode(k)->Data->point));
            //             if (newDistance != 0.0)
            //             {
            //                 p2 = new Pair<T>(newDistance, *(neighborsList->getNode(k)->Data));
            //                 pairs->push_back(*p2);
            //             }
            //         }
            //     }
            // }

            for (size_t t = 0; t < pairs->get_size(); t++)
            { // sort pairs by distance
                for (size_t k = 0; k < pairs->get_size() - t - 1; k++)
                {
                    if (pairs->operator[](k).distance > pairs->operator[](k + 1).distance)
                    {
                        float temp = pairs->operator[](k).distance;
                        Vertex<T> *tempVertex = pairs->operator[](k).v;

                        pairs->operator[](k).distance = pairs->operator[](k + 1).distance;
                        pairs->operator[](k).v = pairs->operator[](k + 1).v;
                        pairs->operator[](k + 1).distance = temp;
                        pairs->operator[](k + 1).v = tempVertex;
                    }
                }

                Vector<Vertex<T>> *nearestNeighbors = new Vector<Vertex<T>>();

                for (int counter = 0; counter < K; counter++)
                {
                    if (list->search(pairs->operator[](counter).v) == false)
                    {
                        list->addFirst(*(pairs->operator[](counter).v));
                        nearestNeighbors->push_back(*(pairs->operator[](counter).v));
                        count++;
                    }
                    else
                    {
                        nearestNeighbors->push_back(*(pairs->operator[](counter).v));
                    }
                }
                if (list->size() > K)
                {
                    for (int rm = 0; rm < list->size(); rm++)
                    {
                        int idToRm = list->getNode(rm)->Data->id;
                        if (nearestNeighbors->contains(*(list->getNodeById(idToRm)->Data)) == false)
                        {
                            list->remove(list->getNodeById(idToRm));
                            count++;
                        }
                    }
                }

                delete nearestNeighbors;
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
DLL<T> &Graph<T>::get_neighbors_list(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid adjacency list id" << endl;
    }
    return neighbors_list->operator[](id);
}

template <typename T>
int Graph<T>::get_neighbors_list_size(int id) const
{
    if (id > number_of_vertices || id < 0)
    {
        cerr << "Invalid adjacency list id" << endl;
    }
    return neighbors_list->operator[](id).size();
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
        neighbors_list->operator[](i).print();
        cout << endl
             << endl;
    }
}

template <typename T>
int Graph<T>::generate_random_vertex_number(int min, int max)
{
    return min + rand() % (max - min + 1);
}

template <typename T>
void Graph<T>::bruteForce(int K)
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
            for (size_t k = 0; k < pairs->get_size() - t - 1; k++)
            {
                if (pairs->operator[](k).distance > pairs->operator[](k + 1).distance)
                {
                    float temp = pairs->operator[](k).distance;
                    Vertex<T> *tempVertex = pairs->operator[](k).v;

                    pairs->operator[](k).distance = pairs->operator[](k + 1).distance;
                    pairs->operator[](k).v = pairs->operator[](k + 1).v;
                    pairs->operator[](k + 1).distance = temp;
                    pairs->operator[](k + 1).v = tempVertex;
                }
            }
        }

        for (int count = 0; count < K; count++)
        { // insert the first K pairs into the adjacency list & write vertex into file
            int id = get_vertex(i).id;
            neighbors_list->operator[](id).addLast(*(pairs->operator[](count).v));
            // write_to_filepath(fd, pairs->operator[](count).v, sizeof(pairs->operator[](count).v));
        }
        delete pairs;
    }
    delete p;
}

template <typename T>
int Graph<T>::store_neighbors(int fd)
{
    for (size_t i = 0; i < neighbors_list->get_size(); i++)
    { // for every vertex
        // cout << "Vertex " << i << endl;
        DLL<T> *neighbors = &get_neighbors_list(i);
        for (int j = 0; j < neighbors->size(); j++)
        { // for every neighbor write vertex into file
            // Write vertex id
            Vertex<T> *vertex = neighbors->getNode(j)->Data;
            int id = vertex->id;
            if (write_to_filepath(fd, &id, sizeof(int)) != sizeof(int))
            {
                cerr << "Error writing ID to file" << endl;
                return -1;
            }
            // cout << "wrote id = " << id << endl;

            // Write vector size
            size_t vector_size = vertex->point->get_size();
            if (write_to_filepath(fd, &vector_size, sizeof(size_t)) != sizeof(size_t))
            {
                cerr << "Error writing vector size to file" << endl;
                return -1;
            }
            // cout << "Vector size: " << vector_size << endl;

            // Write vector elements
            for (size_t k = 0; k < vector_size; k++)
            {
                float element = vertex->point->operator[](k);
                if (write_to_filepath(fd, &element, sizeof(float)) != sizeof(float))
                {
                    cerr << "Error writing vector data to file" << endl;
                    return -1;
                }
                // cout << "element = " << element << endl;
            }
            // cout << endl;
        }
    }
    return 0;
}

template <typename T>
int Graph<T>::compare_neighbors(int fd)
{
    int found = 0;
    int count_vertices = 0;
    for (int i = 0; i < number_of_vertices; i++)
    { // for every vertex
        DLL<T> *neighbors = &get_neighbors_list(i);
        // cout << "vertex " << i << endl;
        for (int k = 0; k < neighbors->size(); k++)
        {
            // Read vertex id
            int id;
            if (read_from_filepath(fd, &id, sizeof(int)) != sizeof(int))
            {
                cerr << "Error reading ID from file" << endl;
                return -1;
            }
            // cout << "read id = " << id << endl;

            // Read vector size
            size_t vector_size;
            if (read_from_filepath(fd, &vector_size, sizeof(size_t)) != sizeof(size_t))
            {
                cerr << "Error reading vector size from file" << endl;
                return -1;
            }
            // cout << "vector_size = " << vector_size << endl;

            // Read vector elements
            Vector<float> *vector = new Vector<float>();
            for (size_t j = 0; j < vector_size; j++)
            {
                float vector_element;
                if (read_from_filepath(fd, &vector_element, sizeof(float)) != sizeof(float))
                {
                    cerr << "Error reading vector eleement from file" << endl;
                    return -1;
                }
                vector->push_back(vector_element);
                // cout << "element = " << vector_element << endl;
            }
            // cout << endl;
            Vertex<T> *vertex = new Vertex<T>(id, vector);
            count_vertices++;
            // search for vertex and increase found counter if found
            if (neighbors->search(vertex) == true)
            {
                found++;
            }
            delete vertex;
            delete vector;
        }
    }

    cout << "count of vertices = " << count_vertices << endl;
    cout << "found = " << found << endl;

    int success = ((float)found / (float)count_vertices) * 100;
    return success;
}