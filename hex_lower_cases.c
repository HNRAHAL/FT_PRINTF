#include "ft_printf_bonus.h"

	void hexnumber_case_one(const char *str, t_format *flg, int w_nbr, int len, int *count)
	{
		*count = 1;
		if(flg->hash_flag)
		{
			w_nbr -= len + 2;
			*count += 2;
		}
		else
			w_nbr -= len;

		if(flg->minus_flag && flg->hash_flag || flg->zero_flag && flg->hash_flag)
			combined_flags_hex_case_one(str,flg,w_nbr,len,count);
		else if(flg->minus_flag||flg->hash_flag)
			single_flags_hex_case_one(str,flg,w_nbr,len,count);
		else
		{
			hex_case_check_padding(flg, w_nbr, count);
			printing_string_hex(flg, len, str, w_nbr, count);
		}
	}

    void hexnumber_case_two(const char *str, t_format *flg, int p_nbr, int len, int *count)
	{
		*count = 1;
		p_nbr -= len;
		if(flg->hash_flag)
		{
			ft_putstr("0x");
			*count += 2;
		}
		while(p_nbr-- > 0)
			*count += ft_putchar('0');
		while (len-- > 0)
			*count += write(1, &str[len], 1);
	}

    void hexnumber_case_three(const char *str, t_format *flg, int p_nbr, int w_nbr,int len, int *count)
	{
		if(flg->hash_flag)
		{
			w_nbr -= p_nbr + 2;
			*count += 2;
		}
		else
			w_nbr -= p_nbr;
		p_nbr-=len;
		if(flg->hash_flag && flg->minus_flag || flg->hash_flag)
			hex_cases_in_case_three(str,flg,w_nbr,p_nbr,len,count);
		else if(flg->minus_flag)
		{
			while(p_nbr-- > 0)
				*count += ft_putchar('0');
			printing_string_hex(flg,len,str,w_nbr, count);
			hex_case_check_padding(flg, w_nbr, count);
		}
		else
		{
			while(w_nbr-- > 0)
				*count += ft_putchar(' ');
			while(p_nbr-- > 0)
				*count += ft_putchar('0');
			printing_string_hex(flg,len,str,w_nbr, count);
		}
	}