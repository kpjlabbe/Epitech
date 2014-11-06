/*
** vars_add.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Mon May  6 09:21:53 2013 kevin labbe
** Last update Fri May 10 14:12:19 2013 pierre-antoine urvoy
*/

#include "proto.h"

t_vars		*vars_split_var(char *vars)
{
  t_vars	*var;
  int		i;

  if (!(var = my_alloc(1, sizeof(t_vars))))
    return (NULL);
  i = 0;
  while (vars[i] && vars[i] != '=')
    i++;
  vars[i++] = '\0';
  var->name = &vars[0];
  var->val = &vars[i];
  return (var);
}

int		vars_add_var(t_list *list, char *name, char *val,
			     char free_status)
{
  t_vars	*vars;

  if (!(vars = my_alloc(1, sizeof(t_vars))))
    return (0);
  vars->name = name;
  vars->val = val;
  vars->free = free_status;
  list_ins_before(list, vars);
  return (1);
}
