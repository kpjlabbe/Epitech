/*
** my_trim.c for lib in /media/data/all/projects/epitech/42sh
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu Mar  7 01:43:31 2013 kevin labbe
** Last update Mon Apr  8 11:09:19 2013 kevin labbe
*/

#include "my.h"

char	*trim(char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!src || !src[j])
    return (NULL);
  while (src[j] && (src[j] == ' ' || src[j] == '\t'))
    j++;
  while (src[j])
    {
      while (src[j] && (src[j] != ' ' && src[j] != '\t'))
	src[i++] = src[j++];
      if (src[j] && (src[j] == ' ' || src[j] == '\t'))
	src[i++] = ' ';
      while (src[j] && (src[j] == ' ' || src[j] == '\t'))
  	j++;
    }
  if (src[i - 1] && src[i - 1] == ' ')
    src[i - 1] = '\0';
  src[i] = '\0';
  return (src);
}
