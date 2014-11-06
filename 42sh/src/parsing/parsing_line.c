/*
** parsing_line.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 15:33:36 2013 kevin labbe
** Last update Thu May 16 13:19:17 2013 kevin labbe
*/

#include "proto.h"

t_list		*parsing_line(char *line, t_delim *delim)
{
  char		*sepa;
  int		i;
  int		start;
  t_list	*list;

  list_create(&list);
  i = 0;
  while (line[i])
    {
      start = i;
      sepa = NULL;
      while (line[i] && !sepa)
	sepa = cmd_lookfor_delim(delim, line, &i);
      if (line[i])
	line[i] = '\0';
      i += (sepa) ? strlen(sepa) : 0;
      sepa = sepa ? sepa : "";
      cmd_add(list, &line[start], sepa);
    }
  return (list);
}

char		*cmd_lookfor_delim(t_delim *delim, char *line, int *i)
{
  char		escaped;
  char		*sepa;

  escaped = 0;
  sepa = NULL;
  while (line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
    (*i)++;
  while (line[*i] && ((line[*i] != ' ' && line[*i] != '\t') || escaped))
    {
      if ((sepa = skip_quotes(delim, line, i, &escaped)))
	return (sepa);
    }
  return (sepa);
}

char		*skip_quotes(t_delim *delim, char *line, int *i, char *escaped)
{
  char		*sepa;

  sepa = NULL;
  if (line[*i] && (line[*i] == '\'' || line[*i] == '"'))
    {
      if (!*escaped)
	*escaped = line[*i];
      else
	if (*escaped && (line[*i] == *escaped))
	  *escaped = 0;
      (*i)++;
    }
  else
    {
      if ((sepa = get_next_delim(delim, &line[*i])) && !*escaped)
	return (sepa);
      (*i)++;
    }
  return (sepa);
}
