/*
** free_all.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  9 01:40:10 2013 kevin labbe
** Last update Thu May  9 23:44:48 2013 kevin labbe
*/

#include "proto.h"

void	free_all(t_data *data)
{
  vars_free(data->env);
  vars_free(data->local);
  alias_free(data->alias);
  redir_free(data->redir);
  free(data->delim);
  free(data->builtins);
  free(data->redir_fct);
}
