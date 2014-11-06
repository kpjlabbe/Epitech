/*
** builtin_local.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  9 04:14:31 2013 kevin labbe
** Last update Thu May  9 04:15:06 2013 kevin labbe
*/

#include "proto.h"

int	builtin_local(t_cmd *cmd, t_data *data)
{
  return (builtin_vars(cmd, data->local));
}

int	builtin_setlocal(t_cmd *cmd, t_data *data)
{
  return (builtin_setvars(cmd, data->local));
}

int	builtin_unsetlocal(t_cmd *cmd, t_data *data)
{
  return (builtin_unsetvars(cmd, data->local));
}
