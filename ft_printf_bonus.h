#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int	zero_flag;
	int	minus_flag;
	int	plus_flag;
	int	hash_flag;
	int	space_flag;
}		t_format;



int		ft_printf(const char *fmt, ...);
void	flag_check(const char *fmt, int *i, t_format *flag);
int		ft_putchar(char c);
char	*ft_putstr(char *s);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		num_len(int n);

#endif