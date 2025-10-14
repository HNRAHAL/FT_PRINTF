#include "ft_printf_bonus.h"
#include <stdio.h>

void	flag_check(const char *fmt, int *i, t_format *flag)
{
	flag->minus_flag = 0;
	flag->plus_flag = 0;
	flag->space_flag = 0;
	flag->hash_flag = 0;
	flag->zero_flag = 0;
	while (fmt[*i] == '0' || fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == ' '
		|| fmt[*i] == '#')
	{
		if (fmt[*i] == '0')
			flag->zero_flag = 1;
		else if (fmt[*i] == '+')
			flag->plus_flag = 1;
		else if (fmt[*i] == ' ')
			flag->space_flag = 1;
		else if (fmt[*i] == '#')
			flag->hash_flag = 1;
		else if (fmt[*i] == '-')
			flag->minus_flag = 1;
		(*i)++;
	}
}
/*----------------------------------------------------------------------------------------------*/
/*format string %s */
/*----------------------------------------------------------------------------------------------*/
int	string_case_check_one(const char *str, t_format *flg, int *w_nbr, int len)
{
	int count, j;
	count = 0;
	j = 0;
	*w_nbr -= len;
	if (flg->minus_flag == 1)
	{
		while (str[j])
			count += write(1, &str[j++], 1);
		while ((*w_nbr)-- > 0)
			count += ft_putchar(' ');
	}
	else
	{
		while ((*w_nbr)-- > 0)
			count += ft_putchar(' ');
		while (str[j])
			count += write(1, &str[j++], 1);
	}
	return (count);
}

int	string_case_check_two(const char *str, t_format *flg, int *w_nbr, int p_nbr)
{
	int count, j;
	count = 0;
	j = 0;
	*w_nbr -= p_nbr;
	if (flg->minus_flag == 1)
	{
		while (str[j] && j < p_nbr)
			count += write(1, &str[j++], 1);
		while ((*w_nbr)-- > 0)
			count += ft_putchar(' ');
	}
	else
	{
		while ((*w_nbr)-- > 0)
			count += ft_putchar(' ');
		while (str[j] && j < p_nbr)
			count += write(1, &str[j++], 1);
	}
	return (count);
}

