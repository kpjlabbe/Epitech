/*
** builtin_alias.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Mon May  6 18:06:41 2013 kevin labbe
** Last update Fri May 17 17:44:13 2013 kevin labbe
*/

#include "proto.h"

int		builtin_alias(t_cmd *cmd, t_data *data)
{
  if (cmd->args[1])
    {
      if (cmd->args[1][0] && cmd->args[1][0] == '-')
	{
	  if (!strcmp(cmd->args[1], "-i"))
	    list_del(data->alias, &alias_del_elt);
	  if (!strcmp(cmd->args[1], "--help"))
	    my_printf(MSG_ALIAS_HELP);
	}
      else
	return (builtin_alias_opt_print(cmd, data->alias));
    }
  else
    list_foreach(data->alias, &alias_show);
  return (1);
}

int		builtin_alias_opt_print(t_cmd *cmd, t_list *list)
{
  int		i;
  t_alias	*elt;
  int		j;

  i = 1;
  while (cmd->args[i])
    {
      if ((elt = alias_get(list, cmd->args[i])))
	{
	  my_printf("%s=", cmd->args[i]);
	  j = 0;
	  while (elt->args[j])
	    my_printf("%s ", elt->args[j++]);
	  my_printf("\n");
	}
      else
	{
	  my_fprintf(STDERR_FILENO, MSG_ALIAS_NOT_EXISTS, cmd->args[i]);
	  return (-1);
	}
      i++;
    }
  return (1);
}
