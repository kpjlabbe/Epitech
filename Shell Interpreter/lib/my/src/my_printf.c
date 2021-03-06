/*
** my_printf.c for 42shlib in /media/data/all/projects/42sh-v1/lib/my/src/string
** 
** Made by kevin labbe
** Login   <labbe_k@epitech.net>
** 
** Started on  Tue Apr 23 14:33:39 2013 kevin labbe
** Last update Tue Apr 23 15:15:24 2013 kevin labbe
*/

#include "my.h"

int		printf_flag_exists(char chr)
{
  char		*flags;
  
  flags = "%csdiuoxXb";
  while (*flags)
    if (chr == *flags++)
      return (1);
  return (0);
}

void		printf_replace_flag(const int fd, char chr, va_list arg)
{
  (chr == '%') ? my_putchar(fd, '%') : 0;
  (chr == 'c') ? my_putchar(fd, (char) va_arg(arg, int)) : 0;
  (chr == 's') ? my_putstr(fd, va_arg(arg, char *)) : 0;
  (chr == 'd' || chr == 'i') ? my_putnbr(fd, va_arg(arg, int)) : 0;
  (chr == 'u') ? my_putnbr_base(fd, va_arg(arg, int), "0123456789") : 0;
  (chr == 'o') ? my_putnbr_base(fd, va_arg(arg, int), "01234567") : 0;
  (chr == 'x') ? my_putnbr_base(fd, va_arg(arg, int), "0123456789abcdef") : 0;
  (chr == 'X') ? my_putnbr_base(fd, va_arg(arg, int), "0123456789ABCDEF") : 0;
  (chr == 'b') ? my_putnbr_base(fd, va_arg(arg, int), "01") : 0;
}

void		my_printf(const char *format, ...)
{
  va_list	list;
  
  va_start(list, format);
  while (*format)
    {
      if (*format == '%' && printf_flag_exists(*(format + 1)))
	printf_replace_flag(1, *(++format), list);
      else
	my_putchar(1, *format);
      format++;
    }
  va_end(list);
}
