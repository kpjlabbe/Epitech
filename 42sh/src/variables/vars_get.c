/*
** vars_get.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu Apr 25 18:22:07 2013 kevin labbe
** Last update Thu May  9 23:31:33 2013 kevin labbe
*/

#include "proto.h"

t_vars		*vars_get_var(t_list *list, char *name)
{
  t_list	*tmp;
  t_vars	*elt;

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

char		*vars_get_val(t_list *list, char *name)
{
  t_vars	*elt;

  if (!list)
    return (NULL);
  if (!(elt = vars_get_var(list, name)))
    return (NULL);
  return (elt->val);
}

char		**vars_get_array(t_list *list)
{
  t_list	*tmp;
  t_vars	*elt;
  char		**array;
  int		i;
  int		len_line;

  if (!list || !(array = my_alloc(list_get_size(list), sizeof(char *))))
    return (NULL);
  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      elt = tmp->data;
      len_line = strlen(elt->name) + strlen(elt->val) + 1;
      array[i] = my_alloc(len_line, sizeof(char));
      strcat(array[i], elt->name);
      strcat(array[i], "=");
      strcat(array[i], elt->val);
      array[i][len_line] = '\0';
      i++;
      tmp = tmp->next;
    }
  array[i] = NULL;
  return (array);
}
