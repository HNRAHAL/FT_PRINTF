#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int	zero_flag;
	int	minus_flag;
	int	plus_flag;
	int	hash_flag;
	int	space_flag;
}		t_format;



int		ft_printf(const char *fmt, ...);
void	flag_check(const char *fmt, int *i, t_format *flag);
int		ft_putchar(char c);
char	*ft_putstr(char *s);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		num_len(int n);



//All Cases for the %d and %i format
int 	number_format_case_one(int w_nbr, int count, t_format *flg, int num, int len);
int 	number_format_case_two(int p_nbr, int count, t_format *flg, int num, int len);
int 	number_format_case_three(int p_nbr, int w_nbr, int count, t_format *flg, int num, int len);
int 	else_case_number_format(t_format *flg, int num, int len);
//Helper functions 1:
int 	padding_option(t_format *flg, int w_nbr);
void 	positive_case(int num, t_format *flg, int *count, int *w_nbr);
void 	negative_case(int *num, t_format *flg);
void 	double_flag_combination_check(t_format *flg, int w_nbr, int len, int num, int *count);
void 	single_flag_combination_check(t_format *flg, int w_nbr, int len, int num, int *count);
//Helper functions 2:
int 	padding_width(int w_nbr);
int 	padding_prescion(int p_nbr);
int 	zero_case_number_format(int p_nbr, int w_nbr, int count, t_format *flg, int num, int len);
int 	else_case_number_format2(int p_nbr, int w_nbr, int count, t_format *flg, int num, int len);




#endif