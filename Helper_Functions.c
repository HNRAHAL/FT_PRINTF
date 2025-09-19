#include "ft_printf.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if(!s)
        return;

    while(s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

void    ft_putnbr_fd(int n, int fd)
{

    if(n == INT_MIN)
    {
        ft_putstr_fd("-2147483648", 1);
        return;
    }
    if(n == INT_MAX)
    {
        ft_putstr_fd("2147483647", 1);
        return;
    }
    if(n < 0)
    {
        ft_putchar_fd('-', 1);
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n/10, 1);
    }
    ft_putchar_fd((n % 10) + '0', 1);
}

void    ft_putnbr_unsigned_fd( unsigned int n, int fd)
{
    if(n >= 10)
    {
        ft_putnbr_unsigned_fd(n / 10, 1);
    }
    ft_putchar_fd((n % 10) + '0', 1);

}

void    return_address_and_convert_to_hex(void *address)
{
    int rem;
    int i;
    char str[30];
    uintptr_t n_address;
    n_address = (uintptr_t)address;

    i = 0;
    while(n_address != 0)
    {
        rem = n_address % 16;
        n_address /= 16;
        if(rem >= 10 && rem <= 15)
            str[i] = ((rem - 10) + 'A');
        else
            str[i] = rem + '0';
        i++;
    }
    while(i < 16)
        str[i++] = '0';
    while(i > 0)
    {
        i--;
        write(1, &str[i], 1);
    }
}

void    return_hexvalue_lower(int n)
{
    int rem;
    char str[30];
    int i = 0;

    if(n == 0)
        ft_putchar_fd('0', 1);

    while(n != 0)
    {
        rem = n % 16;
        n /= 16;
        if(rem >= 10 && rem <= 15)
            str[i] = ((rem - 10) + 'a');
        else
            str[i] = rem + '0';
        i++;
    }
    str[i] = '\0';
    while(i >= 0)
    {
        i--;
        write(1, &str[i], 1);
    }
}

void    return_hexvalue_upper(int n)
{
    int rem;
    char str[30];
    int i = 0;

    if(n == 0)
        ft_putchar_fd('0', 1);

    while(n != 0)
    {
        rem = n % 16;
        n /= 16;
        if(rem >= 10 && rem <= 15)
            str[i] = ((rem - 10) + 'A');
        else
            str[i] = rem + '0';
        i++;
    }
    str[i] = '\0';
    while(i >= 0)
    {
        i--;
        write(1, &str[i], 1);
    }
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