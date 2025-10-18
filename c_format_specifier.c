#include "ft_printf_bonus.h"
int	char_case_check(char c, t_format *flg, int w_nbr)
{
	int	count;
	count = 0;
	if (flg->minus_flag == 1)
	{
		count += ft_putchar(c);
		while (--w_nbr > 0)
			count += ft_putchar(' ');
	}
	else
	{
		while (--w_nbr > 0)
			count += ft_putchar(' ');
		count += ft_putchar(c);
	}
	return (count);
}

void c_specifier(t_format *flg,const char *fmt, va_list list, int *count, int w_nbr)
{
    char c;
    c = va_arg(list, int);
    if (w_nbr != -1)
        *count += char_case_check(c, flg, w_nbr);
    else
        *count += ft_putchar(c);
}