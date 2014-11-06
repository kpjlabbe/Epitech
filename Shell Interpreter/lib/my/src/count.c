/*
** count.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:40:19 2013 kevin labbe
** Last update Tue Apr 23 14:40:27 2013 kevin labbe
*/

#include "my.h"

int	count(char **array)
{
  int	i;
  
  i = 0;
  while (array[i])
    i++;
  return (i);
}
