/*
** get_commands.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  2 11:39:03 2013 kevin labbe
** Last update Fri May 17 16:22:25 2013 kevin labbe
*/

#include "proto.h"

static int	init_cmd_vars(t_data *data)
{
  if (!(xmemset(data->pipe_old, -1, 2)) || !(xmemset(data->pipe_new, -1, 2)))
    return (ID_FAIL_MEMSET);
  data->exit_cmd = 0;
  env_load_protected_vars(data->env);
  return (0);
}

char		*get_commands(const int fd, t_data *data)
{
  char		*line;

  if (data->exit_prog || (!data->ret_val < 0))
    return (NULL);
  init_cmd_vars(data);
  print_prompt(data);
  if (!(line = get_next_line(fd)))
    {
      my_printf("exit\n");
      return (NULL);
    }
  data->cmdlist = parsing_line(line, data->delim);
  parsing_commands(data);
  data->nbr_cmds++;
  return (line);
}
