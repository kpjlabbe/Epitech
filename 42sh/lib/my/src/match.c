/*
** match.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:38:30 2013 kevin labbe
** Last update Tue Apr 23 14:38:41 2013 kevin labbe
*/

#include "my.h"

int	match(char *src, char *pattern)
{
  int	i;
  int	j;
  
  i = strlen(src) - 1;
  j = strlen(pattern) - 1;
  while (i >= 0 && j >= 0)
    {
      if ((pattern[j] != '*') && (src[i] != pattern[j]))
	return (0);
      if (src[i] == pattern[j] ||
	  (pattern[j - 1] && src[i - 1] && src[i - 1] == pattern[j - 1]))
	j--;
      i--;
    }
  if (i >= 0 && j >= 0 && pattern[j] != '*')
    return (0);
  return (1);
}
