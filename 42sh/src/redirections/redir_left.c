/*
** redir_left.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sun May  5 21:46:48 2013 kevin labbe
** Last update Mon May 20 09:31:15 2013 kevin labbe
*/

#include "proto.h"

static int	file_access(char *file)
{
  struct stat	infos;

  if (access(file, F_OK) == -1)
    {
      my_fprintf(2, MSG_FILE_NOT_EXISTS, file);
      return (-1);
    }
  if (access(file, F_OK | W_OK) == -1)
    {
      my_fprintf(STDERR_FILENO, MSG_FILE_PERMS_DENIED, file);
      return (ID_FAIL_PERMS_DENIED);
    }
  if ((stat(file, &infos) == -1))
    {
      my_fprintf(STDERR_FILENO, MSG_FAIL_STAT);
      return (ID_FAIL_STAT);
    }
  if ((S_ISDIR(infos.st_mode)))
    {
      my_fprintf(STDERR_FILENO, MSG_FILE_IS_DIR, file);
      return (ID_FAIL_FILE_IS_DIR);
    }
  return (1);
}

int		redir_left(char *file, int fd)
{
  int		ret;

  if ((ret = file_access(file)) < 0)
    return (ret);
  if ((ret = xopen(file, O_RDONLY, 0666)) < 0)
    return (ID_FAIL_OPEN);
  if (xdup2(ret, fd) != 1)
    return (ID_FAIL_DUP2);
  return (ret);
}

int		redir_double_left(char *keyword, int fd)
{
  char		*arg;
  int		fd_pipe[2];
  int		exit_loop;

  if (!keyword)
    return (-1);
  if (xpipe(fd_pipe) != 1)
    return (ID_FAIL_PIPE);
  my_printf(REDIR_LEFT_PROMPT);
  exit_loop = 0;
  while (!exit_loop && (arg = get_next_line(STDIN_FILENO)))
    {
      if (!strcmp(keyword, arg))
	exit_loop = 1;
      else
	{
	  my_printf(REDIR_LEFT_PROMPT);
	  my_fprintf(fd_pipe[PIPE_OUT], "%s\n", arg);
	}
      free(arg);
    }
  if (xdup2(fd_pipe[PIPE_IN], fd) != 1)
    return (ID_FAIL_DUP2);
  return (fd_pipe[PIPE_OUT]);
}
