/*
** strlen_to.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:21:56 2013 kevin labbe
** Last update Tue Apr 23 15:35:33 2013 kevin labbe
*/

#include "my.h"

int	my_strlen_to(char *str, char delimiter)
{
  int	i;
  
  i = 0;
  while (str[i] && str[i] != delimiter)
    i++;
  return (i);
}
