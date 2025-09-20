/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:12:34 by hrahal            #+#    #+#             */
/*   Updated: 2025/09/20 19:04:22 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case_check(const char *fmt, int count, va_list list)
{
	if (*fmt == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (*fmt == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (*fmt == 'd' || *fmt == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (*fmt == 'u')
		count += ft_putnbr_unsigned(va_arg(list, unsigned int));
	else if (*fmt == 'x')
		count += return_hexvalue_lower(va_arg(list, int));
	else if (*fmt == 'X')
		count += return_hexvalue_upper(va_arg(list, int));
	else if (*fmt == 'p')
		count += return_address_and_convert_to_hex(va_arg(list, void *));
	else if (*fmt == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	list;

	va_start(list, fmt);
	i = 0;
	count = 0;
	while (fmt[i] != '\0')
	{
		while (fmt[i] != '%' && fmt[i] != '\0')
		{
			count += write(1, &fmt[i], 1);
			i++;
		}
		if (fmt[i] == '\0')
			return (count);
		if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			i++;
			count = case_check(&fmt[i], count, list);
		}
		i++;
	}
	va_end(list);
	return (count);
}

#include <stdio.h> // CHECK FOR NULL TESTINGGGGGG

int	main(void)
{
    // int my_len = ft_printf("%c\n%c\n%c\n%s\n%s\n%s\n%d\n%d\n%i\n%i\n",'a','a','a', "one","two","three",22,55,0,1);
	// printf("-----------------------------------\n");
    // int og_len = printf("%c\n%c\n%c\n%s\n%s\n%s\n%d\n%d\n%i\n%i\n",'a','a','a', "one","two","three",22,55,0,1);
	// printf("-----------------------------------\n");
    // printf("my len: %d\n", my_len);
	// printf("org len: %d\n", og_len);

    // int my_len = ft_printf("%X\n%X\n%X\n", 45555556, 6698986, 10006980);
	// printf("-----------------------------------\n");
    // int og_len = printf("%X\n%X\n%X\n", 45555556, 6698986, 10006980);
	// printf("-----------------------------------\n");
    // printf("my len: %d\n", my_len);
    // printf("og len: %d\n", og_len);

	// int x = 24;
	// int *ptr = &x;
	// int my_len = ft_printf("%p\n", ptr);
	// printf("-----------------------------------\n");
	// int og_len = printf("%p\n", ptr);
	// printf("-----------------------------------\n");
	// printf("my len: %d\n", my_len);
	// printf("og len: %d\n", og_len);

	// int len1 = ft_printf("5%%\n6%%\n");
	// printf("-----------------------------------\n");
	// int len2 = printf("5%%\n6%%\n");
	// printf("-----------------------------------\n");
	// printf("len1: %d\n", len1);
	// printf("len2: %d\n", len2);
	// return (0);
	ft_printf("%s\n", NULL);
	printf("%s", NULL);
// NULL TESTINGGGGG: DONT FORGETTTTTTTT

}
