/*
** parsing_alias.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue May  7 18:56:22 2013 kevin labbe
** Last update Fri May 17 14:54:49 2013 kevin labbe
*/

#include "proto.h"

static int	arraycat(char **dest, char **src1, char **src2)
{
  int		i;
  int		j;

  if (!dest || !src1 || !src2)
    return (-1);
  i = 0;
  j = 0;
  while (src1[j])
    dest[i++] = src1[j++];
  j = 1;
  while (src2[j])
    dest[i++] = src2[j++];
  dest[i] = NULL;
  return (1);
}

int		parsing_alias(t_cmd *cmd, t_data *data)
{
  t_alias	*alias;
  char		**args;
  int		new_len;

  if (!cmd->args[0] || !(alias = alias_get(data->alias, cmd->args[0])))
    return (0);
  new_len = count(cmd->args) - 1 + count(alias->args);
  if (!(args = my_alloc(new_len, sizeof(char *))))
    return (0);
  arraycat(args, alias->args, cmd->args);
  free(cmd->args);
  cmd->args = args;
  return (1);
}
