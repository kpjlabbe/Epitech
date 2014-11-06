/*
** list_insert.c for t_list in /media/data/all/projects/epitech/42sh/lib/t_list/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed Mar  6 18:00:54 2013 kevin labbe
** Last update Wed Apr 24 19:16:59 2013 kevin labbe
*/

#include "my.h"
#include "t_list.h"

int		list_ins_before(t_list *elt, void *data)
{
  t_list	*tmp;

  tmp = my_alloc(1, sizeof(t_list));
  if (!data || !elt)
    return (-1);
  tmp->data = data;
  tmp->prev = elt->prev;
  tmp->next = elt;
  elt->prev->next = tmp;
  elt->prev = tmp;
  return (0);
}

int		list_ins_after(t_list *elt, void *data)
{
  t_list	*tmp;

  tmp = my_alloc(1, sizeof(t_list));
  if (!data || !elt)
    return (-1);
  tmp->data = data;
  tmp->prev = elt;
  tmp->next = elt->next;
  elt->next->prev = tmp;
  elt->next = tmp;
  return (0);
}
