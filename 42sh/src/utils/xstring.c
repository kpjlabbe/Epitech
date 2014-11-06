/*
** xstring.c for 42sh in /home/labbe_k/Desktop/42sh/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Fri May 17 12:02:26 2013 kevin labbe
** Last update Fri May 17 16:33:30 2013 kevin labbe
*/

#include "proto.h"

char	*xstrcat(char *dest, const char *src)
{
  char	*ret;

  if (!(ret = strcat(dest, src)))
    my_fprintf(STDERR_FILENO, MSG_FAIL_STRCAT);
  return (ret);
}

char	*xstrncat(char *dest, const char *src, size_t n)
{
  char	*ret;

  if (!(ret = strncat(dest, src, n)))
    my_fprintf(STDERR_FILENO, MSG_FAIL_STRNCAT);
  return (ret);
}
