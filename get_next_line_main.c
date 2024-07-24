#include <stdio.h>
#include <fcntl.h>   // For file control options
#include <unistd.h>  // For close()
#include <stdlib.h>

char* get_next_line(int fd);

int main() {
    int fd;
    char* line;
	int	i;

    // Open a file. Replace "example.txt" with your file path
    fd = open("example10.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Reading lines from the file
	i = 0;
	(void)i;
    while ((line = get_next_line(fd)) != NULL /*&& i < 1*/) {
        printf("Line: %s", line);
        free(line); // Assuming get_next_line allocates memory for the line
		i++;
    }

	free(line);
    // Close the file descriptor
    close(fd);

    return 0;
}

