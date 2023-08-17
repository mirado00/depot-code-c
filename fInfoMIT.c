#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/home/mirado/programme.c/exoFile/infoMIT.h"
//#include "./infoMIT.h"

void recuper_info(etudiant *p, int *nbr){
	FILE *file=fopen("../../etudiant.csv", "r");
	char *line=malloc(200);
	char **var=dec2d(8, 200);
	int i=0;
	
	while(!feof(file)){
		/*
		printf("Nom:");scanf("%s", p[i].nom);
		printf("Prenom(s):");scanf("%s", p[i].prenom);
		printf("taille:");scanf("%d", &p[i].taille);
		*/
		//fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,]", p[i].nom, p[i].prenom, p[i].genre, p[i].mention, p[i].nation);
		fgets(line, 200, file);
		var=split(line);
		
		strcpy(p[i].nom, var[0]);
		strcpy(p[i].prenom, var[1]);
		strcpy(p[i].DL, var[2]);
		strcpy(p[i].genre, var[3]);
		strcpy(p[i].adress, var[4]);
		strcpy(p[i].mention, var[5]);
		strcpy(p[i].nation, var[6]);
		
		i++;
	}
	*nbr=i; 
	 
	fclose(file);
}
void write_File(etudiant *p, int nbr){
	FILE *file=fopen("../../Documents/infoMIT.csv", "w+");
	if(file==NULL){
		printf("impossible d'ouvrir le fichier!\n");exit(1);
	}
	
	fprintf(file, "%s,%s,%s,%s,%s,%s,%s", p[0].nom, p[0].prenom,p[0].DL,  p[0].genre, p[0].adress, p[0].mention, p[0].nation);
	for (int i=1;i<nbr-1;i++){
		fprintf(file, "%s,%s,%s,%s,%s,%s,%s", p[i].nom, p[i].prenom,p[i].DL,  p[i].genre, p[i].adress, p[i].mention, p[i].nation);
	}
	fclose(file);
}
char **dec2d(int dim1, int dim2){
	char **var=malloc(sizeof(char*)*dim1);
	for (int i=0;i<dim1;i++){
		var[i]=malloc(dim2);
	}
	return var;
}
char  **split(char *line){
	char **var=dec2d(8, 100);
	char *M=strtok(line, ",");
	int n=0;
	while(M!=NULL){
		strcpy(var[n], M);
		M=strtok(NULL, ",");
		n++;
	}

	return var;
}
void echanger(etudiant  *a, etudiant *b) {
    etudiant tmp = *a;
    *a = *b;
    *b = tmp;
}


void sort (etudiant *p, int nbr){
	for(int i=1;i<nbr; i++){

		for(int j=i+1;j<nbr;j++){
			if(strcmp(p[i].nom,p[j].nom)>=0 && strcmp(p[i].prenom, p[j].prenom)==1){
				echanger(&p[i], &p[j]);
			}
		}
	}

}
