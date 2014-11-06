/*
** filter_commands.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sun May  5 10:59:24 2013 kevin labbe
** Last update Fri May 10 01:17:50 2013 kevin labbe
*/

#include "proto.h"

int		parsing_commands(t_data *data)
{
  t_list	*tmp;
  t_cmd		*cmd;

  if (!data || !data->cmdlist)
    return (-1);
  tmp = data->cmdlist->next;
  while (!data->exit_prog && !data->exit_cmd && tmp != data->cmdlist)
    {
      if (!(cmd = tmp->data))
	return (1);
      if (cmd->args && cmd->args[0])
	parsing_redir(cmd, data);
      parsing_vars(cmd, data);
      parsing_alias(cmd, data);
      parsing_globing(cmd);
      tmp = tmp->next;
    }
  return (1);
}
