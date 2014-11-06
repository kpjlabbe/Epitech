/*
** my.h for malloc in /home/kael/workspace/PSU_2013_malloc/src
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Last update Sun Feb 16 22:14:43 2014 Kevin Labbe
** Started on  Sat Feb 15 05:17:13 2014 Kevin Labbe
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"

#define STATE_ACTIVE 1
#define STATE_FREE 2
#define GET_ALIGNED_SIZE(x) ((((int)x / 4) + 1) * 4)

void		*malloc(size_t);
void		create_page(t_header*);
t_header	*get_header();
void		*get_aligned_address(t_header*, size_t);
void		*malloc(size_t size);
void		create_block_after(t_header *, size_t, int);
void		create_block_at_address(t_block*, t_block*, size_t, int);
void		show_alloc_mem();
void		free(void *ptr);
void		*calloc(size_t nbrElts, size_t bytes);

#endif
