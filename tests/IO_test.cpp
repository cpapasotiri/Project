#include "catch.hpp"
#include "IO.hpp"

TEST_CASE("IO functionality tests", "[IO]"){
    SECTION("Valid input for brute_force - 5 arguments") 
    {
        char* dummy_argv[] = {(char*)"./brute_force", (char*)"datasets/2dims.bin", (char*)"2", (char*)"2", (char*)"e"};
        char input_filepath[256], distance[2];
        int dimensions, K, delta = 0;
        float p = 0.0;
        REQUIRE(main_args_validator(5, dummy_argv, input_filepath, &dimensions, &K, distance, &delta, &p) == 0);
        // Add additional REQUIRE statements to validate the expected values
        REQUIRE(strcmp(input_filepath, "datasets/2dims.bin") == 0);
        REQUIRE(dimensions == 2);
        REQUIRE(K == 2);
        REQUIRE(strcmp(distance, "e") == 0);
        // not used here
        REQUIRE(delta == 0);
        REQUIRE(p == (float)0.0);
    }

    SECTION("Valid input for project - 7 arguments") 
    {
        char* dummy_argv[] = {(char*)"./project", (char*)"datasets/2dims.bin", (char*)"3", (char*)"3", (char*)"e", (char*)"5", (char*)"0.1"};
        char input_filepath[256], distance[2];
        int dimensions, K, delta = 0;
        float p = 0.0;
        REQUIRE(main_args_validator(7, dummy_argv, input_filepath, &dimensions, &K, distance, &delta, &p) == 0);
        // Add additional REQUIRE statements to validate the expected values
        REQUIRE(strcmp(input_filepath, "datasets/2dims.bin") == 0);
        REQUIRE(dimensions == 3);
        REQUIRE(K == 3);
        REQUIRE(strcmp(distance, "e") == 0);
        REQUIRE(delta == 5);
        REQUIRE(p == (float)0.1);
    }

    SECTION("Invalid number of arguments - 4 arguments") 
    {
        char* dummy_argv[] = {(char*)"./brute_force", (char*)"datasets/2dims.bin", (char*)"2", (char*)"2"};
        char input_filepath[256], distance[2];
        int dimensions, K, delta = 0;
        float p = 0;
        REQUIRE(main_args_validator(4, dummy_argv, input_filepath, &dimensions, &K, distance, &delta, &p) == -1);
    }

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
        int K = 2;
        char filepath[19] = "datasets/2dims.bin";
        create_output_filepath(filepath, distance, K, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_2_e.bin") == 0);
    }

    SECTION("Create output filepath using datasets/2dims.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "e";
        int K = 4;
        char filepath[19] = "datasets/2dims.bin";
        create_output_filepath(filepath, distance, K, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_4_e.bin") == 0);
    }

    SECTION("Create output filepath using datasets/00000020.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "m";
        char filepath[22] = "datasets/00000020.bin";
        int K = 10;
        create_output_filepath(filepath, distance, K, outputPath, sizeof(outputPath));
        cout << outputPath << endl;
        REQUIRE(strcmp(outputPath, "output/00000020_10_m.bin") == 0);
    }

    SECTION("Create output filepath using 2dims.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "m";
        char filepath[10] = "2dims.bin";
        int K = 5;
        create_output_filepath(filepath, distance, K, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_5_m.bin") == 0);
    }

    SECTION("Create output filepath using include/2dims.bin inputFile")
    {
        char outputPath[256];
        char distance[2] = "e";
        char filepath[18] = "include/2dims.bin";
        int K = 2;
        create_output_filepath(filepath, distance, K, outputPath, sizeof(outputPath));
        REQUIRE(strcmp(outputPath, "output/2dims_2_e.bin") == 0);
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

    SECTION("Calculate the length of an integer", "[get_int_len]")
    {
        REQUIRE(get_int_len(0) == 1);
        REQUIRE(get_int_len(1) == 1);
        REQUIRE(get_int_len(10) == 2);
        REQUIRE(get_int_len(15) == 2);
        REQUIRE(get_int_len(100) == 3);
        REQUIRE(get_int_len(1000) == 4);
        REQUIRE(get_int_len(10000) == 5);
        REQUIRE(get_int_len(100000) == 6);
        REQUIRE(get_int_len(1000000) == 7);
        REQUIRE(get_int_len(10000000) == 8);
        REQUIRE(get_int_len(100000000) == 9);
        REQUIRE(get_int_len(1000000000) == 10);
    }

    SECTION("Convert integer to string", "[int_to_str]")
    {
        char str[11];
        int_to_str(0, str, 1);
        REQUIRE(strcmp(str, "0") == 0);
        int_to_str(1, str, 1);
        REQUIRE(strcmp(str, "1") == 0);
        int_to_str(10, str, 2);
        REQUIRE(strcmp(str, "10") == 0);
        int_to_str(100, str, 3);
        REQUIRE(strcmp(str, "100") == 0);
        int_to_str(1000, str, 4);
        REQUIRE(strcmp(str, "1000") == 0);
        int_to_str(10000, str, 5);
        REQUIRE(strcmp(str, "10000") == 0);
        int_to_str(100000, str, 6);
        REQUIRE(strcmp(str, "100000") == 0);
        int_to_str(1000000, str, 7);
        REQUIRE(strcmp(str, "1000000") == 0);
        int_to_str(10000000, str, 8);
        REQUIRE(strcmp(str, "10000000") == 0);
        int_to_str(100000000, str, 9);
        REQUIRE(strcmp(str, "100000000") == 0);
        int_to_str(1000000000, str, 10);
        REQUIRE(strcmp(str, "1000000000") == 0);}
}