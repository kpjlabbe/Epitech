/*
** builtin_env.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  9 04:10:37 2013 kevin labbe
** Last update Thu May  9 04:13:41 2013 kevin labbe
*/

#include "proto.h"

int	builtin_env(t_cmd *cmd, t_data *data)
{
  return (builtin_vars(cmd, data->env));
}

int	builtin_setenv(t_cmd *cmd, t_data *data)
{
  return (builtin_setvars(cmd, data->env));
}

int	builtin_unsetenv(t_cmd *cmd, t_data *data)
{
  return (builtin_unsetvars(cmd, data->env));
}
