<div align="center">
	<img src="https://github.com/maksim-volkmann/42-project-badges/blob/main/badges/get_next_linem.png" width="200" alt="get_next_line badge" />
	<h1>Get_next_line</h1>
</div>

## Summary
This project implements `get_next_line`, a function that reads one line at a time from a file each time it is called. Each call to `get_next_line` returns one line, making it easier to handle file data line-by-line. The function allows adjusting the buffer size, which controls how many characters are read at once, to optimize performance based on file size or memory needs. In the bonus part, `get_next_line` can read from multiple files at the same time without losing track of each file’s position.

## Usage Example

To use `get_next_line`, open the file you want to read, then call `get_next_line` in a loop to get each line.

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"  // Include the header for get_next_line

int main(void)
{
	int fd = open("example.txt", O_RDONLY); // Open the file in read-only mode
	if (fd == -1)
	{
		perror("Error opening file");
		return 1;
	}

	static int count = 0;   // Counter for each call
	for (int i = 0; i < 5; i++)
	{
		char *line = get_next_line(fd);  // Get a line from the file
		if (!line)
			break;
		printf("%d: %s\n", count, line);  // Print the line with the count
		free(line);  // Free the memory allocated by get_next_line
		count++;
	}

	close(fd); // Close the file descriptor
	return 0;
}
```

This example opens `example.txt` and reads five lines, printing each line with a counter. The `get_next_line` function reads one line per call, and the buffer size can be set when compiling, e.g., `-D BUFFER_SIZE=42`.
