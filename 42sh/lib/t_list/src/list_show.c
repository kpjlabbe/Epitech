/*
** list_show.c for t_list in /media/data/all/projects/epitech/42sh/lib/t_list/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed Mar  6 18:00:45 2013 kevin labbe
** Last update Thu Mar  7 02:48:08 2013 kevin labbe
*/

#include "my.h"
#include "t_list.h"

int		list_show(t_list *list)
{
  t_list	*tmp;

  if (!list)
    return (-1);
  tmp = list->next;
  while (tmp != list)
    {
      my_printf("%s\n", tmp->str);
      tmp = tmp->next;
    }
  return (0);
}
