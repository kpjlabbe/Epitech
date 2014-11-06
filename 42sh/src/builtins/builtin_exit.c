/*
** builtin_exit.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  1 19:09:31 2013 kevin labbe
** Last update Thu May  2 11:32:24 2013 kevin labbe
*/

#include "proto.h"

int	builtin_exit(t_cmd *cmd, t_data *data)
{
  data->exit_prog = 1;
  if (cmd->args[1])
    data->ret_val = my_atoi(cmd->args[1]);
  else
    data->ret_val = 0;
  return (data->ret_val);
}
