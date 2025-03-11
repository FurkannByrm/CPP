#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok("shared_memory_file", 60); // unique key

    int shmid = shmget(key, 1024, 0666| IPC_CREAT); // definer's return for shared memory part

    char *str = (char*) shmat(shmid, (void*)0,0);// attaching itself to memory part

    std::cout<<" Write Data: ";
    std::cin>> str;

    std::cout<<"writing data in shared memory"<<str;

    shmdt(str);//We're done with shared memory


    return 0;
}

