/*
** my_execvp.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Fri May  3 15:29:15 2013 kevin labbe
** Last update Mon May 20 10:04:36 2013 kevin labbe
*/

#include "proto.h"

static int	testing_path(char **args, char **vars, char **path, int *i)
{
  int		len_path;
  int		len_arg;
  char		*cmdname;

  len_path = strlen(path[*i]);
  len_arg = strlen(args[0]);
  if (!(cmdname = my_alloc(len_path + len_arg + 1, sizeof(char))))
    return (ID_FAIL_ALLOC);
  if (!xstrcat(cmdname, path[*i]) ||
      !xstrcat(cmdname, "/") ||
      !xstrcat(cmdname, args[0]))
    return (ID_FAIL_STRCAT);
  if (execve(cmdname, args, vars) > 0)
    {
      free_array(path);
      free(cmdname);
      return (1);
    }
  free(cmdname);
  return (0);
}

static int	check_path(char **args, char **vars, char **path)
{
  int		i;
  int		ret;

  i = 0;
  while (path[i])
    {
      if ((ret = testing_path(args, vars, path, &i)) != 0)
	return (ret);
      i++;
    }
  free_array(path);
  return (0);
}

int		my_execvp(t_cmd *cmd, t_data *data)
{
  char		**vars;
  char		**path;
  char		*val;

  if (!data->env || !(val = vars_get_val(data->env, "PATH")) || !cmd->args[0])
    return (0);
  vars = vars_get_array(data->env);
  if (!xstrcat(val, ":."))
    return (ID_FAIL_STRCAT);
  path = explode(":", val);
  if ((cmd->args[0][0] == '/' && execve(cmd->args[0], cmd->args, vars) == -1)
      || (cmd->args[0][0] != '/' && !check_path(cmd->args, vars, path)))
    {
      free_array(vars);
      return (0);
    }
  free_array(vars);
  return (1);
}
