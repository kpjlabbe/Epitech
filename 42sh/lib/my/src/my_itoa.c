/*
** my_itoa.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:36:44 2013 kevin labbe
** Last update Tue Apr 30 18:24:50 2013 kevin labbe
*/

#include "my.h"

char	*my_itoa(const int nbr)
{
  return (my_itoa_base(nbr, "0123456789"));
}
