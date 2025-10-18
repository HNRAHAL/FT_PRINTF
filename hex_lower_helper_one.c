	#include "ft_printf_bonus.h"
    
    void	hex_case_check_padding(t_format *flg, int w_nbr, int *count)
	{
		if((flg->zero_flag) && (!flg->minus_flag || !flg->hash_flag))
		{
			while(w_nbr-- > 0)
				*count += ft_putchar('0');
		}
		else
		{
			while(w_nbr-- > 0)
				*count += ft_putchar(' ');
		}
	}

	void printing_string_hex(t_format *flg ,int len, const char *str, int w_nbr, int *count)
	{
		if(flg->hash_flag)
		{
			while (len-- > 0)
				*count += write(1, &str[len], 1);
		}
		else
		{
			while (len-- > 0)
				*count += write(1, &str[len], 1);
		}
	}
	void combined_flags_hex_case_one(const char *str, t_format *flg, int w_nbr, int len, int *count)
	{
		if(flg->minus_flag && flg->hash_flag)
		{
			ft_putstr("0x");
			printing_string_hex(flg, len, str, w_nbr, count);
			hex_case_check_padding(flg, w_nbr, count);
		}
		else if(flg->zero_flag && flg->hash_flag)
		{
			ft_putstr("0x");
			hex_case_check_padding(flg, w_nbr, count);
			printing_string_hex(flg, len, str, w_nbr, count);
		}
	}
	void single_flags_hex_case_one(const char *str, t_format *flg, int w_nbr, int len, int *count)
	{
		if (flg->minus_flag)
		{
			printing_string_hex(flg, len, str, w_nbr, count);
			hex_case_check_padding(flg, w_nbr, count);
		}
		else if(flg->hash_flag)
		{
			hex_case_check_padding(flg, w_nbr, count);
			ft_putstr("0x");
			printing_string_hex(flg, len, str, w_nbr, count);
		}
	}

	void hex_cases_in_case_three(const char *str, t_format *flg, int w_nbr, int p_nbr, int len, int *count)
	{
		if(flg->hash_flag && flg->minus_flag)
		{
			ft_putstr("0x");
			while(p_nbr-- > 0)
				*count += ft_putchar('0');
			printing_string_hex(flg,len,str,w_nbr, count);
			hex_case_check_padding(flg, w_nbr, count);
		}
		else if(flg->hash_flag)
		{
			hex_case_check_padding(flg, w_nbr, count);
			ft_putstr("0x");
			while(p_nbr-- > 0)
				*count += ft_putchar('0');
			printing_string_hex(flg,len,str,w_nbr, count);
		}
	}
	