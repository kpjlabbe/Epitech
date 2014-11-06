/*
** vars_show.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu Apr 25 18:31:28 2013 kevin labbe
** Last update Mon May  6 09:17:55 2013 kevin labbe
*/

#include "proto.h"

void		vars_show_var(t_list *elt)
{
  t_vars	*var;

  var = elt->data;
  my_printf("%s=%s\n", var->name, var->val);
}
