//pipeWithProcesses.c
#include <stdio.h>
#include <unistd.h>

int main() {
	int pipefds[2];
	int returnStatus;
	int pid;
	char writeMssges[2][20] = {"Hi", "Hello"};
	char readMssge[20];
	returnStatus = pipe(pipefds);
	if (returnStatus == -1) {
		printf("Unable to create pipe\n");
		return 1;
	}
	pid = fork();

	if (pid == 0) {
		read(pipefds[0], readMssge, sizeof(readMssge));
		printf("Child process - reading from pipe - Message 1 is %s\n", readMssge);
		read(pipefds[0], readMssge, sizeof(readMssge));
		printf("Child process - reading from pipe - Message 2 is %s\n", readMssge);
	}
	else {
		printf("Parent process - writing to pipe - Message 1 is %s\n", writeMssges[0]);
		write(pipefds[1], writeMssges[0], sizeof(writeMssges[0]));
		printf("Parent process - writing to pipe - Message 2 is %s\n", writeMssges[1]);
		write(pipefds[1], writeMssges[1], sizeof(writeMssges[1]));
	}
	return 0;
}

