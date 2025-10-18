#include "ft_printf_bonus.h"

void	positive_case(int num, t_format *flg, int *count, int *w_nbr)
{
	if (num >= 0)
	{
		if (flg->plus_flag)
		{
			if (num >= 0)
				ft_putchar('+');
		}
		else if (flg->space_flag)
		{
			if (num >= 0)
				ft_putchar(' ');
		}
		else if (flg->minus_flag || flg->zero_flag)
		{
			(*w_nbr)++;
			(*count)--;
		}
	}
}
void	negative_case(int *num, t_format *flg)
{
	if (*num < 0)
	{
		if (flg->plus_flag || flg->zero_flag || flg->space_flag || flg->minus_flag)
		{
			*num *= -1;
			ft_putchar('-');
		}
	}
}
int	padding_option(t_format *flg, int w_nbr)
{
	int	count;

	count = 0;
	if ((flg->minus_flag && flg->plus_flag || flg->space_flag
			&& flg->minus_flag))
	{
		while (--w_nbr > 0)
			count += ft_putchar(' ');
	}
	else if (flg->zero_flag && flg->plus_flag || flg->zero_flag
		&& flg->space_flag)
	{
		while (--w_nbr > 0)
			count += ft_putchar('0');
	}
    else if(flg->minus_flag || flg->plus_flag || flg->space_flag)
    {
        while (--w_nbr > 0)
			count += ft_putchar(' ');
    }
    else if(flg->zero_flag)
    { 
        while (--w_nbr > 0)
			count += ft_putchar('0');
    }
	return (count);
}

void	double_flag_combination_check(t_format *flg, int w_nbr, int len,
		int num, int *count)
{
	w_nbr -= len;
	if (flg->plus_flag && flg->minus_flag || flg->minus_flag && flg->space_flag)
	{
		positive_case(num, flg, count, &w_nbr);
		negative_case(&num, flg);
		ft_putnbr(num);
		*count += padding_option(flg, w_nbr) + len;
	}
	else if (flg->plus_flag && flg->zero_flag)
	{
		positive_case(num, flg, count, &w_nbr);
		negative_case(&num, flg);
		*count += padding_option(flg, w_nbr) + len;
		ft_putnbr(num);
	}
	else if (flg->zero_flag && flg->space_flag)
	{
		positive_case(num, flg, count, &w_nbr);
		negative_case(&num, flg);
		*count += padding_option(flg, w_nbr) + len;
		ft_putnbr(num);
	}
}

void single_flag_combination_check(t_format *flg, int w_nbr, int len, int num, int *count)
{
	w_nbr -= len;
	if(flg->plus_flag || flg->space_flag)
	{
		*count += padding_option(flg, w_nbr) + len;
		positive_case(num, flg, count, &w_nbr);
		negative_case(&num, flg);
		ft_putnbr(num);
	}
	else if(flg->minus_flag)
	{
		positive_case(num, flg, count, &w_nbr);
		negative_case(&num, flg);
		ft_putnbr(num);
		*count += padding_option(flg, w_nbr) + len;
	}

	else if(flg->zero_flag)
	{
		positive_case(num, flg, count, &w_nbr);
		negative_case(&num, flg);
		*count += padding_option(flg, w_nbr) + len;
		ft_putnbr(num);
	}
}