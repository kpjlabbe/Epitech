/*
** exec_redir.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sun May  5 17:46:08 2013 kevin labbe
** Last update Mon May 20 09:56:35 2013 kevin labbe
*/

#include "proto.h"

static int	processing_redir(t_redir *redir, t_data *data,
				 int *cur_dbl_left, int nbr_dbl_left)
{
  int		ret;

  if (!redir || !redir->filename)
    {
      my_fprintf(2, MSG_REDIR_ERROR);
      return (ID_FAIL_REDIR);
    }
  if ((ret = in_array(redir->type, data->delim->redir)) == -1)
    return (-1);
  if (ret == 5 || ret == 7)
    redir->fdin = (redir->fdin == -1) ? STDERR_FILENO : redir->fdin;
  else
    {
      if (ret >= 2 && ret <= 8)
	redir->fdin = (redir->fdin == -1) ? STDOUT_FILENO : redir->fdin;
      if (ret >= 0 && ret <= 1)
	redir->fdin = (redir->fdin == -1) ? STDIN_FILENO : redir->fdin;
    }
  if (ret != 1 || (ret == 1 && *cur_dbl_left == nbr_dbl_left))
    redir->fdout = data->redir_fct[ret](redir->filename, redir->fdin);
  if (ret == 1)
    (*cur_dbl_left)++;
  if (redir->fdout > 2)
    close(redir->fdout);
  return (0);
}

int		exec_redir(t_data *data)
{
  t_list	*tmp;
  t_redir	*redir;
  int		nbr_dbl_left;
  int		cur_dbl_left;

  if (!data->redir)
    return (-1);
  cur_dbl_left = 1;
  nbr_dbl_left = redir_get_nbr_of(data->redir, "<<");
  tmp = data->redir->next;
  while (tmp != data->redir)
    {
      if (!(redir = tmp->data))
	return (-1);
      processing_redir(redir, data, &cur_dbl_left, nbr_dbl_left);
      tmp = tmp->next;
    }
  return (0);
}

t_redir_fct	*get_redir_fct(void)
{
  t_redir_fct	*fct;

  if (!(fct = my_alloc(9, sizeof(t_redir))))
    return (NULL);
  fct[0] = &redir_left;
  fct[1] = &redir_double_left;
  fct[2] = &redir_right;
  fct[3] = &redir_double_right;
  fct[4] = &redir_right;
  fct[5] = &redir_right;
  fct[6] = &redir_double_right;
  fct[7] = &redir_double_right;
  fct[8] = &redir_right;
  return (fct);
}
