/*
** my_putnbr_base.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:35:03 2013 kevin labbe
** Last update Tue Apr 30 18:34:44 2013 kevin labbe
*/

#include "my.h"

void	my_putnbr_base(const int fd, int nbr, char *base)
{
  int	reste;

  if (nbr < 0)
    {
      my_putchar(fd, '-');
      nbr *= -1;
    }
  reste = nbr % strlen(base);
  nbr /= strlen(base);
  if (nbr != 0)
    my_putnbr_base(fd, nbr, base);
  my_putchar(fd, base[reste]);
}
