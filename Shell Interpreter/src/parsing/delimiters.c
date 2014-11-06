/*
** delimiters.c for 42svh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 14:14:08 2013 kevin labbe
** Last update Fri May 17 17:14:51 2013 kevin labbe
*/

#include "proto.h"

char		*get_next_delim(t_delim *delim, char *line)
{
  int		ret;

  if ((ret = get_next_delim_as(delim->sepa, line)) >= 0)
    return (delim->sepa[ret]);
  return (NULL);
}

int		get_next_delim_as(char **delim, char *line)
{
  size_t	nbr_chr;
  int		i;

  nbr_chr = my_strlen_to(line, ' ');
  i = 0;
  while (delim[i])
    {
      if (!strncmp(line, delim[i], nbr_chr)
	  && (strlen(delim[i]) == nbr_chr))
	return (i);
      i++;
    }
  return (-1);
}

t_delim		*get_delimiters(void)
{
  t_delim	*delim;

  if (!(delim = my_alloc(1, sizeof(t_delim))))
    return (NULL);
  set_separators(delim);
  set_redirections(delim);
  return (delim);
}

void		set_separators(t_delim *delim)
{
  delim->sepa[0] = DELIM_SEPA;
  delim->sepa[1] = DELIM_PIPE;
  delim->sepa[2] = DELIM_OR;
  delim->sepa[3] = DELIM_AND;
  delim->sepa[4] = NULL;
}

void		set_redirections(t_delim *delim)
{
  delim->redir[0] = REDIR_LEFT;
  delim->redir[1] = REDIR_DBL_LEFT;
  delim->redir[2] = REDIR_RIGHT;
  delim->redir[3] = REDIR_DBL_RIGHT;
  delim->redir[4] = REDIR_RIGHT_OUT;
  delim->redir[5] = REDIR_RIGHT_ERR;
  delim->redir[6] = REDIR_DBL_RIGHT_OUT;
  delim->redir[7] = REDIR_DBL_RIGHT_ERR;
  delim->redir[8] = REDIR_ERR_TO_OUT;
  delim->redir[9] = NULL;
}
