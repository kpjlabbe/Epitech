/*
** convert_base.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:37:03 2013 kevin labbe
** Last update Tue Apr 23 14:37:17 2013 kevin labbe
*/

#include "my.h"

int	get_max_power(int nb_max, int base)
{
  int	nb;
  int	power;
  
  nb = 0;
  power = 0;
  while (nb <= nb_max)
    {
      nb = my_pow(base, power);
      power++;
    }
  power -= 2;
  nb = my_pow(base, power);
  return (nb);
}

char	get_conv_nbr(char *base_to, int *max_nbr, int power)
{
  int	nbr;
  int	conv_nbr;
  
  nbr = 0;
  conv_nbr = 0;
  while (nbr <= *max_nbr)
    {
      nbr = conv_nbr * power;
      conv_nbr++;
    }
  conv_nbr -= 2;
  *max_nbr = *max_nbr - (conv_nbr * power);
  return (base_to[conv_nbr]);
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	decimal;
  int	max_power;
  int	len_base;
  char	*nbr_conv;
  int	i;
  
  decimal = my_atoi_base(nbr, base_from);
  len_base = strlen(base_to);
  max_power = get_max_power(decimal, len_base);
  nbr_conv = my_alloc(my_sqrt(max_power) + 1, sizeof(char));
  i = 0;
  while (max_power >= 1)
    {
      nbr_conv[i] = get_conv_nbr(base_to, &decimal, max_power);
      max_power /= len_base;
      i++;
    }
  nbr_conv[i] = '\0';
  return (nbr_conv);
}
