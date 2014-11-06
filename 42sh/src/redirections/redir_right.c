/*
** redir_right.c<2> for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sat May  4 19:29:52 2013 kevin labbe
** Last update Mon May 20 09:31:06 2013 kevin labbe
*/

#include "proto.h"

static int	file_access(char *file)
{
  struct stat	infos;

  if (access(file, F_OK) == -1)
    return (1);
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

int	redir_right(char *file, int fd)
{
  int	ret;

  if ((ret = file_access(file)) < 0)
    return (ret);
  if ((ret = xopen(file, O_CREAT | O_WRONLY | O_TRUNC, 0666)) < 0)
    return (ID_FAIL_OPEN);
  if (xdup2(ret, fd) != 1)
    return (ID_FAIL_DUP2);
  return (ret);
}

int	redir_double_right(char *file, int fd)
{
  int	ret;

  if ((ret = file_access(file)) < 0)
    return (ret);
  if ((ret = xopen(file, O_CREAT | O_WRONLY | O_APPEND, 0666)) < 0)
    return (ID_FAIL_OPEN);
  if (xdup2(ret, fd) != 1)
    return (ID_FAIL_DUP2);
  return (ret);
}
