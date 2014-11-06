/*
** implode.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:39:09 2013 kevin labbe
** Last update Tue Apr 23 15:11:05 2013 kevin labbe
*/

#include "my.h"

int	count_array_chr(char **array)
{
  int	tab;
  int	chr;
  int	nbr_chr;
  
  tab = 0;
  nbr_chr = 0;
  while (array[tab])
    {
      chr = 0;
      while (array[tab][chr++])
	nbr_chr++;
      tab++;
    }
  return (nbr_chr);
}

char	*implode(char *delimiter, char **args)
{
  char	*str;
  int	len;
  int	nbr_elts;
  int	i;
  
  if (!args[0])
    return (NULL);
  nbr_elts = count(args);
  len = count_array_chr(args) + strlen(delimiter) * nbr_elts;
  str = my_alloc(len, sizeof(char));
  i = 0;
  while (i < nbr_elts)
    {
      strcat(str, args[i]);
      if (i < (nbr_elts - 1))
	strcat(str, delimiter);
      i++;
    }
  return (str);
}
