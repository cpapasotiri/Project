#include "catch.hpp"
#include "vertex.hpp"

TEST_CASE("Vertex functionality tests", "[Vertex]")
{
  SECTION("Testing creation using default constructor")
  {
    Vertex<int> *vertex = new Vertex<int>(); 
    REQUIRE(vertex->id == 0);
    REQUIRE(vertex->point->get_size() == 0);
    delete vertex;
  }

  SECTION("Testing creation using copy constructor")
  {

  }

  SECTION("Testing creation using parameterized constructor")
  {
    Vector<int> *p = new Vector<int>();
    p->push_back(1);
    p->push_back(2);
    p->push_back(3);
    Vertex<int> *vertex = new Vertex<int>(11, p); 
    REQUIRE(vertex->id == 11);
    REQUIRE(vertex->point->get_size() == 3);
  }

  SECTION("Testing operator =")
  {

  }

  SECTION("Testing operator ==")
  {

  }

  SECTION("Testing destructor to delete ")
  {

  }
}