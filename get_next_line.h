#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3

char		*get_next_line(int fd);
void		print_newline_helper(char *buffer);
static char	*read_from_file(int fd);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_strlen(char *str);

#endif
