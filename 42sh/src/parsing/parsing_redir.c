/*
** filter_redirections.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sun May  5 11:05:53 2013 kevin labbe
** Last update Fri May 10 01:07:25 2013 kevin labbe
*/

#include "proto.h"

int		parsing_redir(t_cmd *cmd, t_data *data)
{
  int		i;
  int		j;
  char		*filename;
  char		**args;

  if (!(args = my_alloc(count(cmd->args), sizeof(char *))))
    return (0);
  i = 0;
  j = 0;
  while (cmd->args[i])
    {
      if (in_array(cmd->args[i], data->delim->redir) != -1)
	{
	  filename = (cmd->args[i + 1] ? cmd->args[i + 1] : 0);
	  redir_add(data->redir, cmd->args[i++], filename);
	  cmd->nbr_redir++;
	}
      else
	args[j++] = cmd->args[i];
      i++;
    }
  args[j] = NULL;
  free(cmd->args);
  cmd->args = args;
  return (1);
}
