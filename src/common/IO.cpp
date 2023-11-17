#include "IO.hpp"

using namespace std;

void create_output_filepath(char* filepath, char* distance, char* output_filepath, size_t output_filepath_len) 
{
    char output_directory[8] = "output/";
    char file_extension[5] = ".bin";

    // Find the last occurrence of the path separator ('/') to get the filename
    char* filenameStart = strrchr(filepath, '/');

    // If '/' is found, move past it; otherwise, start from the beginning
    if (filenameStart != nullptr) 
    {
        filenameStart += 1; // Move past the '/'
    }
    else 
    {
        filenameStart = filepath;
    }
    
    // Find the length of the filename
    size_t length = strlen(filenameStart);

    if (length + strlen(output_directory) < output_filepath_len) {
        // Add "output/" to the output_filepath array
        strncpy(output_filepath, output_directory, strlen(output_directory));
        output_filepath += strlen(output_directory);

        // Append the remaining part of the original path
        strncpy(output_filepath, filenameStart, length);

        // Remove the file extension ".bin" if it exists
        if (length >= 4 && strncmp(output_filepath + length - 4, file_extension, 4) == 0) 
        {
            length -= 4;
        }

        // Add "_" to the filename
        strncpy(output_filepath + length, "_", 1);
        length += 1;

        // Add distance type to the filename
        strncpy(output_filepath + length, distance, 1);
        length += 1;

        // Add the file extension ".bin"
        strncpy(output_filepath + length, file_extension, 4);
        length += 4;

        // Null-terminate the output_filepath string
        output_filepath[length] = '\0'; 
    }   
}