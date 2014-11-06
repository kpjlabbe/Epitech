/*
** my_atoi.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:36:09 2013 kevin labbe
** Last update Tue Apr 23 14:36:17 2013 kevin labbe
*/

#include "my.h"

int	my_atoi(char *expr)
{
  return (my_atoi_base(expr, "0123456789"));
}
