/*
** my.h for 42shlib in /media/data/all/projects/42sh-v1/lib/my
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 11:58:57 2013 kevin labbe
** Last update Fri May 17 18:19:40 2013 kevin labbe
*/

#ifndef MY_H_
# define MY_H_

# define GNL_BUFFER_SIZE 300
# define MSG_FAIL_MALLOC "Can't allocate memory anymore.\n"
# define MSG_FAIL_REALLOC "Can't reallocate memory anymore.\n"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "my_struct.h"

void	my_putchar(const int fd, char c);
void	my_putstr(const int fd, char *str);
void	my_putnbr_base(const int fd, int nbr, char *base);
void	my_putnbr(const int fd, int nbr);
int	my_atoi_base(char *str, char *base);
int	my_atoi(char *expr);
char	*my_itoa_base(int nbr, char *base);
char	*my_itoa(const int nbr);
char	*convert_base(char *nbr, char *base_from, char *base_to);
int	is_number(char *str);
void	*my_alloc(int nbr_elts, int bytes);
void	*my_realloc(void *ptr, int nbr_elts, int bytes);
void	my_fprintf(const int fd, const char *format, ...);
void	my_printf(const char *format, ...);
int	match(char *src, char *pattern);
int	in_str(char chr, char *str);
char	*my_strcpy_to(char *dest, char *src, char delimiter);
int	my_strlen_to(char *str, char delimiter);
int	my_pow(int nbr, int power);
int	my_sqrt(const int nbr);
char	*trim(char *src);
char	*implode(char *delimiter, char **args);
char	**explode(char *delim, char *str);
void	free_array(char **array);
int	in_array(char *val, char **array);
int	count(char **array);
char	*get_next_line(const int fd);
char	*str_replace(char *search, char *replace, char *src, int every);

#endif /* !MY_H_ */
