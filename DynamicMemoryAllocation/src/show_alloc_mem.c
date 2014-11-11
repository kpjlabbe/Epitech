/*
** show_alloc_mem.c for show_alloc_mem in /home/marcha_s/rendu/PSU_2013_malloc
** 
** Made by Christophe Marchand
** Login   <marcha_s@epitech.net>
** 
** Started on  Sun Feb 16 04:54:48 2014 Christophe Marchand
** Last update Sun Feb 16 18:04:47 2014 Kevin Labbe
*/

#include "proto.h"

void		show_alloc_mem()
{
  t_header	*header;
  unsigned int	i;

  header = get_header();
  if (!header->blocks)
    return;
  printf("break : %p\n", header->end);
  i = -1;
  while (++i < header->nbrBlocks)
    {
      printf("%p - %p : %d octets\n", header->blocks,
	     (char*)header->blocks + GET_ALIGNED_SIZE(header->blocks->size)
	     + sizeof(t_block),
	     (int)(header->blocks->size + sizeof(t_block)));
      header->blocks = header->blocks->next;
    }
}
