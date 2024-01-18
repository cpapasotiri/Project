#include "catch.hpp"
#include "RPTree.hpp"
#include "vector.hpp"
#include <cstdlib>
#include <time.h>

TEST_CASE("RPTree buildTree function", "[RPTree]")
{
    SECTION("Build function")
    {
    // srand(time(nullptr));
    // // Create a dataset for testing
    // Vector<Vector<float>> dataset;
    // Vector<Vector<float>> *data = &dataset;
    
    // for (int i = 0; i < 10; i++)
    // {   
    //     Vector<float> v;
    //     for (int j = 0; j < 5; j++)
    //     {
    //         v.push_back((float)(rand() % 10));
    //     }
    //     dataset.push_back(v);
    // }
    // srand(time(nullptr));
    // // Create an RPTree
    // RPTree<float> tree;

    // // Build the tree
    // RPTreeNode<float> *root = tree.buildTree(*data, 2);

    // // Add more assertions based on the expected behavior of your tree
    // REQUIRE(root->points->get_size() <= 2);
    // // Clean up
    // //delete root;
    }
}