#include "catch.hpp"
#include "IO.hpp"

TEST_CASE("IO functionality tests", "[IO]"){
    SECTION("Directory creation", "[create_directory]")
    {
        const char* dirpath = "test_directory";
        REQUIRE(create_directory(dirpath) == true);
    }

    SECTION("Try to create an existing directory", "[create_directory]")
    {
        const char* dirpath = "test_directory";
        REQUIRE(create_directory(dirpath) == true);     // first try to create
        REQUIRE(create_directory(dirpath) == true);     // second try to create the same directory
    }

    SECTION("Create output filepath using datasets/2dims.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "e";
        char filepath[19] = "datasets/2dims.bin";
        create_output_filepath(filepath, distance, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_neighbors_e.bin") == 0);
    }

    SECTION("Create output filepath using datasets/00000020.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "m";
        char filepath[22] = "datasets/00000020.bin";
        create_output_filepath(filepath, distance, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/00000020_neighbors_m.bin") == 0);
    }

    SECTION("Create output filepath using 2dims.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "m";
        char filepath[10] = "2dims.bin";
        create_output_filepath(filepath, distance, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_neighbors_m.bin") == 0);
    }

    SECTION("Create output filepath using include/2dims.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "e";
        char filepath[18] = "include/2dims.bin";
        create_output_filepath(filepath, distance, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_neighbors_e.bin") == 0);
    }

    SECTION("Open & close filepath", "[open_filepath close_filepath]")
    {
        const char* filepath = "datasets/2dims.bin";
        int file = open_filepath(filepath, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        REQUIRE(file != -1);
        close_filepath(file);
    }

    SECTION("Read from filepath", "[read_from_filepath]")
    {
        const char* filepath = "datasets/2dims.bin";
        int file = open_filepath(filepath, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        REQUIRE(file != -1);
        uint32_t N;
        REQUIRE(read_from_filepath(file, &N, sizeof(uint32_t)) == sizeof(uint32_t));
        REQUIRE(N == 40);
        close_filepath(file);
    }

    SECTION("Write to filepath", "[write_to_filepath]")
    {
        const char* filepath = "test_write.bin";
        int file = open_filepath(filepath, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        REQUIRE(file != -1);
        uint32_t N = 40;
        REQUIRE(write_to_filepath(file, &N, sizeof(uint32_t)) == sizeof(uint32_t));
        close_filepath(file);
        remove(filepath);
    }
}