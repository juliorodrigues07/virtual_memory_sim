#include "utilities.h"

int tam_pag, tam_mem, numPaginas, leitura=0, escrita=0, pag=0;
char *tipo, *caminho, line[100], tmpAddress[9];

Pagina *first, *last;
FILE *entrada;

void Add_page(char value[9]) {

    Pagina *pag_atual = (Pagina *)malloc(sizeof(Pagina));
	strcpy(pag_atual->address, value);
	pag_atual->next = NULL;

	if (pag == 0) {
		first = pag_atual;
		last = first;
	} else {
		last->next = pag_atual;
		last = pag_atual;
	}

	if (pag < numPaginas)
		pag++;

	escrita++;
}

void LRU(char value[9]) {

    Add_page(value);

    if (pag == numPaginas)
		first = first->next;
}

void NRU(char value[9]) {
	//Implementar
}

void SecondChance(char value[9]) {
	//Implementar
}

bool Find(char value[9]) {

    Pagina *tmp = first, *prev = NULL;

    while (tmp != NULL) {

        if (strcmp(tmp->address, value)==0) {
			if (strcmp(tipo, "lru") == 0) {

                if (prev != NULL) {
					if (tmp->next != NULL)
						prev->next = tmp->next;
				} else
					first = first->next;

                last->next = tmp;
				last = tmp;
				tmp->next = NULL;
			}
			return true;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return false;
}

void Tipo_alg(char value[9]) {

    if (strcmp(tipo, "lru") == 0)
		LRU(value);
	else if (strcmp(tipo, "nru") == 0)
		NRU(value);
	else if (strcmp(tipo, "sc") == 0)
		SecondChance(value);
}

void WriteAddress(char value[9]) {

    if(pag < numPaginas)
		Add_page(tmpAddress);
	else
		Tipo_alg(tmpAddress);
}

void free_memory(){

    Pagina *tmp = first;

    while (tmp != NULL) {
        free(tmp);
        tmp = tmp->next;
    }

    fclose(entrada);
}

int main(int argc, char *argv[]) {

    tipo = argv[1];
	caminho = argv[2];
	tam_pag = atoi(argv[3]);
	tam_mem = atoi(argv[4]);
	numPaginas = tam_mem/tam_pag;

    // Checa se a entrada foi informada corretamente
	if (tam_pag < 2 || tam_pag > 64) {
		printf("O tamanho da página deve estar no intervalo (2, 64), e deve ser potência de 2!\n");
		return 0;
	}

    if (tam_mem < 128 || tam_mem > 16384) {
        printf("O tamanho da memória deve estar no intervalo (128, 16384), e deve ser potência de 2!\n");
        return 0;
    }

	if (!strcmp(tipo, "lru") && !strcmp(tipo, "nru") && !strcmp(tipo, "sc")) {
        printf("O algoritmo solicitado não está implementado ou foi informado incorretamente!\n");
        return 0;
    }

	entrada = fopen(caminho, "r");

    while (fgets(line, 100, entrada) != NULL) {

		strncpy(tmpAddress, line, 8);
		tmpAddress[8] = '\0';

		if (line[9] == 'W')
			WriteAddress(tmpAddress);
		else if (line[9] == 'R') {

			if (Find(tmpAddress))
				printf("R\n");
			else
				WriteAddress(tmpAddress);

            leitura++;
		} else {
			printf("Arquivo de entrada");
			return 0;	
		}	
	}

    // Relatório de execução
	printf("\nExecutando o simulador...\n");
	printf("\nTamanho da memoria: %iKB", tam_mem);
	printf("\nTamanho das paginas: %iKB", tam_pag);
	printf("\nTecnica de reposicao: %s", tipo);
	printf("\nPaginas lidas: %i", leitura);
	printf("\nPaginas escritas: %i\n", escrita);

    free_memory();
	return 0;
}
