/*
** alias_get.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue May  7 20:12:25 2013 kevin labbe
** Last update Fri May 10 02:02:19 2013 kevin labbe
*/

#include "proto.h"

t_alias		*alias_get(t_list *list, char *name)
{
  t_list	*tmp;
  t_alias	*elt;

  if (!list)
    return (NULL);
  tmp = list->next;
  while (tmp != list)
    {
      elt = tmp->data;
      if (!strcmp(elt->name, name))
	return (elt);
      tmp = tmp->next;
    }
  return (NULL);
}
