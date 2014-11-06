/*
** builtin_setvars.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  1 16:51:31 2013 kevin labbe
** Last update Fri May 17 18:24:05 2013 kevin labbe
*/

#include "proto.h"

int		builtin_setvars(t_cmd *cmd, t_list *vars)
{
  if (cmd->args[1])
    {
      if (!strncmp(cmd->args[1], "--", 2))
	{
	  if (!strcmp(cmd->args[1], "--safe"))
	    builtin_setvars_base(cmd, vars, &builtin_setvars_safe);
	  if (!strcmp(cmd->args[1], "--help"))
	    my_printf(MSG_SETENV_HELP);
	}
      else
	return (builtin_setvars_base(cmd, vars, &builtin_setvars_vars));
    }
  else
    {
      my_fprintf(STDERR_FILENO, MSG_SETENV_HELP);
      return (-1);
    }
  return (1);
}

int		builtin_setvars_base(t_cmd *cmd, t_list *vars,
				     int (*fct)(t_vars *, t_list *))
{
  t_vars	*var;
  int		i;

  i = (!strcmp(cmd->args[1], "--safe") ? 2 : 1);
  while (cmd->args[i])
    {
      var = vars_split_var(cmd->args[i]);
      if (var->name && (!var->val || !strcmp(var->val, "")))
	{
	  my_fprintf(STDERR_FILENO, MSG_SETENV_VAR_EMPTY, var->name);
	  return (-1);
	}
      else
	if (fct(var, vars) < 0)
	  {
	    free(var);
	    return (-1);
	  }
      free(var);
      i++;
    }
  return (1);
}

int		builtin_setvars_vars(t_vars *var,  t_list *vars)
{
  char		*name;
  char		*val;

  vars_del_var(vars, var->name);
  if (!(name = strdup(var->name)) || !(val = strdup(var->val)))
    return (ID_FAIL_STRDUP);
  vars_add_var(vars, name, val, 1);
  return (0);
}

int		builtin_setvars_safe(t_vars *var, t_list *vars)
{
  char		*name;
  char		*val;

  if (!vars_get_var(vars, var->name))
    {
      if (!(name = strdup(var->name)) || !(val = strdup(var->val)))
	return (ID_FAIL_STRDUP);
      vars_add_var(vars, name, val, 1);
    }
  else
    {
      my_fprintf(STDERR_FILENO, MSG_SETENV_VAR_EXISTS, var->name);
      return (-1);
    }
  return (0);
}
