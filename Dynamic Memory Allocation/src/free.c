/*
** free.c for malloc in /home/kael/workspace/PSU_2013_malloc/src
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sun Feb 16 07:41:57 2014 Kevin Labbe
** Last update Sun Feb 16 22:51:33 2014 Kevin Labbe
*/

#include "proto.h"

int		isLast(t_header *header, t_block *block)
{
  unsigned int	i;

  i = -1;
  while (++i < header->nbrBlocks && header->blocks)
    {
      if (header->blocks > block)
	return (0);
      header->blocks = header->blocks->next;
    }
  return (1);
}

static int	isPointerAccessible(t_header *header, void *ptr)
{
  return (ptr > header->begin && ptr < header->end);
}

static t_block	*getBlock(void *ptr)
{
  return ((t_block *)((char *)ptr - sizeof(t_block)));
}

static t_block	*merge(t_block *block)
{
  t_header *header = get_header();
  if (block && block->next && block->next->flag == STATE_FREE)
    {
      block->size += sizeof(t_block) + block->next->size;
      block->next = block->next->next;
      if (block->next)
	block->next->prev = block;
      header->nbrBlocks--;
    }
  return (block);
}

void		free(void *ptr)
{
  t_header	*header;
  t_block	*block;

  header = get_header();
  if (!isPointerAccessible(header, ptr)
      || !(block = getBlock(ptr))
      || !(block->data))
      return;
  pthread_mutex_lock(&header->lock[1]);
  block->flag = STATE_FREE;
  if (block->prev)
    block = merge(block->prev);
  if (block->next != header->begin)
    block = merge(block);
  else
    header->end = sbrk(header->pagesize);
  pthread_mutex_unlock(&header->lock[1]);
}
