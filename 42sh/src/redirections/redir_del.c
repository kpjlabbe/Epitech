/*
** redir_del.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  9 11:24:19 2013 kevin labbe
** Last update Thu May  9 11:26:56 2013 kevin labbe
*/

#include "proto.h"

void	redir_del_elt(t_list *elt)
{
  free(elt->data);
}

void	redir_free(t_list *list)
{
  list_del(list, &redir_del_elt);
  free(list);
}
