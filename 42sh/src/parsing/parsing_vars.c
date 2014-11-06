/*
** parsing_vars.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Mon May  6 11:57:30 2013 kevin labbe
** Last update Fri May 17 12:06:20 2013 kevin labbe
*/

#include "proto.h"

static char	*get_replacing_val(char *name, t_data *data)
{
  char		*val;

  if ((val = vars_get_val(data->local, name)))
    return (val);
  if ((val = vars_get_val(data->env, name)))
    return (val);
  return (name);
}

static int	replacing_vars(t_cmd *cmd, t_data *data, int i, int j)
{
  char		*search;
  char		*replace;
  int		len;

  len = my_strlen_to(&cmd->args[i][j + 1], '$') + 1;
  if (!(search = my_alloc(len, sizeof(char))))
    return (0);
  if (!xstrncat(search, &cmd->args[i][j], len))
    return (0);
  replace = get_replacing_val(&search[1], data);
  cmd->args[i] = str_replace(search, replace, cmd->args[i], 1);
  free(search);
  return (1);
}

int		parsing_vars(t_cmd *cmd, t_data *data)
{
  int		i;
  int		j;

  i = 0;
  while (cmd->args[i])
    {
      j = 0;
      while (cmd->args[i][j])
	{
	  if (cmd->args[i][j] == '$' && cmd->args[i][j + 1])
	    replacing_vars(cmd, data, i, j);
	  j++;
	}
      i++;
    }
  return (0);
}
