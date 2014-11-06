/*
** realloc.c for realloc in /home/marcha_s/rendu/PSU_2013_malloc/src
** 
** Made by Christophe Marchand
** Login   <marcha_s@epitech.net>
** 
** Started on  Sun Feb 16 07:44:15 2014 Christophe Marchand
** Last update Sun Feb 16 22:20:25 2014 Kevin Labbe
*/

#include <string.h>
#include "proto.h"

void		*realloc(void *ptr, size_t size)
{
  void		*new;
  t_block	*block;
  t_block	*next;
  size_t	freesize;
  t_header	*header;

  if (!ptr)
    return (malloc(size));
  pthread_mutex_lock(&header->lock[2]);
  block = (t_block*)((char*)ptr - sizeof(t_block));
  if (block->size > size)
    {
      freesize = block->size;
      block->size = GET_ALIGNED_SIZE(size);
      next = (t_block*)((char*)ptr + block->size + 4);
      freesize -= block->size + sizeof(t_block) + 8;
      create_block_at_address(block, next, freesize, STATE_FREE);
      pthread_mutex_unlock(&header->lock[2]);
      return (ptr);
    }
  block->flag = STATE_FREE;
  new = malloc(block->size + size);
  new = memmove(new, ptr, block->size);
  pthread_mutex_unlock(&header->lock[2]);
  return (new);
}
