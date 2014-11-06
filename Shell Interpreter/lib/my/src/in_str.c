/*
** in_str.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:26:16 2013 kevin labbe
** Last update Tue Apr 23 14:26:23 2013 kevin labbe
*/

#include "my.h"

int	in_str(char chr, char *str)
{
  while (*str)
    {
      if (chr == *str)
	return (1);
      str++;
    }
  return (0);
}
