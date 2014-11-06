/*
** cmd_add.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 15:54:18 2013 kevin labbe
** Last update Fri May 17 18:31:55 2013 kevin labbe
*/

#include "proto.h"

void		cmd_add(t_list *list, char *line, char *delim)
{
  t_cmd		*cmd;

  if ((cmd = my_alloc(1, sizeof(t_cmd))))
    {
      cmd->args = cmd_get_args(line);
      cmd->sepa = delim;
      cmd->nbr_redir = 0;
      cmd->prev_sepa = NULL;
      list_ins_before(list, cmd);
    }
}

void		cmd_add_after(t_list *list, char *line, char *delim)
{
  t_cmd		*cmd;

  if ((cmd = my_alloc(1, sizeof(t_cmd))))
    {
      cmd->args = cmd_get_args(line);
      cmd->sepa = delim;
      cmd->nbr_redir = 0;
      list_ins_after(list, cmd);
    }
}
