/*
** is_number.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:37:28 2013 kevin labbe
** Last update Tue Apr 23 14:37:35 2013 kevin labbe
*/

#include "my.h"

int	is_number(char *str)
{
  int	i;
  
  i = 0;
  if (!str[0])
    return (0);
  if (str[0] == '-' && str[1])
    i = 1;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (0);
      i++;
    }
  return (1);
}
