/*
** strcpy_to.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:22:38 2013 kevin labbe
** Last update Tue Apr 23 15:11:49 2013 kevin labbe
*/

#include "my.h"

char	*my_strcpy_to(char *dest, char *src, char delimiter)
{
  int	index;

  index = 0;
  while (src[index] && src[index] != delimiter)
    {
      dest[index] = src[index];
      index++;
    }
  dest[index] = '\0';
  return (dest);
}
