#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


int thread_count = 3;
int m = 3;
int n = 3;
int x[3] = {2, 4, 6};
int y[3];

int a[3][3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};

void Pth_mat_vect(void* rank){
  long* my_rank = (long*) rank;
  int i, j;
  int local_m = m/thread_count;
  int my_first_row = (*my_rank)*local_m;
  int my_last_row = (*my_rank+1)* local_m - 1;
  for(i = my_first_row; i <= my_last_row; i++){
    y[i] = 0;
    for(j = 0; j < n; j++){
      y[i] += a[i][j] * x[j];
    }
  }
}

int main(void){ 
  pthread_t id[3];
  long rank;
  for(rank = 0; rank < 3; rank++){
    pthread_create(&id[rank], NULL, (void *)Pth_mat_vect, &rank);
    pthread_join(id[rank], NULL);
  }
  printf("vetor y final: ");
  for(int i = 0; i < 3; i++){
    printf("%d ", y[i]);
  }
	return 0; 
} 
