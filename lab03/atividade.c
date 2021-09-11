/*
	Ye Wei Jiang
	
	41926293
	
	Escreva um programa que leia um arquivo texto com o nome, a idade e a altura de um conjunto de pessoa.
	Coloque os dados em um vetor de Structs e ordene o vetor por altura. 
	No final, gere um novo arquivo com os dados ordenados.

*/ 


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    double altura;
    
}PESSOA;

int cmp(const void *a, const void *b){
	PESSOA arg1 = *(const PESSOA*)a;
    PESSOA arg2 = *(const PESSOA*)b;
	
	if (arg1.altura < arg2.altura) return -1;
    if (arg1.altura > arg2.altura) return 1;
    return 0;
}


int main(){

	PESSOA povo[10];
	FILE *arq;
	int i = 0;
	//abrir o arquivo
	arq = fopen("pessoas.txt", "r");
	if(arq == NULL){
		printf("Error!");
    	exit(1);
	}
	
	//ler o arquivo
	while(fscanf(arq, "%[^\n]", &povo[i].nome) != EOF){	
		fscanf(arq, "%d", &povo[i].idade);
		fscanf(arq, "%lf", &povo[i].altura);
		char enter = fgetc(arq);
		i++;
	}
	//fechar o arquivo
	fclose(arq);
	// ordena
	qsort(povo, i, sizeof(PESSOA), cmp);
	
	//criar o arquivo
	FILE *novo = fopen("pessoasOrdenado.txt","w");
	if(novo == NULL){
		printf("Error!");   
		exit(1);             
	}
	//escrever no arquivo
	for(int j = 0; j < i; j++){
		fprintf(novo,"%s\n%d\n%f\n", povo[j].nome, povo[j].idade, povo[j].altura);
	} 
	//fechar o arquivo
	fclose(novo);
	printf("Sucesso!!!\n");
	
	return 0;
}

