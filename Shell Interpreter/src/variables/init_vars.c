/*
** init_vars.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  2 11:15:22 2013 kevin labbe
** Last update Fri May 17 18:44:40 2013 kevin labbe
*/

#include "proto.h"

void	init_vars(t_data *data, char **vars)
{
  int	ret;

  data->delim = get_delimiters();
  data->builtins = get_builtins();
  data->redir_fct = get_redir_fct();
  data->env = env_fill(vars);
  list_create(&data->local);
  list_create(&data->alias);
  list_create(&data->redir);
  data->nbr_cmds = 1;
  data->ret_val = 0;
  data->exit_prog = 0;
  data->exit_cmd = 0;
  parsing_file(CONFIG_FILE, data);
  if ((ret = catch_signals()) < 0)
    {
      data->ret_val = ret;
      data->exit_prog = 1;
    }
}
