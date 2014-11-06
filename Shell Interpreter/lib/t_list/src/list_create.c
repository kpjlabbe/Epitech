/*
** list_create.c for t_list in /media/data/all/projects/epitech/42sh/lib/t_list/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed Mar  6 18:00:37 2013 kevin labbe
** Last update Thu May  2 17:27:42 2013 kevin labbe
*/

#include "my.h"
#include "t_list.h"

void		list_create(t_list **list)
{
  t_list	*root;

  root = my_alloc(1, sizeof(t_list));
  root->data = NULL;
  root->prev = root;
  root->next = root;
  *list = root;
}
