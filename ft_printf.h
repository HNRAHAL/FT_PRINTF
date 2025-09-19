# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


int     ft_printf(const char *, ...);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
size_t  ft_strlen(const char *str);
void    ft_putnbr_fd(int n, int fd);
void    ft_putnbr_unsigned_fd( unsigned int n, int fd);
void    return_hexvalue_lower(int n);
void    return_hexvalue_upper(int n);
void    return_address_and_convert_to_hex(void *address);
int     num_len(int n);

#endif