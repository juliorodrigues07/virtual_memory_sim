#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define read 'R'
#define write 'W'
#define limit 4

typedef struct Page {
    int address;
    int modified;
    int referenced;
    struct Page *next;
} Page;

