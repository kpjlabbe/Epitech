/*
** list_foreach.c for t_list in /media/data/all/projects/42sh-v1/lib/t_list/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed Apr 24 17:17:56 2013 kevin labbe
** Last update Wed Apr 24 20:04:45 2013 kevin labbe
*/

#include "my.h"
#include "t_list.h"

int		list_foreach(t_list *list, t_fct_list *fct)
{
  t_list	*tmp;

  if (!list)
    return (-1);
  tmp = list->next;
  while (tmp != list)
    {
      fct(tmp);
      tmp = tmp->next;
    }
  return (0);
}
