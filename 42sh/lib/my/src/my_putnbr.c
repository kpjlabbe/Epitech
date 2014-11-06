/*
** my_putnbr.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:35:18 2013 kevin labbe
** Last update Tue Apr 23 14:35:27 2013 kevin labbe
*/

#include "my.h"

void	my_putnbr(const int fd, int nbr)
{
  my_putnbr_base(fd, nbr, "0123456789");
}
