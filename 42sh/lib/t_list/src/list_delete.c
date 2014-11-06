/*
** list_delete.c for t_list in /media/data/all/projects/epitech/42sh/lib/t_list/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed Mar  6 18:01:07 2013 kevin labbe
** Last update Wed May  1 16:48:24 2013 kevin labbe
*/

#include "my.h"
#include "t_list.h"

int		list_del_elt(t_list *elt, t_fct_list *fct)
{
  if (!elt)
    return (-1);
  elt->prev->next = elt->next;
  elt->next->prev = elt->prev;
  if (fct)
    fct(elt);
  free(elt);
  return (1);
}

int		list_del_nth_elt(t_list *list, int pos, t_fct_list *fct)
{
  if (!list)
    return (-1);
  list_del_elt(list_get_elt(list, pos), fct);
  return (1);
}

int		list_del(t_list *list, t_fct_list *fct)
{
  int		i;

  if (!list)
    return (0);
  i = 0;
  while (list->next != list)
    {
      list_del_elt(list->next, fct);
      i++;
    }
  return (i);
}
