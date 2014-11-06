/*
** signals.c for 42sh in /media/data/all/projects/42sh-v1/src
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 30 16:47:49 2013 kevin labbe
** Last update Fri May 17 10:44:53 2013 kevin labbe
*/

#include "proto.h"

void	throw_signals(int sig)
{
  my_printf("\b\b  \b\b");
  (sig == SIGFPE) ? my_fprintf(STDERR_FILENO, MSG_SIGFPE) : 0;
  (sig == SIGABRT) ? my_fprintf(STDERR_FILENO, MSG_SIGABRT) : 0;
  (sig == SIGILL) ? my_fprintf(STDERR_FILENO, MSG_SIGILL) : 0;
  (sig == SIGBUS) ? my_fprintf(STDERR_FILENO, MSG_SIGBUS) : 0;
  (sig == SIGSYS) ? my_fprintf(STDERR_FILENO, MSG_SIGSYS) : 0;
  (sig == SIGSEGV) ? my_fprintf(STDERR_FILENO, MSG_SIGSEGV) : 0;
}

int    catch_signals(void)
{
  if (signal(SIGINT, throw_signals) == SIG_ERR ||
      signal(SIGQUIT, throw_signals) == SIG_ERR ||
      signal(SIGTSTP, throw_signals) == SIG_ERR ||
      signal(SIGTERM, throw_signals) == SIG_ERR)
    {
      my_fprintf(STDERR_FILENO, MSG_FAIL_SIGNAL);
      return (ID_FAIL_SIGNAL);
    }
  return (0);
}
