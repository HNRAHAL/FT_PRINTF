#include "ft_printf_bonus.h"
#include <stdio.h>

int char_case(char c, int width_nbr, va_list list, int minus_flag)
{
    int count = 0;
    // if(minus_flag == 1 && width_nbr != 0)
    // {
    //     count += ft_putchar(va_arg(list, int));
    //     while(--width_nbr > 0)
    //         count += ft_putchar(' ');
    // }
    // else if(width_nbr != 0)
    // {
    //     while(--width_nbr > 0)
    //         count += ft_putchar(' ');
    //     count += ft_putchar(va_arg(list, int));
    // }
    // else
    //     count += ft_putchar(va_arg(list, int));
    return count;
}

// int string_case()
// {

// }

int ft_printf(const char *fmt, ...)
{
    va_list list;

    int i;
    int count = 0;
    int zero_flag = 0;
    int minus_flag = 0;
    int plus_flag = 0;
    int space_flag = 0;
    int hash_flag = 0;
    int width_nbr = 0;
    int percision_nbr;

    va_start(list, fmt);
    i = 0;
    while(fmt[i])
    {
        if(fmt[i] == '%' && fmt[i+1])
        {
            i++;
            if(fmt[i] == '0')
            {
                zero_flag = 1;
                i++;
            }
            else if(fmt[i] == '-')
            {
                minus_flag = 1;
                i++;
            }
            else if(fmt[i] == '+')
            {
                plus_flag = 1;
                i++;
            }
            else if(fmt[i] == ' ')
            {
                space_flag = 1;
                i++;
            }
            else if(fmt[i] == '#')
            {
                hash_flag = 1;
                i++;
            }

            while(fmt[i] >= '0' && fmt[i] <= '9')
            {
                width_nbr = (width_nbr * 10 + (fmt[i] - '0'));
                i++;
            }

            if(fmt[i] == '.')
            {
                i++;
                while(fmt[i] >= '0' && fmt[i] <= '9')
                {
                    percision_nbr = (percision_nbr * 10 + (fmt[i] + '0'));
                    i++;
                }
            }

            // if(fmt[i] == 'c')
            // {
            //     if(minus_flag == 1 && width_nbr != 0)
            //     {
            //         count += ft_putchar(va_arg(list, int));
            //         while(--width_nbr > 0)
            //             count += ft_putchar(' ');
            //     }
            //     else if(width_nbr != 0)
            //     {
            //         while(--width_nbr > 0)
            //             count += ft_putchar(' ');
            //         count += ft_putchar(va_arg(list, int));
            //     }
            //     else
            //         count += ft_putchar(va_arg(list, int));
            //     i++;
            // }
            else if(fmt[i] == 's')
            {
                char *str = va_arg(list, char *);
                int j = 0;
                int temp;
                if(percision_nbr != 0)
                {
                    temp = width_nbr;
                    temp-= percision_nbr;
                    while(percision_nbr-- > 0 && str[j])
                        write(1,&str[j++], 1);
                }
                if(minus_flag == 1 && width_nbr != 0 && width_nbr > ft_strlen(str))
                {
                    ft_putstr(str);
                    count += ft_strlen(str);
                    width_nbr -= ft_strlen(str);
                    while(width_nbr-- > 0)
                        count += ft_putchar(' ');
                }
                else if(width_nbr != 0 && width_nbr > ft_strlen(str))
                {
                    width_nbr -= ft_strlen(str);
                    while(width_nbr-- > 0)
                        count += ft_putchar(' ');
                    ft_putstr(str);
                    count += ft_strlen(str);
                }
                else
                {
                    ft_putstr(str);
                    count += ft_strlen(str);
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
    return count;
}

int main()
{
    // char c = 'c';

    // int len = ft_printf("|%10c bellooo %50c yelloww %10c|\n", c,c,c);
    // int len1 = printf("|%10c bellooo %50c yelloww %10c|\n", c,c,c);

    // printf("%d\n", len);
    // printf("%d\n", len1);

    char *str = "yelloww and blueee";
    int len1 = ft_printf("|%.5s|\n", str);
    int len2 = printf("|%.5s|\n", str);

    // printf("%d\n", len1);
    // printf("%d\n", len2);
}
