/*
** xredir.c for 42sh in /home/labbe_k/Desktop/42sh/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Fri May 17 10:48:09 2013 kevin labbe
** Last update Mon May 20 09:57:04 2013 kevin labbe
*/

#include "proto.h"

int	xdup2(int to, int from)
{
  if (dup2(to, from) == -1)
    {
      my_fprintf(STDERR_FILENO, MSG_FAIL_DUP2);
      return (ID_FAIL_DUP2);
    }
  return (1);
}

int	xopen(const char *file, int flags, mode_t mode)
{
  int	ret;

  if ((ret = open(file, flags, mode)) == -1)
    {
      my_fprintf(STDERR_FILENO, MSG_FAIL_OPEN, file);
      return (ID_FAIL_OPEN);
    }
  return (ret);
}

int	xpipe(int fd[2])
{
  if (pipe(fd) == -1)
    {
      my_fprintf(STDERR_FILENO, MSG_FAIL_PIPE);
      return (ID_FAIL_PIPE);
    }
  return (1);
}
