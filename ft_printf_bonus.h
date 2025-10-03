#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int     ft_printf(const char *fmt, ...);
int	    ft_putchar(char c);
char	*ft_putstr(char *s);
size_t	ft_strlen(const char *str);


#endif