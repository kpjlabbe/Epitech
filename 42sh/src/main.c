/*
** main.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 15:32:59 2013 kevin labbe
** Last update Fri May 17 18:20:23 2013 kevin labbe
*/

#include "proto.h"

int		main(int ac, char **av, char **envp)
{
  t_data	data;
  char		*line;

  (void)ac;
  (void)av;
  init_vars(&data, envp);
  while ((line = get_commands(STDIN_FILENO, &data)))
    {
      if (!data.exit_cmd)
	cmd_processing(&data);
      cmd_free(data.cmdlist, line);
      list_del(data.redir, &redir_del_elt);
    }
  free_all(&data);
  return (data.ret_val);
}
