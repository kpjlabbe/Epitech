/*
** explode.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:39:20 2013 kevin labbe
** Last update Tue Apr 23 14:39:27 2013 kevin labbe
*/

#include "my.h"

int	patterns_found(char *patterns, char str)
{
  if (!str)
    return (0);
  while (*patterns)
    if (str == *patterns++)
      return (1);
  return (0);
}

int	count_words(char *delim, char *str)
{
  int	nbr_words;
  
  nbr_words = 0;
  while (*str)
    {
      nbr_words++;
      while (*str && !(patterns_found(delim, *str++)));
    }
  return (nbr_words);
}

char	**explode(char *delim, char *str)
{
  char	**array;
  int	word;
  int	letter;
  int	nbr_words;
  
  trim(str);
  nbr_words = count_words(delim, str);
  array = my_alloc(nbr_words, sizeof(char *));
  word = 0;
  while (*str && word < nbr_words)
    {
      array[word] = my_alloc(strlen(str), sizeof(char));
      letter = 0;
      while (*str && !(patterns_found(delim, *str)))
      	{
      	  array[word][letter] = *str;
      	  letter++;
      	  str++;
      	}
      array[word][letter] = '\0';
      str++;
      word++;
    }
  array[word] = '\0';
  return (array);
}
