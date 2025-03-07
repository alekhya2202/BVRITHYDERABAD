#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

static char message[] = "Hello, world";

int main() {
    int fd;
    char buffer[80];
    fd = open("datafile.dat",O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
    if (fd != -1) {
	printf("datafile.dat opened for read/write access\n");
	write(fd, message, sizeof(message));
	lseek(fd, 0L, 0);
	if (read(fd, buffer, sizeof(message)) == sizeof(message))
  	    printf("\"%s\" was written to datafile.dat\n", buffer);
	else
	    printf("*** error reading datafile.dat ***\n");
	    close (fd);
    }
    else
	printf("*** datafile.dat already exists ***\n");
    exit (0);
}

