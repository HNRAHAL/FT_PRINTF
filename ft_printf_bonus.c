#include "ft_printf_bonus.h"
#include <stdio.h>

int	flag_check(char c)
{
	if (c == '0')
		return (1);
	else if (c == '-')
		return (2);
	else if (c == '+')
		return (3);
	else if (c == ' ')
		return (4);
	else if (c == '#')
		return (5);

	return (0);
}

// void char_case( va_list list, int flag_nbr, int width_nbr)
// {
// 	int count;

// 	count = 0;
// 	char c = va_arg(list, int);
// 	if(width_nbr != 0 && flag_nbr == 2) 
// 	{
// 		count += ft_putchar(c);
// 		while (--width_nbr > 0)
// 			count += ft_putchar(' ');
// 	}
// 	else if(width_nbr != 0)
// 	{
// 		while(--width_nbr > 0)
// 			count += ft_putchar(' ');
// 		count += ft_putchar(c);
// 	}
// 	else
// 		count += ft_putchar(c);
// }

int	ft_printf(const char *fmt, ...)
{
	va_list	list;

	int i, count, flag_nbr, width_nbr, percision_nbr;
	count = 0;
	width_nbr = 0;
	va_start(list, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			flag_nbr = 0;
			if (fmt[i] == '0' || fmt[i] == '-' || fmt[i] == '+' || fmt[i] == ' '
				|| fmt[i] == '#')
                flag_nbr = flag_check(fmt[i++]);

			while (fmt[i] >= '0' && fmt[i] <= '9')
			{
				width_nbr = (width_nbr * 10 + (fmt[i] - '0'));
				i++;
			}

			if (fmt[i] == '.')
			{
				i++;
				while (fmt[i] >= '0' && fmt[i] <= '9')
				{
					percision_nbr = (percision_nbr * 10 + (fmt[i] - '0'));
					i++;
				}
			}
			if (fmt[i] == 'c')
			{
                char c = va_arg(list, int);
                if(width_nbr != 0 && flag_nbr == 2) // 2 = minus_flag
                {
                    count += ft_putchar(c);
                    while (--width_nbr > 0)
                        count += ft_putchar(' ');
                }
                else if(width_nbr != 0)
                {
                    while(--width_nbr > 0)
                        count += ft_putchar(' ');
                    count += ft_putchar(c);
                }
                else
                    count += ft_putchar(c);
                i++;
			}
			else if(fmt[i] == 's')
			{
				int j = 0;
				char *str = va_arg(list, char *);
				int len = ft_strlen(str);
				if(flag_nbr == 2 && percision_nbr != 0 && width_nbr != 0)
				{
					while(str[j] && j < percision_nbr)
						count += write(1, &str[j++], 1);
					while(width_nbr-- > 0)
						count += ft_putchar(' ');
				}
				else if(percision_nbr != 0 && percision_nbr < len && width_nbr != 0)
				{
					width_nbr -= percision_nbr;
					while(width_nbr-- > 0)
						count += ft_putchar(' ');
					while(str[j] && j < percision_nbr)
						count += write(1, &str[j++], 1);
				}
				else if(width_nbr != 0 && width_nbr > len)
				{
					width_nbr -= len;
					while(width_nbr-- > 0)
						count += ft_putchar(' ');
					while(str[j])
						write(1, &str[j++], 1);
					count += len;
				}
				else
				{
					ft_putstr(str);
					count += len;
				}
				i++;
			}
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
	// char	c;
	// int		len;
	// int		len1;

	// c = 'c';
	// len = ft_printf("|%-10c word %10c word %10c|\n", c, c, c);
	// len1 = printf("|%-10c word %10c word %10c|\n", c, c, c);
	// printf("%d\n", len);
	// printf("%d\n", len1);


	char *str = "yelloww and blueee";
	int len1 = ft_printf("|%-10.2s|\n", str);
	int len2 = printf("|%-10.2s|\n", str);
	printf("%d\n", len1);
	printf("%d\n", len2);
}

// else if(fmt[i] == 's')
// {
//     char *str = va_arg(list, char *);
//     int j = 0;
//     int temp;
//     if(percision_nbr != 0)
//     {
//         temp = width_nbr;
//         temp-= percision_nbr;
//         while(percision_nbr-- > 0 && str[j])
//             write(1,&str[j++], 1);
//     }
//     if(minus_flag == 1 && width_nbr != 0
// && width_nbr > ft_strlen(str))
//     {
//         ft_putstr(str);
//         count += ft_strlen(str);
//         width_nbr -= ft_strlen(str);
//         while(width_nbr-- > 0)
//             count += ft_putchar(' ');
//     }
//     else if(width_nbr != 0 && width_nbr > ft_strlen(str))
//     {
//         width_nbr -= ft_strlen(str);
//         while(width_nbr-- > 0)
//             count += ft_putchar(' ');
//         ft_putstr(str);
//         count += ft_strlen(str);
//     }
//     else
//     {
//         ft_putstr(str);
//         count += ft_strlen(str);
//     }
//     i++;
// }