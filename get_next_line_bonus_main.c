#include <stdio.h>
#include <fcntl.h>   // For file control options
#include <unistd.h>  // For close()
#include <stdlib.h>

char* get_next_line(int fd);

int main() {
    int fd;
	int fd2;
    char* line;
	char *line2;
	int	i;

    // Open a file. Replace "example.txt" with your file path
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	fd2 = open("example2.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error opening second file");
		return 1;
	}

    // Reading lines from the file
	i = 0;
	(void)i;
	while (1)
	{
		    line = get_next_line(fd);
			line2 = get_next_line(fd2);
			printf("Line: %s\n", line);
			printf("line2: %s\n", line2);
			if (line == NULL && line2 == NULL)
				break ;
			free(line2);
        	free(line); // Assuming get_next_line allocates memory for the line
			i++;
	}
	free(line2);
	free(line);
    // Close the file descriptor
    close(fd);

    return 0;
}

