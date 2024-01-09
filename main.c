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
