#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

typedef struct Pagina {
	char address[9];
	struct Pagina *next;	
} Pagina;

void Add_page(char value[9]);
void LRU(char value[9]);
void NRU(char value[9]);
void SecondChance(char value[9]);
bool Find(char value[9]);
void Tipo_alg(char value[9]);
void WriteAddress(char value[9]);
