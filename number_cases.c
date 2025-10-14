#include "ft_printf_bonus.h"
#include <stdio.h>
int number_format_case_one(int w_nbr, int count, t_format *flg, int num, int len)
{
	count = 1;
	if (flg->plus_flag && flg->minus_flag || flg->minus_flag
		&& flg->space_flag || flg->plus_flag && flg->zero_flag
		|| flg->zero_flag && flg->space_flag)
		double_flag_combination_check(flg, w_nbr, len, num,
			&count);
	else if(flg->plus_flag || flg->minus_flag || flg->space_flag || flg->zero_flag)
		single_flag_combination_check(flg, w_nbr, len, num, &count);
	else
	{
		w_nbr -= len;
		if(num >= 0)
			w_nbr++;
		else
			count++;

		while(--w_nbr > 0)
			count += ft_putchar(' ');
		ft_putnbr(num);
		count += len -1;
	}
	return count;
}

int number_format_case_two(int p_nbr, int count, t_format *flg, int num, int len)
{
	count = 1;
	p_nbr -= len;
	if(num < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	else
	{
		if(flg->plus_flag)
			ft_putchar('+');
		else if(flg->space_flag)
			ft_putchar(' ');
		else
			count--;
	}
	while(p_nbr-- > 0)
		count += ft_putchar('0');
	ft_putnbr(num);
	count += len;
	return count;
}

int number_format_case_three(int p_nbr, int w_nbr, int count, t_format *flg, int num, int len)
{
	count = 1;
	w_nbr -= p_nbr;
	p_nbr -= w_nbr - 1;
	if(flg->plus_flag && flg->minus_flag || flg->space_flag && flg->minus_flag || flg->minus_flag)
	{
		positive_case(num, flg, &count, &w_nbr);
		negative_case(&num, flg);
		count += padding_prescion(p_nbr) + len;
		ft_putnbr(num);
		count += padding_width(w_nbr);
	}
	else if(flg->plus_flag && flg->zero_flag || flg->space_flag && flg->zero_flag || flg->plus_flag || flg->space_flag)
	{
		count += padding_width(w_nbr);
		positive_case(num, flg, &count, &w_nbr);
		negative_case(&num, flg);
		count += padding_prescion(p_nbr) + len;
		ft_putnbr(num);
	}
	else if(flg->zero_flag)
		count += zero_case_number_format(p_nbr,w_nbr,count,flg,num,len);
	else
		count += else_case_number_format2(p_nbr,w_nbr,count,flg,num,len);
	return count;
}

int else_case_number_format(t_format *flg, int num, int len)
{
	int count;
	count = 0;

	if(num < 0)
		count++;
	else
	{
		if(flg->plus_flag)
			count += ft_putchar('+');
		else if(flg->space_flag)
			count += ft_putchar(' ');
	}
	ft_putnbr(num);
	count += len;
	return count;
}