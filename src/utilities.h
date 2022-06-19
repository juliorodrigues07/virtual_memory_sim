#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define read 'R'
#define write 'W'
#define limit 10240
#define INF 1E08
#define start 1048576

typedef struct Page {
    int address;
    int modified;
    int referenced;
    int usage;
    struct Page *next;
} Page;