int	string_case_check_three(const char *str, t_format *flg, int *w_nbr,
		int p_nbr)
{
	int count, j;
	j = 0;
	count = 0;
	if (*w_nbr <= p_nbr)
		*w_nbr = 0;
	else
		*w_nbr -= p_nbr;
	if (flg->minus_flag == 1)
	{
		while (str[j] && j < p_nbr)
			count += write(1, &str[j++], 1);
		while ((*w_nbr)-- > 0)
			count += ft_putchar(' ');
	}
	else
	{
		while ((*w_nbr)-- > 0)
			count += ft_putchar(' ');
		while (str[j] && j < p_nbr)
			count += write(1, &str[j++], 1);
	}
	return (count);
}
/*----------------------------------------------------------------------------------------------*/
/*format string %c */
/*----------------------------------------------------------------------------------------------*/
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
/*----------------------------------------------------------------------------------------------*/
/* format string %d and %i*/
/*----------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/

int	ft_printf(const char *fmt, ...)
{
	va_list		list;
	t_format	flg;
	char		c;
	char		*str;

	int i, j, len, count, w_nbr, p_nbr, num;
	num = 0;
	p_nbr = -1;
	count = 0;
	w_nbr = -1;
	va_start(list, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			flag_check(fmt, &i, &flg);
			if (fmt[i] >= '0' && fmt[i] <= '9')
			{
				w_nbr = 0;
				while (fmt[i] >= '0' && fmt[i] <= '9')
					w_nbr = (w_nbr * 10 + (fmt[i++] - '0'));
			}
			if (fmt[i] == '.')
			{
				i++;
				p_nbr = 0;
				while (fmt[i] >= '0' && fmt[i] <= '9')
					p_nbr = (p_nbr * 10 + (fmt[i++] - '0'));
			}
			if (fmt[i] == 'c')
			{
				c = va_arg(list, int);
				if (w_nbr != -1)
					count += char_case_check(c, &flg, w_nbr);
				else
					count += ft_putchar(c);
			}
			else if (fmt[i] == 's')
			{
				j = 0;
				str = va_arg(list, char *);
				len = ft_strlen(str);
				if (p_nbr >= 0 && p_nbr <= len && w_nbr <= len)
					count += string_case_check_three(str, &flg, &w_nbr, p_nbr);
				else if (p_nbr >= 0 && p_nbr <= len && w_nbr > len)
					count += string_case_check_two(str, &flg, &w_nbr, p_nbr);
				else if (w_nbr != -1 && w_nbr > len)
					count += string_case_check_one(str, &flg, &w_nbr, len);
				else
				{
					ft_putstr(str);
					count += len;
				}
			}
			else if ((fmt[i] == 'd') || (fmt[i] == 'i'))
			{
				num = va_arg(list, int);
				len = num_len(num);
				if(w_nbr > len && p_nbr > len)
				{
					if(w_nbr <= p_nbr)
						count += number_format_case_two(p_nbr, count, &flg, num, len);
					else
						count += number_format_case_three(p_nbr, w_nbr, count, &flg, num, len);
				}
				else if (w_nbr > len && w_nbr != -1)
					count += number_format_case_one(w_nbr, count, &flg, num, len);
				else if(p_nbr > len && p_nbr != -1)
					count += number_format_case_two(p_nbr, count, &flg, num, len);
				else
					count += else_case_number_format(&flg, num, len);
			}
			i++;
		}
		else
		{
			count += write(1, &fmt[i], 1);
			if (count == -1)
				return (-1);
			i++;
		}
	}
	va_end(list);
	return (count);
}
int	main(void)
{
	/*  numbers test cases for %d and %i */
	int num =  +1000;
	int num1 = -1000;
	// int len1 = ft_printf("|%d|\n", num);
	// int len2 = printf("|%d|\n", num);
	// printf("my len: %d\n", len1);
	// printf("og len: %d", len2);
	// char	*str = "yelukmnsdjknvskjdnckjdsnckjdsncnkjcndskjcndseee";
	// char 	c = 'a';

	// int len1 = ft_printf("|%0d||%0i||%0d||%0i|\n", num, num, num, num);
	// int len2 = ft_printf("|%0d||%0i||%0d||%0i|\n", num1, num1, num1, num1);
	// int len3 = printf("|%0d||%0i||%0d||%0i|\n", num, num, num, num);
	// int len4 = printf("|%0d||%0i||%0d||%0i|\n", num1, num1, num1, num1);
	// printf("my len positive: %d\n", len1);
	// printf("my len negative: %d\n", len2);
	// printf("og len positive: %d\n", len3);
	// printf("og len negative: %d\n", len4);

	// int len1 = ft_printf("|%-100d|\n", num);
	// int len2 = printf("|%-100d|\n", num);
	// printf("my len: %d\n", len1);
	// printf("og len: %d", len2);

	// int len1 = ft_printf("|%0-100d|\n", num);
	// int len2 = printf("|%0-100d|\n", num);
	// printf("my len: %d\n", len1);
	// printf("og len: %d", len2);

	// int len1 = ft_printf("|%0100d|\n", num);
	// int len2 = printf("|%0100d|\n", num);
	// printf("my len: %d\n", len1);
	// printf("og len: %d", len2);

	/*  numbers test cases for %d and %i */
	
	/*  string  and character test cases for %c and %s */

	
	// char	c = 'c';

	// int len1 = ft_printf("|%-10c word %10c word %10c|\n", c, c, c);
	// int len2 = printf("|%-10c word %10c word %10c|\n", c, c, c);
	// printf("%d\n", len);
	// printf("%d\n", len1);

	// int len1 = ft_printf("||%-10.5s||%-0.0s||%-10c||%-10c|||%10.5d||%10.5i||%10.5d||%10.5i|\n", str, str, c,c,num,num,num1,num1);
	// int len2 = printf("||%-10.5s||%-0.0s||%-10c||%-10c|||%10.5d||%10.5i||%10.5d||%10.5i|\n", str, str, c,c,num,num,num1,num1);
	// printf("mine test 1:  %d\n", len1);
	// printf("original test 1:  %d\n", len2);

	// int len1 = ft_printf("|%-1500.0s %-1500.0s|\n", str,str); 
	// int len2 = printf("|%-1500.0s %-1500.0s|\n", str,str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-1500.0s|\n", str);
	// int len2 = printf("|%-1500.0s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-----100s|\n", str);
	// int len2 = printf("|%-----100s|\n", str);
	// printf("mine test 2:  %d\n", len1);
	// printf("original test 2:  %d\n", len2);

	// int len1 = ft_printf("|%100s\n %-100s|\n", str, str);
	// int len2 = printf("|%100s\n %-100s|\n", str, str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%.5s|\n", str);
	// int len2 = printf("|%.5s|\n", str);
	// printf("mine test 4:  %d\n", len1);
	// printf("original test 4:  %d\n", len2);

	// int len1 = ft_printf("|%.50s|\n", str);
	// int len2 = printf("|%.50s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-.5000s|\n", str);
	// int len2 = printf("|%-.5000s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%0.0s|\n", str);
	// int len2 = printf("|%0.0s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%0.1s|\n", str);
	// int len2 = printf("|%0.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-0.1s|\n", str);
	// int len2 = printf("|%-0.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%1.1s|\n", str);
	// int len2 = printf("|%1.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%10.1s|\n", str);
	// int len2 = printf("|%10.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-10.1s|\n", str);
	// int len2 = printf("|%-10.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%100.1s|\n", str);
	// int len2 = printf("|%100.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%100.100s|\n", str);
	// int len2 = printf("|%100.100s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-100.100s\n%100.100s|\n", str,str);
	// int len2 = printf("|%-100.100s\n%100.100s|\n", str,str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-1000.1s|\n", str);
	// int len2 = printf("|%-1000.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%1.10000s|\n", str);
	// int len2 = printf("|%1.10000s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%0.10000s|\n", str);
	// int len2 = printf("|%0.10000s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%1000.1s\n%1000.1s|\n", str,str);
	// int len2 = printf("|%1000.1s\n%1000.1s|\n", str,str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	// int len1 = ft_printf("|%-10000.1s|\n", str);
	// int len2 = printf("|%-10000.1s|\n", str);
	// printf("mine test 3:  %d\n", len1);
	// printf("original test 3:  %d\n", len2);

	/*  string  and character test cases for %c and %s */

}
