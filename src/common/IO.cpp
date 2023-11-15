#include "IO.hpp"

using namespace std;

void create_output_filepath(char* filepath, char* distance, char* output_filepath, size_t output_filepath_len) 
{
    char* datasets_directory = "datasets/";
    char* output_directory = "output/";
    char* startPos = strstr(filepath, datasets_directory);
    if (startPos != nullptr) 
    {
        // Move past the "datasets/" part
        startPos += strlen(datasets_directory);

        // Find the length of the remaining path
        size_t length = strlen(startPos);

        if (length + strlen(output_directory) < output_filepath_len) {
            // Add "output/" to the output_filepath array
            strncpy(output_filepath, output_directory, strlen(output_directory));
            output_filepath += strlen(output_directory);

            // Append the remaining part of the original path
            strncpy(output_filepath, startPos, length);

            // Add "_" to the filename
            strncpy(output_filepath + length, "_", 1);
            length += 1;

            // Add distance type to the filename
            strncpy(output_filepath + length, distance, 1);
            length += 1;

            // Add the file extension ".bin"
            strncpy(output_filepath + length, ".bin", 4);
            length += 4;

            // Null-terminate the output_filepath string
            output_filepath[length] = '\0'; 
        }
    } else 
    {
        // If "datasets/" is not found, copy the original path as is
        strncpy(output_filepath, filepath, output_filepath_len);
        output_filepath[output_filepath_len - 1] = '\0'; // Null-terminate the output_filepath string
    }    
}