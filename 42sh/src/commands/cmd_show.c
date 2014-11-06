/*
** cmd_show.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 15:54:39 2013 kevin labbe
** Last update Thu May  9 23:41:22 2013 kevin labbe
*/

#include "proto.h"

void		cmd_show(t_list *elt)
{
  t_cmd		*cmd;
  int		i;

  cmd = elt->data;
  i = 0;
  while (cmd->args[i])
    {
      my_printf("arg n°%d: %s\n", i, cmd->args[i]);
      i++;
    }
  if (cmd->sepa)
    my_printf("sepa: %s\n", cmd->sepa);
  if (cmd->nbr_redir)
    my_printf("%d\n", cmd->nbr_redir);
  my_printf("\n");
}
