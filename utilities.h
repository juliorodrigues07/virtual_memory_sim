#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Pagina {
	char address[9];
	struct Pagina *next;	
}Pagina;