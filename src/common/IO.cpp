#include "IO.hpp"

bool create_directory(const char* dirpath) 
{
    struct stat info;
    bool directory_exists = (stat(dirpath, &info) == 0) && S_ISDIR(info.st_mode);
    if(!directory_exists) 
    {
        if(mkdir(dirpath, 0777) == -1) 
        {
            cerr << "Error creating directory" << dirpath << endl;
            return false;
        }
    }
    return true;
}

void create_output_filepath(char* filepath, char* distance, char* output_filepath, size_t output_filepath_len) 
{
    char output_directory[8] = "output/";
    char file_extension[5] = ".bin";
    char neighbors[10] = "neighbors";
    char bar[2] = "_";

    // create output/ if it doesn't exist
    create_directory(output_directory); 

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
        strncpy(output_filepath + length, bar, 1);
        length += 1;

        // Add "neighbors" to the filename
        strncpy(output_filepath + length, neighbors, 9);
        length += 9;

        // Add "_" to the filename
        strncpy(output_filepath + length, bar, 1);
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

int open_filepath(const char* filepath, int flags, mode_t mode) 
{
    int fd = open(filepath, flags, mode);
    if (fd == -1)
    {
        cerr << "Unable to open file" << endl;
        return fd;
    }
    return fd;
}

int close_filepath(int fd)
{   
    int f = close(fd);
    if (f == -1) 
    {
        cerr << "Error closing file" << endl;
        return f;
    }
    return f;
}

size_t read_from_filepath(int fd, void* buf, size_t size) 
{
    size_t read_size = read(fd, buf, size);
    if (size == (size_t)-1)
    {
        cerr << "Error reading file" << endl;
        return -1;
    }
    return read_size;
}

int write_to_filepath(int fd, const void* buf, size_t size) 
{
    size_t write_size = write(fd, buf, size);
    if (write_size == (size_t)-1) 
    {
        cerr << "Error writing to file: " << buf << endl;
        return -1;
    }
    return write_size;
}