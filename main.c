#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;

	fd = open("test.txt", 0_RDONLY);
	if (fd == -1)
		return (1);

}
