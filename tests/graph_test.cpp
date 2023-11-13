#include "catch.hpp"
#include "graph.hpp"

TEST_CASE("Graph functionality tests", "[Graph]")
{
  SECTION("Testing created using constructor")
  {
    Graph<int> *graph = new Graph<int>();
    REQUIRE(graph->get_number_of_vertices() == 0);
    delete graph;
  }

  SECTION("Testing destructor")
  {
   
  }

  SECTION("Testing added a vertex")
  {
    Graph<int> *graph = new Graph<int>();
    Vector<int> *point1 = new Vector<int>();
    point1->push_back(1);
    point1->push_back(2);
    Vector<int> *point2 = new Vector<int>();
    point2->push_back(3);
    point2->push_back(4);

    REQUIRE(graph->get_number_of_vertices() == 0);
    graph->add_vertex(point1);
    REQUIRE(graph->get_number_of_vertices() == 1);
    graph->add_vertex(point2);
    REQUIRE(graph->get_number_of_vertices() == 2);
    delete graph;
  }

  SECTION("Testing added edges")
  {
   
  }

  SECTION("Testing K Nearest Neighbors for a given point")
  {
   
  }

  SECTION("Testing K Nearest Neighbors for all points")
  {
   
  }

  SECTION("Testing NNDescent")
  {

  }

  SECTION("Testing get number of vertices")
  {
    Graph<int> *graph = new Graph<int>();
    REQUIRE(graph->get_number_of_vertices() == 0);
    delete graph;
  }

  SECTION("Testing get vertex by id")
  {
    Graph<int> *graph = new Graph<int>();
    Vector<int> *point0 = new Vector<int>();
    point0->push_back(0);
    point0->push_back(1);
    graph->add_vertex(point0);
    Vector<int> *point1 = new Vector<int>();
    point1->push_back(1);
    point1->push_back(2);
    graph->add_vertex(point1);
    Vector<int> *point2 = new Vector<int>();
    point2->push_back(2);
    point2->push_back(3);
    graph->add_vertex(point2);
    Vertex<int> *vertex0 = &graph->get_vertex(0);
    Vertex<int> *vertex1 = &graph->get_vertex(1);
    Vertex<int> *vertex2 = &graph->get_vertex(2);
    REQUIRE(vertex0->id == 0);
    REQUIRE(vertex1->id == 1);
    REQUIRE(vertex2->id == 2);
    delete graph;
  }

  SECTION("Testing get adjacency list by id")
  {
    
  }

  SECTION("Testing get adjacency list size")
  {
    
  }

  SECTION("Testing display")
  {
    
  }
}