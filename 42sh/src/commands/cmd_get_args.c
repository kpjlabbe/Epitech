/*
** cmd_get_args.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 15:40:18 2013 kevin labbe
** Last update Fri May 17 17:18:41 2013 kevin labbe
*/

#include "proto.h"

char		**cmd_get_args(char *str)
{
  char		escaped;
  char		**args;
  int		i;
  int		j;
  int		start;
  int		elt;
  int		len;

  i = 0;
  j = 0;
  elt = 0;
  escaped = '\0';
  len = strlen(str);
  if (!(args = my_alloc(len, sizeof(char *))))
    return (NULL);
  while ((i < len) && str[i])
    {
      start = j;
      trim_arg(str, &i, &j, &escaped);
      if (strcmp(&str[start], ""))
	args[elt++] = &str[start];
      i += (i < j) ? (j - i) : 0;
    }
  return (args);
}

void		trim_arg(char *str, int *i, int *j, char *escaped)
{
  while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
    (*i)++;
  while (str[*i] && ((str[*i] != ' ' && str[*i] != '\t') || *escaped))
    trim_characters(str, i, j, escaped);
  str[(*j)++] = '\0';
}

int		trim_characters(char *str, int *i, int *j, char *escaped)
{
  int		ret;

  if ((ret = trim_slashes(str, i, j)))
    return (1);
  if ((ret = trim_quotes(str, i, j, escaped)))
    return (2);
  str[(*j)++] = str[(*i)++];
  return (3);
}

int		trim_slashes(char *str, int *i, int *j)
{
  if (*i && str[*i - 1] && str[*i - 1] == '\\')
    {
      --(*j);
      str[(*j)++] = str[(*i)++];
      return (1);
    }
  return (0);
}

int		trim_quotes(char *str, int *i, int *j, char *escaped)
{
  if (str[*i] && (str[*i] == '\'' || str[*i] == '"'))
    {
      if (!*escaped)
	*escaped = str[(*i)++];
      if (*escaped && (str[*i] == *escaped))
	{
	  *escaped = 0;
	  (*i)++;
	}
      else
	if (*escaped == '\'' && str[(*i)] == '$')
	  (*i)++;
	else
	  str[(*j)++] = str[(*i)++];
      return (1);
    }
  return (0);
}
