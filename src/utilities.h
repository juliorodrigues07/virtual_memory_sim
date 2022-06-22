#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define read 'R'
#define write 'W'
#define INF 1E08

// Controle do envelhecimento de página, métrica que diminui a medida que a página não é referenciada, ocorridas as interrupções de relógio e vice-versa
#define start 1048576

// Interrupção de relógio a cada 10.240 endereços de páginas analisados
#define limit 10240

// Lista de páginas que conterá as informações das páginas que estão na memória principal no instante t
typedef struct Page {
    int id;
    int modified;
    int referenced;
    int usage;
    struct Page *next;
} Page;

void add_new_page(unsigned id, char rw, int *used_pages, int n_pages);
void fill_info(Page *page, unsigned id, char rw, int *writebacks);
void lru(unsigned id, char rw, int *writebacks);
void second_chance(unsigned id, char rw, int *writebacks);
void nru(unsigned addr, char rw, int *writebacks);
bool page_search(unsigned addr, char rw);
void algorithm_selection(char *algorithm, unsigned id, char rw, int *writebacks);
void write_address(char *algorithm, unsigned id, char rw, int *used_pages, int n_pages, int *faults, int *writebacks);
void unreference_pages();
unsigned shift_bits(unsigned id, int page_size);
void free_memory(FILE *file);
void list_pages();