#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     count;

    count = 0;
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file");
        return (1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        count++;
        printf("[%d]:%s\n, count, line"); //   count is to show you the line numbers
        free(line);
        line = NULL;
    }
    close(fd);
    return (0);
}
