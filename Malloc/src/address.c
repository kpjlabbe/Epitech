/*
** address.c for malloc in /home/kael/workspace/PSU_2013_malloc/src
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sat Feb 15 09:23:51 2014 Kevin Labbe
** Last update Sun Feb 16 17:57:08 2014 Christophe Marchand
*/

#include "proto.h"

static int	current_page_is_enough(t_header *header)
{
  return (header->bytes <= header->pagesize * header->nbrPages);
}

void		*get_aligned_address(t_header *header, size_t bytes)
{
  header->last = header->begin + header->bytes;
  header->bytes += GET_ALIGNED_SIZE(bytes) + GET_ALIGNED_SIZE(sizeof(t_block));
  header->bytes += 4;
  while (!current_page_is_enough(header))
    create_page(header);
  return (header->last);
}
