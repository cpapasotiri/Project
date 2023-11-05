#include "../include/catch.hpp"
#include "../include/DLL.hpp"

TEST_CASE("DLL functionality tests", "[DLL]")
{
  DLL<int> dll;
  Vector<int> vec1, vec2;
  vec1.push_back(1);
  vec1.push_back(2);
  vec2.push_back(3);
  vec2.push_back(4);

  SECTION("DLL size is initially zero")
  {
    REQUIRE(dll.size() == 0);
  }

  SECTION("Adding elements to DLL increases size")
  {
    dll.addFirst(vec1);
    REQUIRE(dll.size() == 1);

    dll.addLast(vec2);
    REQUIRE(dll.size() == 2);
  }

  SECTION("Getting elements from DLL")
  {
    dll.addFirst(vec1);
    dll.addLast(vec2);
    dll.addLast(vec2);

    REQUIRE(dll.getNode(1) == dll.getNext(0));
    REQUIRE(dll.getPrevious(1) == dll.getNode(0));
  }

  SECTION("Remove elements from DLL decreases size")
  {
    dll.addFirst(vec1);
    dll.addLast(vec2);

    dll.remove(dll.getFirst());
    REQUIRE(dll.size() == 1);

    dll.remove(dll.getLast());
    REQUIRE(dll.size() == 0);
  }
}
