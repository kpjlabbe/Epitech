/*
** cmd_del.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 15:53:49 2013 kevin labbe
** Last update Thu May  9 01:02:58 2013 kevin labbe
*/

#include "proto.h"

void		cmd_del_elt(t_list *elt)
{
  t_cmd		*cmd;
  int		i;

  cmd = elt->data;
  i = 0;
  while (cmd->args[i])
    free(cmd->args[i++]);
  free(cmd->args);
  free(elt->data);
}

void		cmd_free(t_list *list, char *line)
{
  list_del(list, &cmd_del_elt);
  free(list);
  free(line);
}
