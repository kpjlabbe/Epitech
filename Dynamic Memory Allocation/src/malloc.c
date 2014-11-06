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

static void		*split(t_header *header, t_block *block, size_t size)
{
  size_t		freeSize;
  t_block		*freeBlock;

  block->flag = STATE_ACTIVE;
  freeBlock = (t_block *)((char *)block + block->size + sizeof(t_block) + 4);
  freeSize = block->size - size - sizeof(t_block);
  create_block_at_address(block, freeBlock, freeSize, STATE_FREE);
  pthread_mutex_unlock(&header->lock[0]);
  return (block + sizeof(t_block));
}

void			*malloc(size_t size)
{
  t_header		*header;
  t_block		*block;
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
