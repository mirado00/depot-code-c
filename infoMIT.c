#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./fInfoMIT.c"

int main(){
	etudiant *p=malloc(sizeof(etudiant)*50);
	int nbr;
	recuper_info(p, &nbr);
	sort(p, nbr);
	write_File(p, nbr);
	return 0;
}
