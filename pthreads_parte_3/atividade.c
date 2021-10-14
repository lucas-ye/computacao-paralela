#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread_count = 1;
double sum = 0.0;
long long n = 1000000;

void* Thread_sum(void* rank){
  long my_rank = *(long*) rank;
  double factor;
  long long i;
  long long my_n = n / thread_count;
  int my_first_i = my_n * my_rank;
  int my_last_i = my_first_i + my_n;

  if(my_first_i % 2 == 0){
    factor = 1.0;
  }else{
    factor = -1.0;
  }
  for(i = my_first_i; i < my_last_i; i++, factor = -factor){
    sum += factor/(2*i+1);
  }
  return NULL;
}


int main(void) {
  pthread_t id[1];
  long rank;
  for(rank = 0; rank < thread_count; rank++){
    pthread_create(&id[rank], NULL, Thread_sum, &rank);
    pthread_join(id[rank], NULL);
  }
  double result = 4 * sum;
  printf("%lf", result);
  // long long a = 5l/2;
  // printf("%lld", a);
  return 0;
}
