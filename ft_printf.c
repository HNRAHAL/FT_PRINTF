#include "ft_printf.h"
#include <stdio.h>


int ft_printf(const char *fmt, ...)
{
    char *str;
    int c;
    int nbr;
    int i;
    int count;
    va_list list;
    va_start(list, fmt);

    i = 0;
    count = 0;
    while (fmt[i] != '\0')
    {
        while(fmt[i] != '%' && fmt[i] != '\0')
        {
            write(1, &fmt[i], 1);
            count++;
            i++;
        }

        if(fmt[i] == '\0')
            return (count);

        if(fmt[i] == '%' && fmt[i + 1] != '\0')
        {
            i++;
            if(fmt[i] == 'c')
            {
                c = va_arg(list, int);
                ft_putchar_fd(c, 1);
                count += 1;
            }

            else if(fmt[i] == 's')
            {
                str = va_arg(list, char *);
                ft_putstr_fd(str, 1);
                count += ft_strlen(str);
            }
            else if((fmt[i] == 'd') || (fmt[i] == 'i'))
            {
                nbr = va_arg(list, int);
                ft_putnbr_fd(nbr, 1);
                count += num_len(nbr);
            }
            else if(fmt[i] == 'u')
            {
                nbr = va_arg(list, unsigned int);
                ft_putnbr_unsigned_fd(nbr, 1);
                count += num_len(nbr);
            }
            else if(fmt[i] == 'x')
            {
                nbr = va_arg(list, int);
                return_hexvalue_lower(nbr);
                count += num_len(nbr);
            }
            else if(fmt[i] == 'X')
            {
                nbr = va_arg(list, int);
                return_hexvalue_upper(nbr);
                count += num_len(nbr);
            }
            else if(fmt[i] == 'p')
            {
                void *ptr = va_arg(list, void *);
                return_address_and_convert_to_hex(ptr);
                count += ft_strlen(ptr);
            }
            else if(fmt[i] == '%')
                ft_putchar_fd('%', 1);
        }
        i++;
    }
    return (count);
}

#include <stdio.h>
int main()
{
    // int len1 = ft_printf("%s\n%s\n%s\n", "ONE", "TWO", "THREE");
    // int len2 = printf("%s\n%s\n%s\n", "ONE", "TWO", "THREE");
    // printf("len1: %d\n", len1);
    // printf("len2: %d\n", len2);

    char *str = "ALLAHHHH";
    int len1 = ft_printf("address: %p\nUpper hexadecimal value: %X\nlower hexadecimal value: %x\nunsigned number: %u\nnumber: %d\nnumber2: %i\nnumber3: %d\nstring: %s\ncharacter: %c\npercent: 5%%\n",(void *)&str,2147483647,2147483647,4294967296, 214748364788, 214748364788, 98, "string", 'a');
    ft_printf("len1: %d\n", len1);
    ft_printf("--------------------------------------\n");
    int len2 = ft_printf("address: %p\nUpper hexadecimal value: %X\nlower hexadecimal value: %x\nunsigned number: %u\nnumber: %d\nnumber2: %i\nnumber3: %d\nstring: %s\ncharacter: %c\npercent: 5%%\n",(void *)&str,2147483647,2147483647,4294967296, 214748364788, 214748364788, 98, "string", 'a');
    ft_printf("len2: %d\n", len2);
    // printf("%u\n", 4294967295);
    // // printf("%u\n", -1);
    // ft_printf("%u\n", 4294967297);
    // printf("%u\n", 4294967297);

    // char *str = "Helloo";
    // ft_printf("%p\n", (void *)&str + 5);
    // printf("%p\n", (void *)&str + 5);
    return (0);
}

