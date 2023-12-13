#include "catch.hpp"
#include "graph.hpp"

TEST_CASE("Graph functionality tests", "[Graph]")
{
  char distance[2] = "e";
  Graph<int> graph(distance);

  Vector<int> point0;
  point0.push_back(0);
  point0.push_back(1);

  Vector<int> point1;
  point1.push_back(2);
  point1.push_back(3);

  Vector<int> point2;
  point2.push_back(4);
  point2.push_back(5);

  Vector<int> point3;
  point3.push_back(6);
  point3.push_back(7);

  Vector<int> point4;
  point4.push_back(8);
  point4.push_back(9);

  Vector<int> point5;
  point5.push_back(10);
  point5.push_back(11);

  Vector<int> point6;
  point6.push_back(12);
  point6.push_back(13);

  Vector<int> point7;
  point7.push_back(14);
  point7.push_back(15);

  Vector<int> point8;
  point8.push_back(16);
  point8.push_back(17);

  Vector<int> point9;
  point9.push_back(18);
  point9.push_back(19);

  Vector<int> point10;
  point10.push_back(20);
  point10.push_back(21);

  Vector<int> point11;
  point11.push_back(22);
  point11.push_back(23);

  Vector<int> point12;
  point12.push_back(24);
  point12.push_back(25);

  Vector<int> point13;
  point13.push_back(26);
  point13.push_back(27);

  Vector<int> point14;
  point14.push_back(28);
  point14.push_back(29);

  Vector<int> point15;
  point15.push_back(30);
  point15.push_back(31);

  SECTION("Testing created using constructor")
  {
    REQUIRE(graph.get_number_of_vertices() == 0);
  }

  SECTION("Testing destructor")
  { // TODO
  }

  SECTION("Add vertices and add edges")
  {
    int vertices = graph.get_number_of_vertices();
    REQUIRE(vertices == 0);
    graph.add_vertex(&point0);
    graph.add_vertex(&point1);
    graph.add_vertex(&point2);
    graph.add_vertex(&point3);
    graph.add_vertex(&point4);
    graph.add_vertex(&point5);
    graph.add_vertex(&point6);
    graph.add_vertex(&point7);
    graph.add_vertex(&point8);
    graph.add_vertex(&point9);
    graph.add_vertex(&point10);
    graph.add_vertex(&point11);
    graph.add_vertex(&point12);
    graph.add_vertex(&point13);
    graph.add_vertex(&point14);
    graph.add_vertex(&point15);
    vertices = graph.get_number_of_vertices();
    REQUIRE(vertices == 16);

    int K = 2;
    graph.add_edges(K);
    for (int i = 0; i < vertices; i++)
    {
      REQUIRE(graph.get_neighbors_list_size(i) == K);
    }

    // TODO - check if reverse list are correct
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

  SECTION("Testing get neighbors list by id")
  { // TODO
    // graph.add_vertex(&point0);
    // graph.add_vertex(&point1);
    // graph.add_vertex(&point2);
    // DLL<int> list0 = graph.get_neighbors_list(0);
  }

  SECTION("Testing get reverse neighbors list by id")
  { // TODO
    // DLL<int> list0 = graph.get_neighbors_list(0);
  }

  SECTION("Testing get neighbors list size")
  {
    graph.add_vertex(&point0);
    REQUIRE(graph.get_neighbors_list_size(0) == 0);
    graph.add_vertex(&point1);
    REQUIRE(graph.get_neighbors_list_size(1) == 0);
  }

  SECTION("Testing get reverse neighbors list size")
  { // TODO
    graph.add_vertex(&point0);
    REQUIRE(graph.get_reverseNeighbors_list_size(0) == 0);
  }

  SECTION("Testing store neighbors in file")
  { // TODO
  
  }

  SECTION("Testing compare neighbors from file")
  { // TODO
  
  }
}