#include "IO.hpp"

int main_args_validator(int argc, char* argv[], char *input_filepath, int* dimensions, int* K, char *distance, int* delta, float* p)
{   
    // hold only the executable name
    const char* executable_name = strrchr(argv[0], '/');
    if (executable_name != nullptr) 
    {
        executable_name += 1; // Move past the '/'
    } else 
    {
        executable_name = argv[0];
    }

    // check number of arguments
    if (argc != 5 && argc != 7)
    {
        cerr << "Wrong number of arguments" << endl;
        return -1;
    }

    // check if arguments are valid for the given executable
    if (argc != 5 && strcmp(executable_name, "brute_force") == 0)
    {
        cerr << "Usage: " << argv[0] << " <filepath> <dimensions> <K nearest neighbors> <distance type e or m>" << endl;
        return -1;
    } else if (argc != 7 && strcmp(executable_name, "project") == 0)
    {
        cerr << "Usage: " << argv[0] << " <filepath> <dimensions> <K nearest neighbors> <distance type e or m> <delta> <p>" << endl;
        return -1;
    }

    strcpy(input_filepath, argv[1]); // inputFile
    cout << "input_filepath = " << input_filepath << endl;

    *dimensions = atoi(argv[2]); // dimensions of point
    if (*dimensions <= 0)
    {
        cerr << "Invalid dimensions" << endl;
        return -1;
    }
    cout << "dimensions = " << *dimensions << endl;

    *K = atoi(argv[3]); // K nearest neighbors
    if (*K <= 0)
    {
        cerr << "Invalid K number of nearest neighbors" << endl;
        return -1;
    }
    cout << "K = " << *K << endl;

    strncpy(distance, argv[4], strlen(argv[4])); // distance type
    if (strcmp(distance, "e") != 0 && strcmp(distance, "m") != 0)
    {
        cerr << "Invalid distance type. Select e for euclidean or m for manhattan." << endl;
        return -1;
    }
    cout << "distance = " <<  distance << endl;

    if (argc == 7)
    {
        *delta = atoi(argv[5]); // delta
        if (*delta <= 0)
        {
            cerr << "Invalid delta" << endl;
            return -1;
        }
        cout << "delta = " << *delta << endl;

        *p = atof(argv[6]); // p
        if (*p <= 0)
        {
            cerr << "Invalid p" << endl;
            return -1;
        }
        cout << "p = " << *p << endl;
    }
    cout << endl;

    return 0;
}

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

void create_output_filepath(char* filepath, char* distance, int K, char* output_filepath, size_t output_filepath_len) 
{
    char output_directory[8] = "output/";
    char file_extension[5] = ".bin";
    char bar[2] = "_";

    int k_len = get_int_len(K);
    char* k_str = static_cast<char*>(malloc(k_len + 1));
    int_to_str(K, k_str, k_len);

    // create output/ if it doesn't exist
    create_directory(output_directory); 

    // Find the last occurrence of the path separator ('/') to get the filename
    char* filenameStart = strrchr(filepath, '/');

    // If '/' is found, move past it; otherwise, start from the beginning
    if (filenameStart != nullptr) 
    {
        filenameStart += 1; // Move past the '/'
    } else 
    {
        filenameStart = filepath;
    }
    
    // Find the length of the filename
    size_t length = strlen(filenameStart);

    if (length + strlen(output_directory) < output_filepath_len) {
        // Copy "output/" to the output_filepath array
        strncpy(output_filepath, output_directory, output_filepath_len);

        // Append the remaining part of the original path
        strncat(output_filepath, filenameStart, output_filepath_len - strlen(output_directory));

        // Find the position of the last dot ('.') character
        char* dot = strrchr(output_filepath, '.');

        // If a dot is found and it is not the first character, insert text before it
        if (dot != nullptr && dot != output_filepath) {
            *dot = '\0'; // Truncate the string at the dot position
        }

        // Add "_K_distance.bin" to the filename
        strncat(output_filepath, bar, strlen(bar));
        strncat(output_filepath, k_str, strlen(k_str));
        strncat(output_filepath, bar, strlen(bar));
        strncat(output_filepath, distance, strlen(distance));
        strncat(output_filepath, file_extension, strlen(file_extension));

        // Null-terminate the output_filepath string
        output_filepath[output_filepath_len - 1] = '\0';
    }   

    free(k_str);
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

int get_int_len(int number) 
{   
    int length = 0;

    if (number == 0) 
    { 
        length++;
        return length;
    }
    
    int temp = abs(number); // Use abs to handle negative numbers
    while (temp > 0) 
    {   
        temp /= 10;
        length++;
    }
    return length;
}

void int_to_str(int number, char* str, int lenght) {
    // Null-terminate the string
    str[lenght] = '\0';

    // Fill the string with digits
    for (int i = lenght - 1; i >= 0; i--) {
        str[i] = '0' + (abs(number) % 10); // Use abs to handle negative numbers
        number /= 10;
    }

    // Handle the sign for negative numbers
    if (number < 0) {
        str[0] = '-';
    }
}