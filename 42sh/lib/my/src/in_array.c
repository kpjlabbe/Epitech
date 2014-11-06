/*
** in_array.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:40:08 2013 kevin labbe
** Last update Sun May  5 18:11:21 2013 kevin labbe
*/

#include "my.h"

int	in_array(char *val, char **array)
{
  int	i;

  if (!val || !array)
    return (-1);
  i = 0;
  while (array[i])
    {
      if (strcmp(val, array[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}
