#include "../include/utils.h"
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

char* getFilePath(const char* path) {

    const char* current_dir = GetWorkingDirectory();
    size_t len = strlen(current_dir) + strlen(path) + 1;

    char* filepath = (char*) malloc(len);

    strcpy(filepath, current_dir);
    strcat(filepath, path);

    return filepath;

}
