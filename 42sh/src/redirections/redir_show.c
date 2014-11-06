/*
** redir_show.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  9 11:27:14 2013 kevin labbe
** Last update Thu May  9 18:30:50 2013 kevin labbe
*/

#include "proto.h"

void		redir_show(t_list *elt)
{
  t_redir	*redir;

  redir = elt->data;
  if (redir->type)
    my_printf("type=%s\n", redir->type);
  if (redir->filename)
    my_printf("filename=%s\n", redir->filename);
  if (redir->fdin)
    my_printf("fdin=%d\n", redir->fdin);
  if (redir->fdout)
    my_printf("fdout=%d\n", redir->fdout);
  my_printf("\n");
}
