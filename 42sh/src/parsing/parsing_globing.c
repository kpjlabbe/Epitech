/*
** parsing_globing.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  8 17:16:03 2013 kevin labbe
** Last update Fri May 17 14:52:19 2013 kevin labbe
*/

#include "proto.h"

static void	arraycat(char **dest, int *i, glob_t *g)
{
  size_t	j;

  j = 0;
  while (j < g->gl_pathc)
    dest[(*i)++] = g->gl_pathv[j++];
  dest[*i] = NULL;
}

static char	**processing_globing(t_cmd *cmd, int i, char **args, int *j)
{
  int		len;
  glob_t	g;

  if (glob(cmd->args[i], MY_GLOB_FLAGS, NULL, &g) != GLOB_NOMATCH)
    {
      len = count(args) + g.gl_pathc;
      if (!(args = my_realloc(args, len, sizeof(char *))))
	return (NULL);
      arraycat(args, j, &g);
      free(g.gl_pathv);
    }
  else
    {
      len = count(args);
      if (!(args = my_realloc(args, len + 1, sizeof(char *))))
	return (NULL);
      if (!(args[(*j)++] = xstrdup(cmd->args[i])))
	return (NULL);
    }
  return (args);
}

int		parsing_globing(t_cmd *cmd)
{
  int		i;
  int		j;
  char		**args;

  if (!cmd->args[0] || !(args = my_alloc(1, sizeof(char *))))
    return (0);
  if (!(args[0] = xstrdup(cmd->args[0])))
    return (0);
  args[1] = NULL;
  i = 1;
  j = 1;
  while (cmd->args[i])
    {
      if (!(args = processing_globing(cmd, i++, args, &j)))
	return (0);
      args[j] = NULL;
    }
  free(cmd->args);
  cmd->args = args;
  return (0);
}
