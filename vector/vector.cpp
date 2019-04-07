#include "vector.h"

void* operator new[](size_t size, size_t line, const char* nameFile, const char* nameFunc, void* remem) {
    void* memory = nullptr;

    FILE* logS = fopen("logFile.txt", "a+");

    if (!remem) {
        memory = calloc(size, 1);
        fprintf(logS, "Memory allocation.\n");
    }

    else {
        memory = realloc(remem, size);
        fprintf(logS, "Memory reallocation!\n");
    }

    fprintf(logS, "#\tLine %lu\n"
                  "#\tfunction %s\n"
                  "#\tfile %s\n"
                  "#\tsize %lu byte\n"
                  "#\ton address %p\n\n", line, nameFunc,nameFile, size, memory);

    fclose(logS);

    return memory;
}

void operator delete[](void* mem) {
    assert(mem);

    FILE* logS = fopen("logFile.txt", "a+");

    fprintf(logS, "Free memory.\n"
                  "#\t address %p\n\n", mem);

    fclose(logS);

    free(mem);
}



