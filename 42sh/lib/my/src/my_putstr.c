/*
** my_putstr.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:33:08 2013 kevin labbe
** Last update Tue Apr 23 14:33:19 2013 kevin labbe
*/

#include "my.h"

void	my_putstr(const int fd, char *str)
{
  while (*str)
    write(fd, str++, 1);
}
