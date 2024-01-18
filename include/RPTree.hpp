#pragma once

#include "vector.hpp"
#include "vertex.hpp"

template <typename T>
class RPTreeNode
{
public:
    Vector<Vector<T>> *points; //The points in this node
    RPTreeNode<T> *left_child;  // Left child
    RPTreeNode<T> *right_child; // Right child

    RPTreeNode();
    RPTreeNode(Vector<Vector<T>> *p);
    ~RPTreeNode();
    void printData();
};

template <typename T>
class RPTree
{
public:
    RPTreeNode<T> *root;

    RPTree();
    ~RPTree();

    void buildTree(Vector<Vector<T>> &data, int D, Vector<RPTreeNode<T>> *resultNodes);
};

#include "../templates/RPTree.tpp"
