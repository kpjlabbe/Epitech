/*
** free_array.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:39:47 2013 kevin labbe
** Last update Sat May  4 16:51:21 2013 kevin labbe
*/

#include "my.h"

void	free_array(char **array)
{
  int	word;
  
  word = 0;
  while (array[word])
    {
      free(array[word]);
      word++;
    }
  free(array);
}
