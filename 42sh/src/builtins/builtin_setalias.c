/*
** builtin_setalias.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue May  7 16:20:38 2013 kevin labbe
** Last update Fri May 17 18:29:49 2013 kevin labbe
*/

#include "proto.h"

int	builtin_setalias(t_cmd *cmd, t_data *data)
{
  if (cmd->args[1])
    {
      if (!strncmp(cmd->args[1], "--", 2))
	{
	  if (!strcmp(cmd->args[1], "--safe"))
	    builtin_setvars_base(cmd, data->alias, &builtin_setalias_safe);
	  if (!strcmp(cmd->args[1], "--help"))
	    my_printf(MSG_SETALIAS_HELP);
	}
      else
	return (builtin_setvars_base(cmd, data->alias, &builtin_setalias_new));
    }
  else
    {
      my_fprintf(STDERR_FILENO, MSG_SETALIAS_HELP);
      return (-1);
    }
  return (1);
}

int	builtin_setalias_new(t_vars *var, t_list *list)
{
  char	*name;
  char	*val;

  alias_del_name(list, var->name);
  if (!(name = strdup(var->name)) || !(val = strdup(var->val)))
    return (ID_FAIL_STRDUP);
  alias_add(list, name, val, 1);
  return (0);
}

int	builtin_setalias_safe(t_vars *var, t_list *list)
{
  char	*name;
  char	*val;

  if (!alias_get(list, var->name))
    {
      if (!(name = strdup(var->name)) || !(val = strdup(var->val)))
	return (ID_FAIL_STRDUP);
      alias_add(list, name, val, 1);
    }
  else
    {
      my_fprintf(STDERR_FILENO, MSG_SETENV_VAR_EXISTS, var->name);
      return (-1);
    }
  return (0);
}
