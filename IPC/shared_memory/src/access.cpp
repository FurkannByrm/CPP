#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>



int main()
{
    key_t key =ftok("shared_memory_file", 60);
    
    int shmid = shmget(key,1024,0666|IPC_CREAT);

    char *str = (char*) shmat(shmid, (void*)0,0);

    std::cout<<"Read data in memory : "<<str<<"\n";

    shmdt(str);

    shmctl(shmid, IPC_RMID, nullptr);

    return 0;
}