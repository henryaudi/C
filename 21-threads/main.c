#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

void *funcCount1();
void *funcCount2();

static int count = 0;

int main(int argc, char *argv[])
{
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, funcCount1, NULL);
  pthread_create(&thread2, NULL, funcCount2, NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  exit(0);
}

void *funcCount1()
{
  for (;;)
  {
    pthread_mutex_lock(&condition_mutex);

    /* Wait until count is outside the halt range */
    while (count >= COUNT_HALT1 && count <= COUNT_HALT2)
    {
      /* While it's waiting it releases the mutex and waits for the wake condition
         is met, then it reacquires the mutex and continues execution.
      */
      pthread_cond_wait(&condition_cond, &condition_mutex);
    }

    pthread_mutex_unlock(&condition_mutex);

    /* Increment the count */
    pthread_mutex_lock(&count_mutex);
    count++;
    printf("Counter value: %d\n", count);
    pthread_mutex_unlock(&count_mutex);

    if (count >= COUNT_DONE)
    {
      return NULL;
    }
  }
}

void *funcCount2()
{
  for (;;)
  {
    pthread_mutex_lock(&condition_mutex);
    if (count < COUNT_HALT1 || count > COUNT_HALT2)
    {
      /* Signal the waiting thread to wake up */
      pthread_cond_signal(&condition_cond);
    }
    pthread_mutex_unlock(&condition_mutex);

    /* Increment the count */
    pthread_mutex_lock(&count_mutex);
    count++;
    printf("Counter value: %d\n", count);
    pthread_mutex_unlock(&count_mutex);
    
    if (count >= COUNT_DONE)
    {
      return NULL;
    }
  }

}
