/*
** env_fill.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu Apr 25 18:19:17 2013 kevin labbe
** Last update Fri May 17 16:48:10 2013 kevin labbe
*/

#include "proto.h"

t_list		*env_fill(char **env)
{
  t_list	*list;
  int		i;
  t_vars	*var;

  list_create(&list);
  i = 0;
  while (env[i])
    {
      var = vars_split_var(env[i++]);
      vars_add_var(list, var->name, var->val, 0);
      free(var);
    }
  return (list);
}

int		env_load_protected_vars(t_list *vars)
{
  char		*name;
  char		*val;

  if (!vars_get_var(vars, "HOME"))
    {
      if (!(name = strdup("HOME")) || !(val = strdup(ENV_HOME)))
	return (ID_FAIL_STRDUP);
      vars_add_var(vars, name, val, 1);
    }
  if (!vars_get_var(vars, "PWD") && (val = xgetcwd()))
    {
      if (!(name = strdup("PWD")))
	return (ID_FAIL_STRDUP);
      vars_add_var(vars, name, val, 1);
    }
  if (!vars_get_var(vars, "PROMPT"))
    {
      if (!(name = strdup("PROMPT")) || !(val = strdup(ENV_PROMPT)))
	return (ID_FAIL_STRDUP);
      vars_add_var(vars, name, val, 1);
    }
  return (0);
}
