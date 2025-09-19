#include "ft_printf.h"

int   ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int    ft_putstr(char *s)
{
    int i;

    i = 0;
    if(!s)
        return(0);

    while(s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return i;
}

int    ft_putnbr(int n)
{
    int count;
    count = 0;
    if(n == INT_MIN)
    {
        ft_putstr("-2147483648");
        return(10);
    }
    if(n == INT_MAX)
    {
        ft_putstr("2147483647");
        return(11);
    }
    if(n < 0)
    {
        count += ft_putchar('-');
        n = -n; 
    }
    if (n >= 10)
    {
        count += ft_putnbr(n/10);
    }
    count += ft_putchar((n % 10) + '0');
    return count;
}

int    ft_putnbr_unsigned( unsigned int n)
{
    int count = 0;
    if(n >= 10)
    {
        count += ft_putnbr_unsigned(n / 10);
    }
    count += ft_putchar((n % 10) + '0');
    return count;
}

int    return_address_and_convert_to_hex(void *address)
{
    int rem;
    int i;
    int count;
    char str[30];
    uintptr_t n_address;
    n_address = (uintptr_t)address;

    i = 0;
    ft_putstr("0x");
    count = 2;
    while(n_address != 0)
    {
        rem = n_address % 16;
        n_address /= 16;
        if(rem >= 10 && rem <= 15)
            str[i] = ((rem - 10) + 'a');
        else
            str[i] = rem + '0';
        i++;
        count++;
    }
    while(i > 0)
    {
        i--;
        write(1, &str[i], 1);
    }
    return (count);
}

int    return_hexvalue_lower(int n)
{
    int rem;
    int count;
    char str[30];
    int i = 0;

    if(n == 0)
    {
        ft_putchar('0');
        return (1);
    }
    count = 0;
    while(n != 0)
    {
        rem = n % 16;
        n /= 16;
        if(rem >= 10 && rem <= 15)
            str[i] = ((rem - 10) + 'a');
        else
            str[i] = rem + '0';
        i++;
        count++;
    }
    str[i] = '\0';
    while(i >= 0)
    {
        i--;
        write(1, &str[i], 1);
    }
    return count;
}

int    return_hexvalue_upper(int n)
{
    int rem;
    int count;
    char str[30];
    int i = 0;

    if(n == 0)
    {
        ft_putchar('0');
        return (1);
    }
    count = 0;
    while(n != 0)
    {
        rem = n % 16;
        n /= 16;
        if(rem >= 10 && rem <= 15)
            str[i] = ((rem - 10) + 'A');
        else
            str[i] = rem + '0';
        i++;
        count++;
    }
    str[i] = '\0';
    while(i >= 0)
    {
        i--;
        write(1, &str[i], 1);
    }
    return count;
}

size_t  ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return i;
}

int     num_len(int n)
{
    int count = 0;
    if(n == 0)
        return (1);
    while(n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}