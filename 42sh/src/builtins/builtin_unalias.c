/*
** builtin_unalias.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue May  7 17:31:46 2013 kevin labbe
** Last update Fri May 17 17:21:08 2013 kevin labbe
*/

#include "proto.h"

int	builtin_unalias(t_cmd *cmd, t_data *data)
{
  if (cmd->args[1])
    {
      if (!strncmp(cmd->args[1], "--", 2))
	{
	  if (!strcmp(cmd->args[1], "--all"))
	    list_del(data->alias, &alias_del_elt);
	  if (!strcmp(cmd->args[1], "--help"))
	    my_printf(MSG_UNALIAS_HELP);
	}
      else
	return (builtin_unalias_name(cmd, data->alias));
    }
  else
    {
      my_fprintf(STDERR_FILENO, MSG_UNALIAS_HELP);
      return (-1);
    }
  return (1);
}

int	builtin_unalias_name(t_cmd *cmd, t_list *list)
{
  int	i;

  i = 1;
  while (cmd->args[i])
    {
      if (!alias_del_name(list, cmd->args[i]))
	{
	  my_fprintf(STDERR_FILENO, MSG_ALIAS_NOT_EXISTS, cmd->args[i]);
	  return (-1);
	}
      i++;
    }
  return (1);
}
