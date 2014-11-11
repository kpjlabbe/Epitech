/*
** malloc.c for malloc in /home/kael/workspace/PSU_2013_malloc/src
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Started on Sun Feb 16 17:49:02 2014 Kevin Labbe
** Last update Tue Feb 18 22:13:33 2014 Kevin Labbe
*/

#include "proto.h"

void			*malloc(size_t size)
{
  t_header		*header;
  unsigned int		i;

  if ((int) size < 0)
    return ((void*) - 1);
  if ((header = get_header()) == NULL)
    return (NULL);
  pthread_mutex_lock(&header->lock[0]);
  create_block_after(header, size, STATE_ACTIVE);
  pthread_mutex_unlock(&header->lock[0]);
  return (header->last + sizeof(t_block));
}
