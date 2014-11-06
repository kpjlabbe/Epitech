/*
** cmd_processing.c for  in /media/data/all/projects/42sh-v1
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 17:11:06 2013 kevin labbe
** Last update Fri May 17 17:17:40 2013 kevin labbe
*/

#include "proto.h"

static int	cmd_analyzing(t_data *data, t_cmd *cmd, t_list *tmp)
{
  if (tmp->next->data)
    ((t_cmd *)tmp->next->data)->prev_sepa = cmd->sepa;
  if (!is_builtin(cmd, data))
    cmd_exec(cmd, data);
  if ((cmd->sepa && !strcmp(cmd->sepa, DELIM_AND) && data->ret_val != 0) ||
      (cmd->sepa && !strcmp(cmd->sepa, DELIM_OR) && !data->ret_val))
    return (data->exit_cmd = 1);
  return (0);
}

int		cmd_processing(t_data *data)
{
  t_list	*tmp;
  t_cmd		*cmd;
  int		ret;

  if (!data->cmdlist)
    return (-1);
  tmp = data->cmdlist->next;
  while (!data->exit_prog && !data->exit_cmd && tmp != data->cmdlist)
    {
      cmd = tmp->data;
      if ((ret = cmd_analyzing(data, cmd, tmp) != 0))
	return (ret);
      tmp = tmp->next;
    }
  list_del(data->local, &vars_del_elt);
  return (1);
}

static int	cmd_exec_child(t_cmd *cmd, t_data *data)
{
  if (cmd->nbr_redir)
    exec_redir(data);
  if (cmd->args[0] && !my_execvp(cmd, data))
    {
      my_fprintf(2, MSG_FAIL_EXEC_CMD, cmd->args[0]);
      data->exit_prog = 1;
      return ((data->ret_val = ID_FAIL_EXEC_CMD));
    }
  if (!cmd->args[0])
    {
      data->exit_prog = 1;
      return (-1);
    }
  return (1);
}

int		cmd_exec(t_cmd *cmd, t_data *data)
{
  pid_t		pid;
  char		pipe_case;

  if (!cmd || !data)
    return (0);
  pipe_case = get_pipe_case(cmd);
  if (pipe_create(pipe_case, data) == ID_FAIL_PIPE)
    return (data->ret_val);
  if ((pid = fork()) < 0)
    {
      my_fprintf(2, MSG_FAIL_FORK);
      data->exit_prog = 1;
      return ((data->ret_val = ID_FAIL_FORK));
    }
  if (!pid)
    {
      redir_pipe(pipe_case, data);
      if ((data->ret_val = cmd_exec_child(cmd, data)) != 1)
	return (data->ret_val);
    }
  else
    {
      close_pipe(pipe_case, data);
      waiting_child(pid, data);
    }
  return (1);
}

int		waiting_child(pid_t pid, t_data *data)
{
  int		status;

  (void)data;
  if (waitpid(pid, &status, 0) < 0)
    {
      my_fprintf(2, MSG_FAIL_WAITPID);
      return (ID_FAIL_WAITPID);
    }
  data->ret_val = status;
  if (!WIFEXITED(status))
    {
      if (WIFSIGNALED(status))
  	throw_signals(WTERMSIG(status));
      if (WIFSTOPPED(status))
  	my_fprintf(STDERR_FILENO, MSG_WAITPID_CHILD_STOPPED);
    }
  return (1);
}
