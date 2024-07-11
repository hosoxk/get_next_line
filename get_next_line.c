#include <unistd.h>
#include "get_next_line.h"

/* -------------------------------------------------------------------------- */
/* Function to read data from the file and append it to partial content.      */
/* -------------------------------------------------------------------------- */
static char *read_from_file(int fd)
{
int bytes_read;
char    *buffer;
static int  count;

printf("ft_calloc#[%d]---", count++);
buffer = ft_calloc (3 + 1 * sizeof(char)); //  +1 for the string to null terminate
if (buffer == NULL)
    return (NULL);
bytes_read = read(fd, buffer, 3);
if (bytes_read <= 0)
{
    free(buffer);
    return (NULL); //   short: return(free(buffer), NULL);
}
return (buffer);
}

/* -------------------------------------------------------------------------- */
/* The get_next_line function to get the next line from the file descriptor.  */
/* -------------------------------------------------------------------------- */
char    *get_next_line(int fd)
{
    char    	*buffer;
	int			length;
	const char	stash;	

    buffer = read_from_file(fd);
	stash += buffer;	//	const char, so saves char written to stash
	length = 0;
	while (length <= buffer)
	{
		check_newline(buffer);
		length++;
	}
    return (buffer);
}

void	check_newline(char *str)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == '\n')
			divide_buffer();
		i++;
	}
}

/* ------------------------------------------------------------------- */
/* Function to convert and print the newline character as ?            */
/* ------------------------------------------------------------------- */
void    print_newline_helper(char *buffer)
{

    while (*buffer &&  *buffer != '\0')
    {
        if (*buffer == '\n') 
        {
            *buffer= '\\';
        }
        printf("%c",*buffer);
        buffer++;
    }
}


