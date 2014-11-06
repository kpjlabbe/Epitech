/*
** vars_set.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu Apr 25 18:25:38 2013 kevin labbe
** Last update Mon May  6 09:15:30 2013 kevin labbe
*/

#include "proto.h"

int		vars_set_val(t_list *list, char *name, char *val,
			     char free_status)
{
  if (!list)
    return (-1);
  vars_del_var(list, name);
  vars_add_var(list, name, val, free_status);
  return (0);
}

int		vars_rename(t_list *list, char *oldname, char *newname)
{
  t_vars	*elt;

  if (!list)
    return (-1);
  if (!(elt = vars_get_var(list, oldname)))
    return (-1);
  elt->name = newname;
  return (0);
}
