// #include <fcntl.h>
// #include <unistd.h>
// #include "get_next_line.h"

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", 0_RDONLY);
// 	if (fd == -1)
// 		return (1);

// }

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

int main(void) {
	int fd;
	ssize_t read_bytes;
	char buffer[BUFFER_SIZE];

	// Open the file
	fd = open("test.txt", O_RDONLY);
	// if (fd == -1)
	// 	return (1);

	// Read from the file and write to the terminal
	while ((read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
		write(STDOUT_FILENO, buffer, read_bytes);
	}

	// Close the file
	close(fd);

	return 0;
}


int main() {
    // Write to the file
    int fd = open("texttest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        // handle error
        return 1;
    }
    char *str = ""; //write in this line
    ssize_t len = strlen(str);
    if (write(fd, str, len) != len) {
        // handle error
        return 1;
    }
    close(fd);
    // Read from the file
    fd = open("texttest.txt", O_RDONLY);
    if (fd == -1) {
        // handle error
        return 1;
    }
    static int  count = 0;
    for (int i = 0; i < 14; i++)
    {
        printf("%d :%s\n", count, get_next_line(fd));
        count++;
    }
    close(fd);
    return 0;
}
