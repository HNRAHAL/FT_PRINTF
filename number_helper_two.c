#include "ft_printf_bonus.h"

int padding_width(int w_nbr)
{
	int count;
	count = 0;
	if(w_nbr)
	{
		while(--w_nbr> 0)
			count += ft_putchar(' ');
	}
	return count;
}
int padding_prescion(int p_nbr)
{
	int count;
	count = 0;
	while(p_nbr-- > 0)
		count += ft_putchar('0');
	return count;
}

int zero_case_number_format(int p_nbr, int w_nbr, int count, t_format *flg, int num, int len)
{
	positive_case(num, flg, &count, &w_nbr);
	count += padding_width(w_nbr);
	negative_case(&num, flg);
	count += padding_prescion(p_nbr) + len;
	ft_putnbr(num);
	return count-1;
}
int else_case_number_format2(int p_nbr, int w_nbr, int count, t_format *flg, int num, int len)
{
    if(num >= 0)
	{
		w_nbr++;
		count--;
	}
	while(--w_nbr > 0)
		count += ft_putchar(' ');
	if(num < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	while(p_nbr-- > 0)
		count += ft_putchar('0');
	ft_putnbr(num);
	count += len;
	return count-1;
}