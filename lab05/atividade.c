#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

/*
  Ye Wei Jiang - 41926293
  
  estrategia: devido a caracteristica do thread(compartilha o mesmo espaco de memoria). 
  utilizei o thread para fazer a multiplicacao, sendo cada elemento eh processado por um thread diferente. 
  ao final imprimindo o resultado do array.

*/



//o numero que vai multiplicar com array
int a;

// fazer calculo
void thread(void* arg){
	int* arr = (int*)arg;
	*arr *= a; 
}

//verificar se o thread foi criado com sucesso
void verify(int ret){
	if(ret!=0){ 
		printf ("Create pthread error!\n"); 
		exit(1); 
	}
}

//criar threads
void criarThread(pthread_t id[], int arr[]){
	int ret;
	for(int i = 0; i < 5; i++){
		ret=pthread_create(&id[i], NULL, (void *)thread, &arr[i]);
		verify(ret);
		pthread_join(id[i], NULL);
	}
}

int main(void){ 
	printf("Digete o numero que vai multiplicar o array: ");
	scanf("%d", &a);
	pthread_t id[5];
	int arr[5] = {1, 2, 3, 4, 5};
	criarThread(id, arr);
	
	//imprimir o resultado
	printf("resultado: \n");
	for(int i =0; i < 5; i++){
		printf("%d\n", arr[i]);
	}
	return 0; 
} 
