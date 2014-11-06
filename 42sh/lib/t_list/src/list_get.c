/*
** list_get.c for t_list in /media/data/all/projects/epitech/42sh/lib/t_list/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed Mar  6 18:00:59 2013 kevin labbe
** Last update Wed Apr 24 19:10:08 2013 kevin labbe
*/

#include "my.h"
#include "t_list.h"

t_list		*list_get_elt(t_list *list, int pos)
{
  t_list	*tmp;
  int		i;

  if (!list)
    return (NULL);
  tmp = list->next;
  i = 0;
  while (tmp != list && i != pos)
    {
      i++;
      tmp = tmp->next;
    }
  if (i != pos || !tmp->data)
    return (NULL);
  return (tmp);
}

int		list_get_size(t_list *list)
{
  t_list	*tmp;
  int		i;

  if (!list)
    return (-1);
  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
