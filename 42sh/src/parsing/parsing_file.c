/*
** parsing_file.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  8 14:28:21 2013 kevin labbe
** Last update Mon May 20 09:55:04 2013 kevin labbe
*/

#include "proto.h"

static char	*get_file_cmds(const int fd, t_data *data)
{
  char		*line;

  if (data->exit_prog || (!data->ret_val < 0))
    return (NULL);
  data->exit_cmd = 0;
  env_load_protected_vars(data->env);
  if (!(line = get_next_line(fd)))
    return (NULL);
  data->cmdlist = parsing_line(line, data->delim);
  parsing_commands(data);
  return (line);
}

static	void	dup_data(t_data *dest, t_data *src)
{
  dest->delim = src->delim;
  dest->builtins = src->builtins;
  dest->env = src->env;
  dest->local = src->local;
  dest->alias = src->alias;
  dest->nbr_cmds = 0;
  dest->ret_val = 0;
  dest->exit_prog = 0;
  dest->exit_cmd = 0;
}

int		parsing_file(char *filename, t_data *data)
{
  int		fd;
  char		*line;
  t_data	datadup;

  if ((fd = xopen(filename, O_RDONLY, 0666)) < 0)
    return (ID_FAIL_OPEN);
  dup_data(&datadup, data);
  while ((line = get_file_cmds(fd, &datadup)))
    {
      if (line[0] && line[0] != '#')
	{
	  if (!datadup.exit_cmd)
	    cmd_processing(&datadup);
	  cmd_free(datadup.cmdlist, line);
	}
      else
	free(line);
    }
  close(fd);
  return (0);
}
