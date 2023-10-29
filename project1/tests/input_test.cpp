#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "input.hpp"


// check for correct input
TEST_CASE("Testing of the existence of an input file ", "[input]") {
  REQUIRE( read_binary_file("../project1/datasets/00000020.bin") == 0);      // file exists
}