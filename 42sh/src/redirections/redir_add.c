/*
** redir_add.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  9 11:21:44 2013 kevin labbe
** Last update Fri May 17 18:32:13 2013 kevin labbe
*/

#include "proto.h"

void		redir_add(t_list *list, char *type, char *filename)
{
  t_redir	*redir;

  if ((redir = my_alloc(1, sizeof(t_redir))))
    {
      redir->type = type;
      redir->filename = filename;
      redir->fdin = -1;
      redir->fdout = -1;
      list_ins_before(list, redir);
    }
}
