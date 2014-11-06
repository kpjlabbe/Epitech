/*
** my_sqrt.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:38:06 2013 kevin labbe
** Last update Tue Apr 23 14:38:13 2013 kevin labbe
*/

#include "my.h"

int	my_sqrt(const int nbr)
{
  int	i;
  
  i = 0;
  while (i <= nbr)
    {
      if ((i * i) > nbr)
	return (i - 1);
      i++;
    }
  return ((nbr == 1 || !nbr) ? nbr : i);
}
