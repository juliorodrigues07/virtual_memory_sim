#include "utilities.h"

char *algorithm, *file_path;
int page_size, mem_size, n_pages, used_pages=0;

// Métricas
int faults = 0, operations=0, reads=0, writes=0, hits=0, misses=0, writebacks=0;
FILE *file;
Page *first, *last;

void add_new_page(unsigned addr, char rw) {

	Page *current = (Page *)malloc(sizeof(Page));
	current->address = addr;
    current->referenced = 1;
    current->usage = start;
	current->next = NULL;

    if (rw == write)
        current->modified = 1;
    else
        current->modified = 0;

	if (used_pages == 0){
		first = current;
		last = first;
	} else {
		last->next = current;
		last = current;
	}
	
	if (used_pages < n_pages)
		used_pages++;
}

void lru(unsigned addr, char rw) {

    Page *tmp = first;
    unsigned value = INF;
    Page *last_use;

    while (tmp != NULL) {
        if (tmp->referenced < value) {
            value = tmp->referenced;
            last_use = tmp;
        }
        tmp = tmp->next;
    }

    if (last_use->modified)
        writebacks++;

    last_use->address = addr;
    last_use->referenced = 1;
    last_use->usage = start;

    if (rw == write)
        last_use->modified = 1;
    else
        last_use->modified = 0;
}

void second_chance(unsigned addr, char rw) {

    Page *count = first;
    bool check = true;

    while (count != NULL) {

        if (count->referenced == 0){

            if (count->modified)
                writebacks++;

            count->address = addr;
            count->referenced = 1;
            count->usage = start;

            if (rw == write)
                count->modified = 1;
            else
                count->modified = 0;
            return;
        }

        count = count->next;
    }

    if (check) {
        if (first->modified)
            writebacks++;

        first->address = addr;
        first->referenced = 1;
        first->usage = start;

        if (rw == write)
            first->modified = 1;
        else
            first->modified = 0;
    }
}

void nru(unsigned addr, char rw) {

    Page *tmp = first;
}

bool page_search(unsigned addr) {

    Page *tmp = first;
    int s;

    while (tmp != NULL) {
        if (addr == tmp->address) {
            s = tmp->usage;
            tmp->usage = s << 1;
            printf("%d\n", tmp->usage);
            return true;
        } else
            tmp = tmp->next;
    }

    return false;
}

void algorithm_selection(unsigned addr, char rw) {

    if (strcmp(algorithm, "lru") == 0)
		lru(addr, rw);
    else if (!strcmp(algorithm, "second_chance"))
        second_chance(addr, rw);
	else if (strcmp(algorithm, "nru") == 0)
		nru(addr, rw);
}

void write_address(unsigned addr, char rw) {

    if (used_pages < n_pages)
		add_new_page(addr, rw);
	else {
		faults++;
		algorithm_selection(addr, rw);
	}
}

void unreference_pages() {

    Page *f = first;
    int s;

    while (f != NULL) {
        f->referenced = 0;
        s = f->usage;
        f->usage = s >> 1;
        f = f->next;
    }
}

unsigned shift_bits(unsigned addr) {

    unsigned s, size, tmp;

    size = page_size;
    tmp = size * 1024;
    s = 0;

    while (tmp > 1) {
        tmp = tmp >> 1;
        s++;
    }

    unsigned page_id;
    page_id = addr >> s;
    return page_id;
}

void FreeMemory() {

    Page *tmp = first;

    while (tmp != NULL){
		free(tmp);
		tmp = tmp->next;
	}

    fclose(file);
}

int main(int argc, char *argv[]) {

    algorithm = argv[1];
	file_path = argv[2];
	page_size = atoi(argv[3]);
	mem_size = atoi(argv[4]);

	if (page_size < 2 || page_size > 64) {
		printf("O tamanho de cada página deve estar no intervalo (2 e 64)\n");
		return 0;
	}
		
	if (mem_size < 128 || mem_size > 16384) {
		printf("O tamanho da memória deve estar no intervalo (128, 16384)\n");
		return 0;
	}	
	
	if (strcmp(algorithm, "lru") && strcmp(algorithm, "second_chance") && strcmp(algorithm, "nru")) {
		printf("O algoritmo informado não existe ou foi informado incorretamente\n\n"
               "Opções disponíveis: lru, second_chance e nru");
		return 0;	
	}
	
	n_pages = mem_size/page_size;
    unsigned end, addr;
    char rw;
    int timer = 0;
		
	if (strlen(file_path) > 0) {

		file = fopen(file_path, "r");

        while (fscanf(file,"%x %c", &end, &rw) != EOF) {

            // Realiza o deslocamento de bits para
            addr = shift_bits(end);
            operations++;

            if (timer == limit) {
                unreference_pages();
                timer = 0;
            }
            if (rw == read) {
                if (page_search(addr))
                    hits++;
                else {
                    misses++;
                    write_address(addr, rw);
                }
                reads++;
            } else if (rw == write) {
                if (page_search(addr))
                    hits++;
                else {
                    misses++;
                    write_address(addr, rw);
                }
                writes++;
            } else {
				printf("O arquivo de entrada não existe ou foi informado incorretamente!\n");
				return 0;
			}
            timer++;
		}
	} else {
		printf("Entrada inválida - Especifique o nome do arquivo .log\n");
		return 0;
	}

	printf("\nExecutando o simulador de memória virtual...\n\n");
	printf("Tamanho da memória: %dKB\n", mem_size);
	printf("Tamanho das páginas: %dKB\n", page_size);
	printf("Técnica de reposição: %s\n", algorithm);
	printf("Páginas lidas: %d\n", reads);
	printf("Páginas escritas: %d\n", writes);
    printf("Page Faults: %d\n", faults);
    printf("Writebacks: %d\n", writebacks);
	/*
    printf("Hits: %d\n", hits);
	printf("Misses: %d\n", misses);
	printf("Taxa de page fault: %f%% \n", (float)faults / operations * 100);
    */
	FreeMemory();
	return 0;
}

