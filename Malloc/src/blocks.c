/*
** blocks.c for malloc in /home/kael/workspace/PSU_2013_malloc/src
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sat Feb 15 05:41:49 2014 Kevin Labbe
** Last update Sun Feb 16 22:39:30 2014 Kevin Labbe
*/

#include "proto.h"

void		create_block_after(t_header *header, size_t size, int flag)
{
  t_block	*newBlock;

  if (!header || !(newBlock = get_aligned_address(header, size)))
    return;
  header->nbrBlocks++;
  newBlock->size = GET_ALIGNED_SIZE(size);
  newBlock->flag = flag;
  if (!header->blocks)
    {
      newBlock->prev = newBlock;
      newBlock->next = newBlock;
      header->blocks = newBlock;
      return;
    }
  newBlock->prev = header->blocks->prev;
  newBlock->next = header->blocks;
  header->blocks->prev->next = newBlock;
  header->blocks->prev = newBlock;
}

void		create_block_at_address(t_block *prev, t_block *new,
				     size_t size, int flag)
{
  t_header	*header;

  header = get_header();
  header->nbrBlocks++;
  new->size = GET_ALIGNED_SIZE(size);
  new->flag = flag;
  new->prev = prev;
  new->next = prev->next;
  prev->next->prev = new;
  prev->next = new;
}
