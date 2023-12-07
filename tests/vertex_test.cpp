#include "catch.hpp"
#include "vertex.hpp"

TEST_CASE("Vertex functionality tests", "[Vertex]")
{
  SECTION("Testing creation using default constructor")
  {
    Vertex<int> vertex;
    REQUIRE(vertex.id == 0);
    REQUIRE(vertex.point->get_size() == 0);
  }

  SECTION("Testing creation using copy constructor")
  {

  }

  Vector<int> point1;
  point1.push_back(1);
  point1.push_back(2);
  point1.push_back(3); 

  Vector<int> point2;
  point2.push_back(2);
  point2.push_back(3);
  point2.push_back(4);

  SECTION("Testing creation using parameterized constructor")
  {
    Vertex<int> vertex(11, &point1); 
    REQUIRE(vertex.id == 11);
    REQUIRE(vertex.point->get_size() == 3);
  }
  
  SECTION("Testing operator ==")
  {
    REQUIRE(point1.operator==(point1) == true);
    REQUIRE(point1.operator==(point2) == false);
  }

  SECTION("Testing operator =")
  { // TODO or change or delete operator= implementation 
    // point1.operator=(point2);
    // REQUIRE(point1.operator==(point2) == true);
  }

  SECTION("Testing destructor to delete ")
  {

  }
}