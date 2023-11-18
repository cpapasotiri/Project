#include "catch.hpp"
#include "graph.hpp"

TEST_CASE("Graph functionality tests", "[Graph]")
{
  Graph<int> graph;

  Vector<int> point0;
  point0.push_back(0);
  point0.push_back(1);

  Vector<int> point1;
  point1.push_back(1);
  point1.push_back(2);

  Vector<int> point2;
  point2.push_back(3);
  point2.push_back(4);

  SECTION("Testing created using constructor")
  {
    REQUIRE(graph.get_number_of_vertices() == 0);
  }

  SECTION("Testing destructor")
  { // TODO
   
  }

  SECTION("Testing added a vertex")
  {
    REQUIRE(graph.get_number_of_vertices() == 0);
    graph.add_vertex(&point1);
    REQUIRE(graph.get_number_of_vertices() == 1);
    graph.add_vertex(&point2);
    REQUIRE(graph.get_number_of_vertices() == 2);
  }

  SECTION("Testing added edges")
  { // TODO
   
  }

  SECTION("Testing K Nearest Neighbors for a given point")
  { // TODO
   
  }

  SECTION("Testing K Nearest Neighbors for all points")
  { // TODO
   
  }

  SECTION("Testing NNDescent")
  { // TODO

  }

  SECTION("Testing get number of vertices")
  {
    REQUIRE(graph.get_number_of_vertices() == 0);
  }

  SECTION("Testing get vertex by id")
  {
    graph.add_vertex(&point0);
    Vertex<int> vertex0 = graph.get_vertex(0);
    REQUIRE(vertex0.id == 0);

    graph.add_vertex(&point1);
    Vertex<int> vertex1 = graph.get_vertex(1);
    REQUIRE(vertex1.id == 1);

    graph.add_vertex(&point2);
    Vertex<int> vertex2 = graph.get_vertex(2);
    REQUIRE(vertex2.id == 2);
  }

  SECTION("Testing get adjacency list by id")
  { // TODO
    // graph.add_vertex(&point0);
    // graph.add_vertex(&point1);
    // graph.add_vertex(&point2);
    // DLL<int> list0 = graph.get_adjacent_list(0);
  }

  SECTION("Testing get adjacency list size")
  {
    graph.add_vertex(&point0);
    REQUIRE(graph.get_adjacent_list_size(0) == 0);
    graph.add_vertex(&point1);
    REQUIRE(graph.get_adjacent_list_size(1) == 0);
  }
}