/*
** vars_del.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu Apr 25 18:22:44 2013 kevin labbe
** Last update Mon May  6 12:23:25 2013 kevin labbe
*/

#include "proto.h"

int		vars_del_var(t_list *list, char *name)
{
  t_list	*tmp;
  t_vars	*elt;

  if (!list)
    return (-1);
  tmp = list->next;
  while (tmp != list)
    {
      elt = tmp->data;
      if (!strcmp(elt->name, name))
	return (list_del_elt(tmp, &vars_del_elt));
      tmp = tmp->next;
    }
  return (0);
}

void		vars_del_elt(t_list *elt)
{
  if (((t_vars *)elt->data)->free)
    {
      free(((t_vars *)elt->data)->name);
      free(((t_vars *)elt->data)->val);
    }
  free(elt->data);
}

void		vars_free(t_list *list)
{
  list_del(list, &vars_del_elt);
  free(list);
}
