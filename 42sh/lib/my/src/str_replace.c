/*
** str_replace.c for lib in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Sat May  4 18:40:49 2013 kevin labbe
** Last update Sat May  4 18:45:58 2013 kevin labbe
*/

#include "my.h"

static void	init_str_replacing(int *i, int *j, int *replaced)
{
  *i = 0;
  *j = 0;
  *replaced = 0;
}

static char	*get_dest(char *dest, int new_len, int replaced, char *replace)
{
  int		len_replace;

  len_replace = (replace ? strlen(replace) : 0);
  if (replaced)
    dest = my_realloc(dest, new_len + len_replace, sizeof(char));
  if (replace)
    strcat(dest, replace);
  return (dest);
}

static void	increment_vars(int *i, int *j, char *search, char *replace)
{
  *j += (replace ? strlen(replace) : 0);
  *i += strlen(search);
}

char		*str_replace(char *search, char *replace, char *src, int every)
{
  char		*dest;
  int		i;
  int		j;
  int		new_len;
  int		replaced;

  if (!src || !search)
    return (NULL);
  new_len = strlen(src) - strlen(search) + (replace ? strlen(replace) : 0);
  dest = my_alloc(new_len, sizeof(char));
  init_str_replacing(&i, &j, &replaced);
  while (src[i])
    {
      if (src[i] == search[0] && !strncmp(&src[i], search, strlen(search))
	  && ((!replaced) || (replaced && every)))
	{
	  dest = get_dest(dest, new_len, replaced, replace);
	  increment_vars(&i, &j, search, replace);
	  replaced = 1;
	}
      else
	dest[j++] = src[i++];
    }
  dest[j] = '\0';
  return (dest);
}
