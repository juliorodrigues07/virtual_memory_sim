#include "utilities.h"

// Ponteiros para o início e final da lista de páginas
Page *first, *last;

void add_new_page(unsigned id, char rw, int *used_pages, int n_pages) {

    // Inicialização da página conforme a operação (leitura ou escrita)
    Page *current = (Page *)malloc(sizeof(Page));
    current->id = id;
    current->referenced = 1;
    current->usage = start;
    current->next = NULL;

    if (rw == write)
        current->modified = 1;
    else
        current->modified = 0;

    // Adiciona a página à lista
    if (*used_pages == 0){
        first = current;
        last = first;
    } else {
        last->next = current;
        last = current;
    }

    // Incrementa o número de páginas utilizadas
    if (*used_pages < n_pages)
        (*used_pages)++;
}

void fill_info(Page *page, unsigned id, char rw, int *writebacks) {

    // Se a página à ser retirada foi modificada, ela deve ser escrita de volta no disco (página suja)
    if (page->modified)
        (*writebacks)++;

    // Atribui os valores da nova página de acordo com seu endereço e a operação realizada
    page->id = id;
    page->referenced = 1;
    page->usage = start;

    if (rw == write)
        page->modified = 1;
    else
        page->modified = 0;
}

void lru(unsigned id, char rw, int *writebacks) {

    unsigned value = INF;
    Page *tmp = first;
    Page *last_use;

    // Busca pelo menor valor de referenciação (mais shifts para a direita) para selecionar a página à ser substituída
    while (tmp != NULL) {
        if (tmp->referenced < value) {
            value = tmp->referenced;
            last_use = tmp;
        }
        tmp = tmp->next;
    }

    fill_info(last_use, id, rw, writebacks);
}

void second_chance(unsigned id, char rw, int *writebacks) {

    Page *count = first;
    Page *tmp = first;
    bool check = true;

    while (count != NULL) {

        // Busca por uma página não referenciada na interrupção de relógio atual
        if (count->referenced == 0){
            fill_info(count, id, rw, writebacks);
            return;
        } else {
            // O ponteiro de início da lista passa a apontar para a segunda página
            tmp = tmp->next;
            first = tmp;

            // A primeira página passa a ocupar a última posição na lista, mas ainda continua na memória principal
            last->next = count;
            last = count;
            last->next = NULL;
        }
        count = count->next;
    }

    // Caso todas estejam referenciadas, a primeira página da lista é selecionada para ser substituída (similar ao algoritmo FIFO)
    if (check)
        fill_info(first, id, rw, writebacks);
}

void nru(unsigned id, char rw, int *writebacks) {

    // Classes
    bool c0 = false, c1 = false, c2 = false;
    Page *page_0, *page_1, *page_2, *page_3;
    Page *tmp = first;

    while (tmp != NULL) {

        // Busca pela página à ser substituída em prioridade crescente de classe (0 -> 1 -> 2 -> 3)
        if (tmp->referenced + tmp->modified == 0) {
            c0 = true;
            page_0 = tmp;
            break;
        } else if (tmp->referenced > tmp->modified) {
            c1 = true;
            page_1 = tmp;
        } else if (tmp->referenced < tmp->modified) {
            c2 = true;
            page_2 = tmp;
        } else
            page_3 = tmp;

        tmp = tmp->next;
    }

    if (c0)
        fill_info(page_0, id, rw, writebacks);
    else if (c1)
        fill_info(page_1, id, rw, writebacks);
    else if (c2)
        fill_info(page_2, id, rw, writebacks);
    else
        fill_info(page_3, id, rw, writebacks);
}

bool page_search(unsigned id, char rw) {

    Page *tmp = first;
    int s;

    while (tmp != NULL) {

        // Se a página já está na memória principal, esta é marcada como referenciada e não ocorre falta de página
        if (id == tmp->id) {
            s = tmp->usage;
            tmp->referenced = 1;
            tmp->usage = s << 1;

            // Se a operação é de escrita, o bit de modificação da página é alterado
            if (rw == write)
                tmp->modified = 1;

            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void algorithm_selection(char *algorithm, unsigned id, char rw, int *writebacks) {

    // Chamadas dos algoritmos
    if (strcmp(algorithm, "lru") == 0)
        lru(id, rw, writebacks);
    else if (!strcmp(algorithm, "segunda_chance"))
        second_chance(id, rw, writebacks);
    else if (strcmp(algorithm, "nru") == 0)
        nru(id, rw, writebacks);
}

void write_address(char *algorithm, unsigned id, char rw, int *used_pages, int n_pages, int *faults, int *writebacks) {

    // Cria uma página se existe memória disponível, caso contrário aplica o algoritmo escolhido para substituição
    if (*used_pages < n_pages)
        add_new_page(id, rw, used_pages, n_pages);
    else {
        (*faults)++;
        algorithm_selection(algorithm, id, rw, writebacks);
    }
}

void unreference_pages() {

    Page *f = first;
    int s;

    // Zera o bit de referenciação de todas as páginas na memória principal a cada interrupção de relógio
    while (f != NULL) {
        f->referenced = 0;
        s = f->usage;
        f->usage = s >> 1;
        f = f->next;
    }
}

unsigned shift_bits(unsigned addr, int page_size) {

    unsigned s, size, tmp, page_id;

    size = page_size;
    tmp = size * 1024;
    s = 0;

    // Calcula o número de bits a serem descartados do endereço conforme o tamanho de página
    while (tmp > 1) {
        tmp = tmp >> 1;
        s++;
    }

    page_id = addr >> s;
    return page_id;
}

void free_memory(FILE *file) {

    Page *tmp;

    while (first != NULL){
        tmp = first;
        first = first->next;
        free(tmp);
    }

    fclose(file);
}

void list_pages() {

    Page *tmp = first;

    while (tmp != NULL) {
        printf("%x\n", tmp->id);
        tmp = tmp->next;
    }
}
