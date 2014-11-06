/*
** builtin_source.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Wed May  8 14:26:57 2013 kevin labbe
** Last update Fri May 17 17:21:29 2013 kevin labbe
*/

#include "proto.h"

int	builtin_source(t_cmd *cmd, t_data *data)
{
  int	i;

  if (!cmd->args[1] || !strcmp(cmd->args[1], "--help"))
    {
      my_fprintf(STDOUT_FILENO, MSG_SOURCE_HELP);
      return (1);
    }
  i = 1;
  while (cmd->args[i])
    {
      if (parsing_file(cmd->args[i], data) == -1)
  	{
  	  my_fprintf(STDERR_FILENO, MSG_SOURCE_NO_FILE, cmd->args[1]);
  	  return (-1);
  	}
      i++;
    }
  return (1);
}
