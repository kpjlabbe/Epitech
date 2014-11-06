/*
** my_atoi_base.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:35:39 2013 kevin labbe
** Last update Tue Apr 23 14:35:59 2013 kevin labbe
*/

#include "my.h"

int	get_sign(char *str)
{
  int	sign;
  
  sign = 1;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign *= (-1);
      str++;
    }
  return (sign);
}

int	convert_to_int(char c, char *base)
{
  int	nb;
  
  nb = 0;
  while (base[nb] && (base[nb] != c) && (c != '+' && c != '-'))
    nb++;
  if (!base[nb])
    return (-1);
  return (nb);
}

int	convert_to_decimal(char *str, char *base, int power, int position)
{
  int	nb;
  int	swap;
  
  nb = 0;
  while (*str)
    {
      swap = convert_to_int(*str, base);
      nb += (swap * my_pow(power, position));
      position--;
      str++;
    }
  return (nb);
}

int	my_atoi_base(char *str, char *base)
{
  int	sign;
  int	power;
  int	position;
  int	nb;
  
  sign = get_sign(str);
  power = strlen(base);
  position = strlen(str) - 1;
  nb = convert_to_decimal(str, base, power, position);
  return (nb * sign);
}
