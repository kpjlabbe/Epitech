/*
** alias_del.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
OB** Login   <labbe_k@epitech.net>
** 
** Started on  Tue May  7 20:11:10 2013 kevin labbe
** Last update Fri May 10 13:56:09 2013 pierre-antoine urvoy
*/

#include "proto.h"

int		alias_del_name(t_list *list, char *name)
{
  t_list	*tmp;
  t_alias	*elt;

  if (!list)
    return (0);
  tmp = list->next;
  while (tmp != list)
    {
      elt = tmp->data;
      if (!strcmp(elt->name, name))
	return (list_del_elt(tmp, &alias_del_elt));
      tmp = tmp->next;
    }
  return (0);
}

void		alias_del_elt(t_list *elt)
{
  if (((t_alias *)elt->data)->free)
    {
      free(((t_alias *)elt->data)->name);
      free(((t_alias *)elt->data)->val);
    }
  free(((t_alias *)elt->data)->args);
  free(elt->data);
}

void		alias_free(t_list *list)
{
  list_del(list, &alias_del_elt);
  free(list);
}
