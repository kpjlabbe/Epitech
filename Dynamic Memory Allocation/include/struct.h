/*
** struct.h for malloc in /home/kael/workspace/PSU_2013_malloc/includes
** 
** Made by Kevin Labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sat Feb 15 05:22:17 2014 Kevin Labbe
** Last update Sun Feb 16 20:48:40 2014 Kevin Labbe
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <pthread.h>

typedef struct __attribute__ ((packed))	s_block
{
  size_t				size;
  int					flag;
  struct s_block			*prev;
  struct s_block			*next;
  char					data[1];
}					t_block;

typedef struct __attribute__ ((packed))	s_header
{
  void					*begin;
  void					*end;
  void					*last;
  size_t				bytes;
  unsigned int				pagesize;
  unsigned int				nbrPages;
  unsigned int				nbrBlocks;
  t_block				*blocks;
  pthread_mutex_t			lock[3];
}					t_header;

#endif
