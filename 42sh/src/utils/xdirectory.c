/*
** xdirectory.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  1 12:10:12 2013 kevin labbe
** Last update Fri May 17 10:30:07 2013 kevin labbe
*/

#include "proto.h"

char	*xgetcwd(void)
{
  char	*buffer;

  if (!(buffer = my_alloc(400, sizeof(char))))
    return (NULL);
  if (getcwd(buffer, 400))
    return (buffer);
  free(buffer);
  return (NULL);
}

int	xchdir(char *dir)
{
  if (chdir(dir) < 0)
    {
      if (access(dir, F_OK) < 0)
	my_fprintf(STDERR_FILENO, MSG_CD_NO_DIR, dir);
      else
	if (access(dir, R_OK) < 0)
	  my_fprintf(STDERR_FILENO, MSG_CD_NO_PERMS, dir);
	else
	  my_fprintf(STDERR_FILENO, MSG_CD_FILE, dir);
      return (-1);
    }
  return (0);
}
