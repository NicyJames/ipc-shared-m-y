#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    int shmid;
    int *val,val1;
    char *bufc[100];
    key_t key=ftok("pipe.c",'a');
    shmid=shmget(key,40,IPC_CREAT|0777);
    if(shmid<0)
    printf("ErRor");
    printf("sharedmemory created with id =%d",shmid);
    if((val=shmat(shmid,0,0))<0)
    {
        printf("error");
    }
    else
    {
        printf("\nstarting address:%u",val);
        printf("enter the string to be written:");
        scanf("%s",bufc);
        strncpy(val,bufc,sizeof(bufc));
        printf("\ncontent of the memory location:%s",val);
        if((val=shmdt(val))<0)
        {
            printf("error");
        }
        printf("allocated shared memory detached");
    }
}
