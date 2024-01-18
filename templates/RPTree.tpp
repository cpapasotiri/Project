// RPTree.tpp
#include "RPTree.hpp"
#include <cstdlib>
#include <cmath>

template <typename T>
RPTreeNode<T>::RPTreeNode() : points(nullptr), left_child(nullptr), right_child(nullptr){};
// RPTreeNode implementation
template <typename T>
RPTreeNode<T>::RPTreeNode(Vector<Vector<T>> *p) : points(p), left_child(nullptr), right_child(nullptr) {}

template <typename T>
RPTreeNode<T>::~RPTreeNode()
{
    // delete points;
    //   delete left_child;
    //   delete right_child;
}

template <typename T>
void RPTreeNode<T>::printData()
{
    for (int i = 0; i < points->get_size(); i++)
    {
        points->operator[](i).display_vector();
    }
}

// RPTree implementation
template <typename T>
RPTree<T>::RPTree() : root(nullptr) {}

template <typename T>
RPTree<T>::~RPTree()
{
    // delete root;
}

template <typename T>
void buildTreeRecursive(RPTreeNode<T> *&current_node, Vector<Vector<T>> &data, int D, Vector<RPTreeNode<T>> *resultNodes)
{

    if (data.get_size() == 0 || data.get_size() == 1)
    {
        return;
    }

    current_node = new RPTreeNode<T>(&data);

    if (current_node->points->get_size() <= D && (current_node->points->get_size() != 0 || current_node->points->get_size() != 1))
    {
        // Handle leaf node
        resultNodes->push_back(*current_node);
        return;
    }

    // Randomly choose a vector for the hyperplane
    Vector<T> hyperplane;
    for (int i = 0; i < data[0].get_size(); i++)
    {
        hyperplane.push_back(static_cast<T>(rand()) / 1000);
    }

    // Normalize the hyperplane vector
    T norm = 0;
    for (int i = 0; i < hyperplane.get_size(); i++)
    {
        norm += hyperplane[i] * hyperplane[i];
    }
    norm = sqrt(norm);

    for (int i = 0; i < hyperplane.get_size(); i++)
    {
        hyperplane[i] /= norm;
    }

    float c = static_cast<T>(rand() / (norm * D));

    // Split the data points into two subsets
    Vector<Vector<T>> left_subset, right_subset;

    for (int j = 0; j < data.get_size(); j++)
    {
        Vector<T> point = data[j];
        float dotProduct = 0;

        if (hyperplane.get_size() != point.get_size())
        {
            perror("The hyperplane must have the same dimensions as the points!");
            exit(1);
        }
        else
        {
            for (int k = 0; k < point.get_size(); k++)
            {
                dotProduct += hyperplane[k] * point[k];
            }
        }

        if (dotProduct <= c)
        {
            left_subset.push_back(point);
        }
        else
        {
            right_subset.push_back(point);
        }
    }

    if (left_subset.get_size() == 0 || right_subset.get_size() == 0)
    {
        return;
    }

    // Recursively build the left and right children
    buildTreeRecursive(current_node->left_child, left_subset, D, resultNodes);
    buildTreeRecursive(current_node->right_child, right_subset, D, resultNodes);

    for (size_t i = 0; i < resultNodes->get_size(); i++)
    {
        cout << "RPTree result nodes size in Recursive = " << resultNodes->operator[](i).points->get_size() << endl;
    }

    return;
}

template <typename T>
void RPTree<T>::buildTree(Vector<Vector<T>> &data, int D, Vector<RPTreeNode<T>> *resultNodes)
{
    Vector<RPTreeNode<T>> *returnNodes = new Vector<RPTreeNode<T>>();
    buildTreeRecursive(root, data, D, returnNodes);

    for (int i = 0; i < returnNodes->get_size(); i++)
    {
        cout << "RPTree nodes size in BuildTree = " << returnNodes->operator[](i).points->get_size() << endl;
        if (returnNodes->operator[](i).points->get_size() <= D && returnNodes->operator[](i).points->get_size() != 0 && returnNodes->operator[](i).points->get_size() != 1)
        {
            resultNodes->push_back(returnNodes->operator[](i));
        }
    }

    delete returnNodes;
}
