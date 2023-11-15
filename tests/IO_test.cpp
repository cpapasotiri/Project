#include "catch.hpp"
#include "IO.hpp"

TEST_CASE("IO functionality tests", "[IO]")
{
  SECTION("Testing create output filepath")
  {
    char outputPath[22];
    // create_output_filepath("datasets/2dims.bin", "e", outputPath, sizeof(outputPath));
    REQUIRE(strcmp(outputPath, "output/2dims_e.bin") == 0);
    create_output_filepath("datasets/2dims.bin", "m", outputPath, sizeof(outputPath));
    REQUIRE(strcmp(outputPath, "output/2dims_m.bin") == 0);
  }
}