/*
** my_struct.h for 42shlib in /media/data/all/projects/42sh-v1/lib/my
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 11:59:28 2013 kevin labbe
** Last update Tue Apr 23 12:00:00 2013 kevin labbe
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct	s_gnl
{
  char		buffer[GNL_BUFFER_SIZE];
  char		*line;
  int		chr_read;
  int		chr_skipped;
  int		found_nl;
}		t_gnl;

#endif /* MY_STRUCT_H_ */
