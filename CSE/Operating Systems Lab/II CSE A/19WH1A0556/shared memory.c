
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
	int i;
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);
	printf("Key of shared memory is %d\n", shmid);
	shared_memory = shmat(shmid, NULL, 0);
	// process attached to shared memory segment
	printf("Process attached at %p\n", shared_memory);
	printf("Enter the data to write into the shared memory\n");
	read(0, buff, 100);
	strcpy(shared_memory, buff);
	printf("You wrote : %s\n", (char*)shared_memory);
}