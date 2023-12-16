#include "string_util.hpp"

// Helper function to trim leading and trailing whitespaces and line endings
const char* trim(const char* str) {
    // Skip leading whitespaces
    while (std::isspace(*str) || *str == '\n' || *str == '\r') {
        ++str;
    }

    // Find the end of the string
    const char* end = str;
    while (*end) {
        ++end;
    }
    
    // Move end back to the last non-whitespace character and line ending
    while (end > str && (std::isspace(*(end - 1)) || *(end - 1) == '\n' || *(end - 1) == '\r')) {
        --end;
    }

    // Return the trimmed string
    return str;
}