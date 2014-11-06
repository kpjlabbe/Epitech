/*
** get_next_line.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:40:39 2013 kevin labbe
** Last update Tue Apr 23 15:07:30 2013 kevin labbe
*/

#include "my.h"

char		*newline(t_gnl *infos, char resize)
{
  int		i;
  int		buffer_to_nl;
  int		buffer_to_end;
  int		line_to_end;
  int		size;
  
  buffer_to_nl = my_strlen_to(&infos->buffer[infos->chr_skipped], '\n');
  buffer_to_end = my_strlen_to(&infos->buffer[infos->chr_skipped], '\0');
  infos->found_nl = (buffer_to_nl != buffer_to_end) ? 1 : 0;
  line_to_end = (resize) ? my_strlen_to(infos->line, '\0') : 0;
  size = line_to_end + buffer_to_nl;
  if (resize)
    infos->line = my_realloc(infos->line, size, sizeof(char));
  else
    infos->line = my_alloc(buffer_to_nl, sizeof(char));
  i = (resize) ? line_to_end : 0;
  while (i < size)
    {
      infos->line[i] = infos->buffer[infos->chr_skipped];
      infos->chr_skipped++;
      i++;
    }
  infos->chr_skipped += (infos->found_nl) ? 1 : 0;
  return (infos->line);
}

char		*get_next_line(const int fd)
{
  static t_gnl	infos;
  
  infos.found_nl = 1;
  if (infos.chr_skipped < infos.chr_read)
    if ((infos.line = newline(&infos, 0)) && infos.found_nl)
      return (infos.line);
  while ((infos.chr_read = read(fd, infos.buffer, GNL_BUFFER_SIZE)) > 0)
    {
      infos.chr_skipped = 0;
      infos.line = (!infos.found_nl) ?
	newline(&infos, 1) : newline(&infos, 0);
      if (infos.found_nl)
	return (infos.line);
    }
  return (NULL);
}
