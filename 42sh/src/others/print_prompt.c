/*
** print_prompt.c for 42sh in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Thu May  2 12:04:54 2013 kevin labbe
** Last update Fri May 17 12:03:12 2013 kevin labbe
*/

#include "proto.h"

static char	*get_env_val(char *name, t_data *data)
{
  char		*val;

  if ((val = vars_get_val(data->local, name)))
    return (val);
  if ((val = vars_get_val(data->env, name)))
    return (val);
  return (NULL);
}

static int	replace_vars(char *str, t_data *data)
{
  char		*search;
  char		*replace;
  int		len_to_dollar;
  int		len_to_space;
  int		len;

  len_to_space = my_strlen_to(str, ' ');
  len_to_dollar = my_strlen_to(str, '$') - 1;
  len = (len_to_space < len_to_dollar) ? len_to_space : len_to_dollar;
  if (!(search = my_alloc(len, sizeof(char))))
    return (0);
  if (!xstrncat(search, str, len))
    return (0);
  replace = get_env_val(search, data);
  if (replace)
    my_printf("%s", replace);
  free(search);
  return (len);
}

int		print_prompt(t_data *data)
{
  char		*str;

  if (!(str = vars_get_val(data->env, "PROMPT")))
    return (0);
  while (*str)
    {
      if (*str == '$' && *(str + 1))
	str += replace_vars(str + 1, data);
      else
	if (*str == '%' && *(str + 1))
	  {
	    if (*(str + 1) == 'c')
	      {
		my_printf("%d", data->nbr_cmds);
		str++;
	      }
	  }
	else
	  my_printf("%c", *str);
      str++;
    }
  return (1);
}
