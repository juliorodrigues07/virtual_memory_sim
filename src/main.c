#include "utilities.h"

int main(int argc, char *argv[]) {

    // Parâmetros do programa
    char *algorithm, *file_path;
    int page_size, mem_size, n_pages, used_pages = 0;

    // Métricas para relatório
    int faults = 0, operations = 0, reads = 0, writes = 0, hits = 0, misses = 0, writebacks = 0;
    FILE *file;

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

    if (strcmp(algorithm, "lru") && strcmp(algorithm, "segunda_chance") && strcmp(algorithm, "nru")) {
        printf("O algoritmo informado não existe ou foi informado incorretamente\n\n"
               "Opções disponíveis: lru, segunda_chance e nru");
        return 0;
    }

    // Número de páginas máximo que a memória principal é capaz de armazenar
    n_pages = mem_size/page_size;
    unsigned id, addr;
    char rw;
    int timer = 0;

    clock_t t, exec_time;
    t = clock();

    if (strlen(file_path) > 0) {

        file = fopen(file_path, "r");

        while (fscanf(file,"%x %c", &addr, &rw) != EOF) {

            // Realiza o deslocamento de bits para encontrar a identificação da página
            id = shift_bits(addr, page_size);
            operations++;

            // Desreferencia todas as páginas na memória principal a cada interrupção de relógio
            if (timer == limit) {
                unreference_pages();
                timer = 0;
            }

            /* Busca pela página atual na memória principal. Caso esta não seja encontrada,
               é criada uma nova página ou aplica-se algum algoritmo de substituição */
            if (page_search(id, rw))
                hits++;
            else {
                misses++;
                write_address(algorithm, id, rw, &used_pages, n_pages, &faults, &writebacks);
            }

            if (rw == read)
                reads++;
            else if (rw == write)
                writes++;
            else {
                printf("Dados do arquivo de entrada estão em formato incorreto!\n");
                return 0;
            }
            timer++;
        }
    } else {
        printf("Entrada inválida - Especifique o nome do arquivo .log\n");
        return 0;
    }

    exec_time = clock() - t;
    float fault_tax = (float)faults / operations * 100;

    // Exibe o relatório de execução
    printf("\nExecutando o simulador de memória virtual...\n\n");
    printf("Arquivo de entrada: \t %s \n", file_path);
    printf("Tamanho da memória: \t %d KB \n", mem_size);
    printf("Tamanho das páginas: \t %d KB \n", page_size);
    printf("Técnica de reposição: \t %s \n", algorithm);
    printf("Páginas lidas: \t\t %d \n", reads);
    printf("Páginas escritas: \t %d \n", writes);
    printf("Page Faults: \t\t %d \n", faults);
    printf("Writebacks: \t\t %d \n", writebacks);
    printf("Hits: \t\t\t %d \n", hits);
    printf("Misses: \t\t %d \n", misses);
    printf("Taxa de page fault: \t %f%% \n", fault_tax);
    printf("\nTempo de execução: \t %lfs \n\n", ((double)exec_time)/((CLOCKS_PER_SEC)));

    free_memory(file);
    return 0;
}