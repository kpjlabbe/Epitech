/*
** pipes.c<2> for 42sh in /home/labbe_k/Desktop/42sh
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May 16 09:26:40 2013 kevin labbe
** Last update Mon May 20 09:58:00 2013 kevin labbe
*/

#include "proto.h"

char	get_pipe_case(t_cmd *cmd)
{
  if (!cmd || !cmd->args || !cmd->args[0])
    return (PIPE_NONE);
  if (cmd->sepa && !strcmp(cmd->sepa, DELIM_PIPE) &&
      (!cmd->prev_sepa || strcmp(cmd->prev_sepa, DELIM_PIPE) != 0))
    return (PIPE_ONE_AFTER);
  if (cmd->sepa && !strcmp(cmd->sepa, DELIM_PIPE) &&
      cmd->prev_sepa && !strcmp(cmd->prev_sepa, DELIM_PIPE))
    return (PIPE_BOTH_SIDES);
  if ((!cmd->sepa || strcmp(cmd->sepa, DELIM_PIPE) != 0) &&
      cmd->prev_sepa && !strcmp(cmd->prev_sepa, DELIM_PIPE))
    return (PIPE_ONE_BEFORE);
  return (PIPE_NONE);
}

int	pipe_create(char pipe_case, t_data *data)
{
  if (!xmemcpy(data->pipe_old, data->pipe_new, sizeof(data->pipe_new)))
    return (ID_FAIL_MEMCPY);
  if (pipe_case != PIPE_ONE_AFTER && pipe_case != PIPE_BOTH_SIDES)
    return (0);
  if (xpipe(data->pipe_new) != 1)
    return (ID_FAIL_PIPE);
  return (0);
}

int	redir_pipe(char pipe_case, t_data *data)
{
  if (pipe_case == PIPE_NONE)
    return (-1);
  if (pipe_case == PIPE_ONE_AFTER || pipe_case == PIPE_BOTH_SIDES)
    {
      close(data->pipe_new[0]);
      if (xdup2(data->pipe_new[1], 1) != 1)
	return (ID_FAIL_DUP2);
      close(data->pipe_new[1]);
    }
  if (pipe_case == PIPE_ONE_BEFORE || pipe_case == PIPE_BOTH_SIDES)
    {
      close(data->pipe_old[1]);
      if (xdup2(data->pipe_old[0], 0) != 1)
	return (ID_FAIL_DUP2);
      close(data->pipe_old[0]);
    }
  return (0);
}

int	close_pipe(char pipe_case, t_data *data)
{
  if (pipe_case == PIPE_NONE)
    return (-1);
  if (pipe_case == PIPE_ONE_AFTER || pipe_case == PIPE_BOTH_SIDES)
    close(data->pipe_new[1]);
  if (pipe_case == PIPE_ONE_BEFORE || pipe_case == PIPE_BOTH_SIDES)
    close(data->pipe_old[0]);
  return (0);
}
