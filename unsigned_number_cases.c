#include "ft_printf_bonus.h"

int unsigned_number_case_one(t_format *flg, int len, int num, int w_nbr)
{
	int count;
	count = 0;
	w_nbr -= len;
	if(flg->minus_flag)
	{
		count += ft_putnbr_unsigned(num);
		while(w_nbr-- > 0)
			count += ft_putchar(' ');
	}
	else if(flg->zero_flag)
	{
		while(w_nbr-- > 0)
			count += ft_putchar('0');
		count += ft_putnbr_unsigned(num);
	}
	else
	{
		while(w_nbr-- > 0)
			count += ft_putchar(' ');
		count += ft_putnbr_unsigned(num);
	}
	return count;
}

int unsigned_number_case_two(t_format *flg, int len, int num, int p_nbr)
{
	int count;
	count = 0;

	p_nbr -= len;
	while(p_nbr-- > 0)
		count += ft_putchar('0');
	count += ft_putnbr_unsigned(num);

	return count;
}
int unsigned_number_case_three(t_format *flg, int len, int num, int p_nbr, int w_nbr)
{
	int count;
	count = 0;

	w_nbr -= p_nbr;
	p_nbr -= len;
	if(flg->minus_flag)
	{
		while(p_nbr-- > 0)
			count += ft_putchar('0');
		count += ft_putnbr_unsigned(num);
		while(w_nbr-- > 0)
			count += ft_putchar(' ');
	}
	else
	{
		while(w_nbr-- > 0)
			count += ft_putchar(' ');
		while(p_nbr-- > 0)
			count += ft_putchar('0');
		count += ft_putnbr_unsigned(num);
	}
	return count;
}