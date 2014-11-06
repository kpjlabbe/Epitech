/*
** builtin_unsetvars.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  1 15:51:52 2013 kevin labbe
** Last update Fri May 17 17:21:03 2013 kevin labbe
*/

#include "proto.h"

int	builtin_unsetvars(t_cmd *cmd, t_list *vars)
{
  if (cmd->args[1])
    {
      if (!strncmp(cmd->args[1], "--", 2))
	{
	  if (!strcmp(cmd->args[1], "--all"))
	    list_del(vars, &vars_del_elt);
	  if (!strcmp(cmd->args[1], "--help"))
	    my_printf(MSG_UNSETENV_HELP);
	}
      else
	return (builtin_unsetvars_vars(cmd, vars));
    }
  else
    {
      my_fprintf(STDERR_FILENO, MSG_UNSETENV_HELP);
      return (-1);
    }
  return (1);
}

int	builtin_unsetvars_vars(t_cmd *cmd, t_list *vars)
{
  int	i;

  i = 1;
  while (cmd->args[i])
    {
      if (!vars_del_var(vars, cmd->args[i]))
	{
	  my_fprintf(STDERR_FILENO, MSG_ENV_NO_VAR, cmd->args[i]);
	  return (-1);
	}
      i++;
    }
  return (1);
}
