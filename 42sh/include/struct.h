/*
** struct.h for 42sh in /media/data/all/projects/42sh-v1/include
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 11:58:07 2013 kevin labbe
** Last update Thu May 16 13:31:58 2013 kevin labbe
*/

#ifndef			STRUCT_H_
# define		STRUCT_H_

typedef int		(*t_redir_fct)(char *, int);
typedef struct s_data	t_data;

typedef struct		s_vars
{
  char			*name;
  char			*val;
  char			free;
}			t_vars;

typedef struct		s_alias
{
  char			*name;
  char			*val;
  char			**args;
  char			free;
}			t_alias;

typedef struct		s_redir
{
  char			*type;
  char			*filename;
  int			fdin;
  int			fdout;
}			t_redir;

typedef struct		s_cmd
{
  char			**args;
  char			*sepa;
  int			nbr_redir;
  char			*prev_sepa;
}			t_cmd;

typedef struct		s_delim
{
  char			*redir[NBR_REDIR];
  char			*sepa[NBR_SEPA];
}			t_delim;

typedef struct		s_builtins
{
  char			*idx[NBR_BUILTINS];
  int			(*fct[NBR_BUILTINS])(t_cmd *, t_data *);
}			t_builtins;

struct			s_data
{
  t_delim		*delim;
  t_builtins		*builtins;
  t_list		*cmdlist;
  t_list		*env;
  t_list		*local;
  t_list		*alias;
  t_list		*redir;
  t_redir_fct		*redir_fct;
  int			pipe_new[2];
  int			pipe_old[2];
  int			nbr_cmds;
  int			ret_val;
  char			exit_prog;
  char			exit_cmd;
};

#endif /* STRUCT_H_ */
