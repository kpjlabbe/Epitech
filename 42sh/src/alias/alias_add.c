/*
** alias_add.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue May  7 20:11:40 2013 kevin labbe
** Last update Fri May 17 17:44:41 2013 kevin labbe
*/

#include "proto.h"

void		alias_add(t_list *list, char *name, char *val, char free_status)
{
  t_alias	*alias;

  if ((alias = my_alloc(1, sizeof(t_alias))))
    {
      alias->name = name;
      alias->val = val;
      alias->args = cmd_get_args(alias->val);
      alias->free = free_status;
      list_ins_before(list, alias);
    }
}
