/*
** builtin_cd.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  1 10:19:47 2013 kevin labbe
** Last update Fri May 17 18:25:00 2013 kevin labbe
*/

#include "proto.h"

int	builtin_cd(t_cmd *cmd, t_data *data)
{
  if (!cmd->args[1])
    if (!(cmd->args[1] = strdup(vars_get_val(data->env, "HOME"))))
      return (ID_FAIL_STRDUP);
  create_pwd_vars(data);
  if (!strcmp(cmd->args[1], "-"))
    if (!(cmd->args[1] = strdup(vars_get_val(data->env, "OLDPWD"))))
      return (ID_FAIL_STRDUP);
  if ((xchdir(cmd->args[1]) == -1))
    return (-1);
  update_pwd_vars(data);
  return (1);
}

int	create_pwd_vars(t_data *data)
{
  char	*pwd;
  char	*name;
  char	*val;

  pwd = xgetcwd();
  if (pwd && !vars_get_var(data->env, "PWD"))
    {
      if (!(name = strdup("PWD")) || !(val = strdup(pwd)))
	return (ID_FAIL_STRDUP);
      vars_add_var(data->env, name, val, 1);
    }
  if (pwd && !vars_get_var(data->env, "OLDPWD"))
    {
      if (!(name = strdup("OLDPWD")))
	return (ID_FAIL_STRDUP);
      vars_add_var(data->env, name, pwd, 1);
    }
  return (0);
}

int	update_pwd_vars(t_data *data)
{
  char	*pwd;
  char	*name;
  char	*val;

  if ((pwd = vars_get_val(data->env, "PWD")))
    {
      if (!(name = strdup("OLDPWD")) || !(val = strdup(pwd)))
	return (ID_FAIL_STRDUP);
      vars_set_val(data->env, name, val, 1);
    }
  if ((pwd = xgetcwd()))
    {
      if (!(name = strdup("PWD")) || !(val = strdup(pwd)))
	return (ID_FAIL_STRDUP);
      vars_set_val(data->env, name, val, 1);
    }
  return (0);
}
