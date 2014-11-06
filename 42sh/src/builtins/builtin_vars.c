/*
** builtin_vars.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  1 10:19:30 2013 kevin labbe
** Last update Fri May 17 17:20:07 2013 kevin labbe
*/

#include "proto.h"

int	builtin_vars(t_cmd *cmd, t_list *vars)
{
  if (cmd->args[1])
    {
      if (cmd->args[1][0] && cmd->args[1][0] == '-')
	{
	  if (!strcmp(cmd->args[1], "-i"))
	    list_del(vars, &vars_del_elt);
	  if (!strcmp(cmd->args[1], "--help"))
	    my_printf(MSG_ENV_HELP);
	}
      else
	return (builtin_vars_opt_print(cmd, vars));
    }
  else
    list_foreach(vars, &vars_show_var);
  return (1);
}

int	builtin_vars_opt_print(t_cmd *cmd, t_list *vars)
{
  int	i;
  char	*val;

  i = 1;
  while (cmd->args[i])
    {
      if ((val = vars_get_val(vars, cmd->args[i])))
	my_printf("%s=%s\n", cmd->args[i], val);
      else
	{
	  my_fprintf(STDERR_FILENO, MSG_ENV_NO_VAR, cmd->args[i]);
	  return (-1);
	}
      i++;
    }
  return (1);
}
