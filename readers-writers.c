#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex;
sem_t write;
int readers=0;

void *Reader(void *arg);
void *Writer(void *arg);

main()
{
        int i,readerCount,writerCount;
        sem_init(&mutex,0,1);
        sem_init(&write,0,1);

        pthread_t readerThread[10],writerThread[10];
	printf("=============================");
        printf("\n Masukkan jumlah readers : ");
        scanf("%d",&readerCount);
        printf("\n Masukkan jumlah writers : ");
        scanf("%d",&writerCount);
	printf("=============================");

        for(i=0;i<readerCount;i++)
        {
                pthread_create(&readerThread[i],NULL,Reader,(void *)i);
        }
        for(i=0;i<writerCount;i++)
        {
                pthread_create(&writerThread[i],NULL,Writer,(void *)i);
        }
        for(i=0;i<writerCount;i++)
        {
                pthread_join(writerThread[i],NULL);
        }

        for(i=0;i<readerCount;i++)
        {
                pthread_join(readerThread[i],NULL);
        }
        sem_destroy(&write);
        sem_destroy(&mutex);
}

void *Writer(void *arg)
{

        sleep(1);
        int temp=(int)arg;
        printf("\n Writer %d mencoba log in ke database untuk reading data",temp);
        sem_wait(&write);
        printf("\n Writer %d sedang writing di database",temp);
        sem_post(&write);
        printf("\n Writer %d log out dari database",temp);
}
	

void *Reader(void *arg)
{
        sleep(1);
        int temp=(int)arg;

        printf("\n Reader %d mencoba log in ke database untuk reading data",temp);
        sem_wait(&mutex);
        readers++;
        if(readers==1)
                sem_wait(&write);
        sem_post(&mutex);
        printf("\n Reader %d sedang reading di database",temp);
        sem_wait(&mutex);
        readers--;
        if(readers==0)
                sem_post(&write);
        sem_post(&mutex);
        printf("\n Reader %d log out dari database",temp);

}

