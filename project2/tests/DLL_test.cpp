#include "catch.hpp"
#include "DLL.hpp"

TEST_CASE("DLL functionality tests", "[DLL]")
{
  DLL<int> dll;
  Vertex<int> ver1, ver2;
  // dll.addFirst(ver1);
  // dll.addFirst(ver2);

  SECTION("DLL size is initially zero")
  {
    REQUIRE(dll.size() == 0);
  }

  SECTION("Adding elements to DLL increases size")
  {
    dll.addFirst(ver1);
    REQUIRE(dll.size() == 1);

    dll.addLast(ver2);
    REQUIRE(dll.size() == 2);
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
}