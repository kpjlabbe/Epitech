/*
** xmemory.c for 42sh in /home/labbe_k/Desktop/42sh/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Fri May 17 11:54:44 2013 kevin labbe
** Last update Fri May 17 16:33:46 2013 kevin labbe
*/

#include "proto.h"

void	*xmemcpy(void *dest, const void *src, size_t n)
{
  void	*ret;

  if (!(ret = memcpy(dest, src, n)))
    my_fprintf(STDERR_FILENO, MSG_FAIL_MEMCPY);
  return (ret);
}

void	*xmemset(void *s, int c, size_t n)
{
  void	*ret;

  if (!(ret = memset(s, c, n)))
    my_fprintf(STDERR_FILENO, MSG_FAIL_MEMSET);
  return (ret);
}

char	*xstrdup(const char *s)
{
  char	*ret;

  if (!(ret = strdup(s)))
    my_fprintf(STDERR_FILENO, MSG_FAIL_STRDUP);
  return (ret);
}
