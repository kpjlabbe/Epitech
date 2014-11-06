/*
** builtin_set.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Mon May  6 11:44:29 2013 kevin labbe
** Last update Mon May  6 11:45:50 2013 kevin labbe
*/

#include "proto.h"

int	builtin_set(t_cmd *cmd, list *vars)
{
  return (builtin_setvars(cmd, vars));
}
