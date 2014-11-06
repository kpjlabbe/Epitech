/*
** my_alloc.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/memory
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:16:09 2013 kevin labbe
** Last update Thu May  9 04:27:03 2013 kevin labbe
*/

#include "my.h"

void	*my_alloc(int nbr_elts, int bytes)
{
  void	*addr;

  if (!(addr = calloc(nbr_elts + 1, bytes)))
    {
      my_putstr(2, MSG_FAIL_MALLOC);
      return (NULL);
    }
  return (addr);
}
