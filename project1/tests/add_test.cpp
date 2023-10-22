#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "add.hpp"

TEST_CASE("Addition testing", "[addition]") {
  REQUIRE( add(1, 2) == 3);
  REQUIRE( add(200, 34) == 234 );
  REQUIRE( add(1234, 5678) == 6912);
}