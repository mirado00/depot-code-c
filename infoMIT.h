#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nom[100];
	char prenom[100];
	char DL[100];
	char genre[100];
	char adress[100];
	char mention[100];
	char nation[100];
}etudiant;

void recuper_info(etudiant *p, int *nbr);
void write_File(etudiant *p, int nbr);
char **dec2d(int dim1, int dim2);
char  **split(char *line);
void echanger(etudiant  *a, etudiant *b);
void sort (etudiant *p, int nbr);


