/*
** calloc.c for malloc in /home/kael/workspace/PSU_2013_malloc/src
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sun Feb 16 09:47:30 2014 Kevin Labbe
** Last update Sun Feb 16 16:01:51 2014 Kevin Labbe
*/

#include <string.h>
#include "proto.h"

void	*calloc(size_t nbrElts, size_t bytes)
{
  char	*ptr;
  int	i;

  if (!(ptr = malloc(nbrElts * bytes)))
    return NULL;
  bytes = GET_ALIGNED_SIZE(bytes);
  memset(ptr, 0, bytes);
  return (ptr);
}
