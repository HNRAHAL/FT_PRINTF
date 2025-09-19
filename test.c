#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

// int main()
// {
//     int number = 100;
//     int *str = &number;
//     printf("character: [%c]\n", 'a');
//     printf("string: [%s]\n", "byeeeeeeeee");
//     printf("pointer: [%p]\n", str);
//     printf("decimal: [%d]\n", 156987);
//     printf("decimal (i): [%i]\n", 987456);
//     printf("unsigned decimal: [%u]\n", 99999);
//     printf("hexadecimal lower case: [%x]\n", 123);
//     printf("hexadecimal upper case: [%X]\n", 123);
//     printf("percent sign: [8%%]\n");
// }

// void print(int n, ...)
// {
//     int i;
//     va_list args;
//     va_start(args, n);

//     i = 0;
//     while(i < n)
//     {
//         printf("%d", va_arg(args, int));
//         i++;
//     }
//     printf("\n");
//     va_end(args);
// }

// int getsum(int n, ...)
// {
//     int i;
//     int sum = 0;
//     va_list list;
//     va_start(list, n);

//     i = 0;
//     while(i < n)
//     {
//         sum += va_arg(list, int);
//         i++;
//     }
//     va_end(list);
//     return sum;
// }

// void print_strings(const char *sep, unsigned int n, ...)
// {
//     int i;
//     char *str;
//     va_list list;
//     va_start(list, n);

//     i = 0;
//     while(i < n)
//     {
//         str = va_arg(list, char *);
//         if(sep != NULL && i > 0)
//             printf("%s", sep);
//         if(str == NULL)
//             printf("null");
//         else
//             printf("%s", str);
//         i++;
//     }
//     va_end(list);
// }

// int find_max_value(unsigned int count, ...)
// {
//     int i;
//     int num;
//     int largest_val;
//     va_list num_list;
//     va_start(num_list, count);
//     largest_val = va_arg(num_list, int);
//     if(count == 1)
//         return largest_val;
//     i = 1;
//     while(i < count)
//     {
//         num = va_arg(num_list, int);
//         if(num > largest_val)
//             largest_val = num;
//         i++;
//     }
//     va_end(num_list);
//     return largest_val;
// }

// int main()
// {
//     // printf("sum1: %d\n", getsum(3, 1,2,3));
//     // printf("sum2: %d\n", getsum(5,1,2,3,4,5));
//     // printf("sum3: %d\n", getsum(10,1,2,3,4,5));

//     // print(5,1,2,3,4,5);
//     // print(2,1,2);
//     // print(4,1,3,5,7);

//     // print_strings(2, "Jay ", "Django");
//     // return (0);

//     // printf("%d", find_max_value(2, 1000,2));
// }

int   ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
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

int main()
{
    printf("\n");
    int len = ft_putnbr_unsigned(100);

}