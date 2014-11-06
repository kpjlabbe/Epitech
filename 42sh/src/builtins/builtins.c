/*
** builtins.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  9 02:25:47 2013 kevin labbe
** Last update Fri May 17 17:43:06 2013 kevin labbe
*/

#include "proto.h"

t_builtins	*get_builtins(void)
{
  t_builtins	*builtins;

  if (!(builtins = my_alloc(1, sizeof(t_builtins))))
    return (NULL);
  set_builtins_idx(builtins);
  set_builtins_fct(builtins);
  return (builtins);
}

void		set_builtins_fct(t_builtins *builtins)
{
  builtins->fct[0] = &builtin_exit;
  builtins->fct[1] = &builtin_source;
  builtins->fct[2] = &builtin_alias;
  builtins->fct[3] = &builtin_setalias;
  builtins->fct[4] = &builtin_unalias;
  builtins->fct[5] = &builtin_cd;
  builtins->fct[6] = &builtin_env;
  builtins->fct[7] = &builtin_setenv;
  builtins->fct[8] = &builtin_unsetenv;
  builtins->fct[9] = &builtin_local;
  builtins->fct[10] = &builtin_setlocal;
  builtins->fct[11] = &builtin_unsetlocal;
  builtins->fct[12] = NULL;
}

void		set_builtins_idx(t_builtins *builtins)
{
  builtins->idx[0] = BUILTIN_EXIT;
  builtins->idx[1] = BUILTIN_SOURCE;
  builtins->idx[2] = BUILTIN_ALIAS;
  builtins->idx[3] = BUILTIN_SETALIAS;
  builtins->idx[4] = BUILTIN_UNALIAS;
  builtins->idx[5] = BUILTIN_CD;
  builtins->idx[6] = BUILTIN_ENV;
  builtins->idx[7] = BUILTIN_SETENV;
  builtins->idx[8] = BUILTIN_UNSETENV;
  builtins->idx[9] = BUILTIN_LOCAL;
  builtins->idx[10] = BUILTIN_SETLOCAL;
  builtins->idx[11] = BUILTIN_UNSETLOCAL;
  builtins->idx[12] = NULL;
}

int		is_builtin(t_cmd *cmd, t_data *data)
{
  int		ret;

  if (!cmd || !cmd->args || !data || !cmd->args[0])
    return (0);
  if ((ret = in_array(cmd->args[0], data->builtins->idx)) == -1)
    return (0);
  ret = data->builtins->fct[ret](cmd, data);
  data->ret_val = (ret == 1) ? 0 : ret;
  return (ret);
}
