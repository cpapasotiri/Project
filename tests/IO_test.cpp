#include "catch.hpp"
#include "IO.hpp"

TEST_CASE("IO functionality tests", "[IO]"){
    size_t len = 255;
    SECTION("Testing create output filepath using datasets/2dims.bin inputFile")
    {
        char outputPath[len];
        create_output_filepath("datasets/2dims.bin", "e", outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_e.bin") == 0);
    }

    SECTION("Testing create output filepath using datasets/00000020.bin inputFile")
    {
        char outputPath[len];
        create_output_filepath("datasets/00000020.bin", "m", outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/00000020_m.bin") == 0);
    }

    SECTION("Testing create output filepath using 2dims.bin inputFile")
    {
        char outputPath[len];
        create_output_filepath("2dims.bin", "m", outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_m.bin") == 0);
    }

    SECTION("Testing create output filepath using include/2dims.bin inputFile")
    {
        char outputPath[len];
        create_output_filepath("include/2dims.bin", "e", outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_e.bin") == 0);
    }
}