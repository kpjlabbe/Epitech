/*
** alias_show.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue May  7 20:12:39 2013 kevin labbe
** Last update Tue May  7 20:12:47 2013 kevin labbe
*/

#include "proto.h"

void		alias_show(t_list *elt)
{
  t_alias	*alias;
  int		i;

  alias = elt->data;
  if (alias->name)
    my_printf("%s=", alias->name);
  if (alias->args)
    {
      i = 0;
      while (alias->args[i])
	my_printf("%s ", alias->args[i++]);
    }
  my_printf("\n");
}
