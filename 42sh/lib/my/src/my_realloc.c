/*
** my_realloc.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/memory
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:16:30 2013 kevin labbe
** Last update Fri May 17 14:46:09 2013 kevin labbe
*/

#include "my.h"

void	*my_realloc(void *ptr, int nbr_elts, int bytes)
{
  void	*new_ptr;

  new_ptr = NULL;
  if (!(new_ptr = realloc(ptr, (nbr_elts + 1) * bytes)))
    {
      my_fprintf(STDERR_FILENO, MSG_FAIL_REALLOC);
      return (NULL);
    }
  ptr = new_ptr;
  return (new_ptr);
}
