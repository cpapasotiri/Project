#include "catch.hpp"
#include "DLL.hpp"

TEST_CASE("DLL functionality tests", "[DLL]")
{
  DLL<int> dll;
  Vector<int> v1;
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  Vertex<int> ver1(1, &v1);

  Vector<int> v2;
  v2.push_back(40);
  v2.push_back(50);
  v2.push_back(60);
  Vertex<int> ver2(2, &v2);

  SECTION("DLL size is initially zero")
  {
    REQUIRE(dll.size() == 0);
  }

  SECTION("DLL is empty") 
  {
    REQUIRE(dll.isEmpty() == true);
  }

  SECTION("Adding elements to DLL increases size")
  {
    dll.addFirst(ver1);
    REQUIRE(dll.size() == 1);

    dll.addLast(ver2);
    REQUIRE(dll.size() == 2);
  }

  SECTION("Adding element to DLL in specific position")
  { // TODO
    // dll.addAfter();
    // dll.addBefore();
  }

  SECTION("Getting elements from DLL")
  {
    dll.addFirst(ver1);
    dll.addLast(ver2);
    dll.addLast(ver2);

    REQUIRE(dll.getNode(1) == dll.getNext(0));
    REQUIRE(dll.getPrevious(1) == dll.getNode(0));
  }

  SECTION("Remove elements from DLL decreases size")
  {
    dll.addFirst(ver1);
    dll.addLast(ver2);

    dll.remove(dll.getFirst());
    REQUIRE(dll.size() == 1);

    dll.remove(dll.getLast());
    REQUIRE(dll.size() == 0);
  }

  SECTION("Remove element by id from DLL decreases size")
  {
    dll.addFirst(ver1);
    dll.addLast(ver2);

    dll.remove_by_id(1);
    REQUIRE(dll.search(&ver2) == true);
  }
}