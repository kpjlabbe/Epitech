/*
** my_itoa_base.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:36:30 2013 kevin labbe
** Last update Tue Apr 30 18:25:12 2013 kevin labbe
*/

#include "my.h"

char	*my_itoa_reverse(char *str)
{
  int	src;
  int	dest;
  char	*rev;
  
  src = strlen(str) - 1;
  dest = 0;
  rev = my_alloc(src + 2, sizeof(char));
  while (src >= 0)
    {
      rev[dest] = str[src];
      src--;
      dest++;
    }
  rev[dest] = '\0';
  free(str);
  return (rev);
}

char	*my_itoa_base(int nbr, char *base)
{
  int	mod;
  int	len_base;
  char	*result;
  int	i;
  
  len_base = strlen(base);
  mod = nbr % len_base;
  nbr /= len_base;
  result = my_alloc(len_base, sizeof(char));
  i = 0;
  result[i++] = base[mod];
  while (nbr != 0)
    {
      mod = nbr % len_base;
      nbr /= len_base;
      result[i++] = base[mod];
    }
  result[i] = '\0';
  return (my_itoa_reverse(result));
}
