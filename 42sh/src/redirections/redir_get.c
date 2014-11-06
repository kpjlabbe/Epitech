/*
** redir_get.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Fri May 10 01:56:57 2013 kevin labbe
** Last update Fri May 10 02:01:22 2013 kevin labbe
*/

#include "proto.h"

int		redir_get_nbr_of(t_list *list, char *type)
{
  t_list	*tmp;
  t_redir	*elt;
  int		i;

  i = 0;
  if (!list)
    return (i);
  tmp = list->next;
  while (tmp != list)
    {
      elt = tmp->data;
      if (!strcmp(elt->type, type))
	i++;
      tmp = tmp->next;
    }
  return (i);
}
