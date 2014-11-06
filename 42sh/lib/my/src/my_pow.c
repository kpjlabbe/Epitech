/*
** my_pow.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:37:53 2013 kevin labbe
** Last update Tue Apr 23 14:37:59 2013 kevin labbe
*/

#include "my.h"

int	my_pow(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power > 0)
    return (nb *= my_pow(nb, power - 1));
  return (1);
}
