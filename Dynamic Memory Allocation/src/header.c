/*
** header.c for malloc in /home/kael/workspace/PSU_2013_malloc/src
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sat Feb 15 10:38:06 2014 Kevin Labbe
** Last update Sun Feb 16 21:02:16 2014 Kevin Labbe
*/

#include "proto.h"

t_header	        *get_header()
{
  static t_header	header;

  if (header.begin == NULL)
    {
      header.pagesize = getpagesize();
      header.begin = sbrk(header.pagesize);
      header.end = sbrk(0);
      header.last = header.begin;
      header.bytes = 0;
      header.nbrPages = 1;
      header.nbrBlocks = 0;
      header.blocks = NULL;
      pthread_mutex_init(&header.lock[0], NULL);
      pthread_mutex_init(&header.lock[1], NULL);
      pthread_mutex_init(&header.lock[2], NULL);
    }
  return &header;
}

void			create_page(t_header *header)
{
  if (!header)
    return;
  sbrk(header->pagesize);
  header->end = sbrk(0);
  header->nbrPages++;
}
