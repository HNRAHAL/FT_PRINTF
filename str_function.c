#include "ft_printf_bonus.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

char	*ft_putstr(char *s)
{
	int	i;
	int	count;
	int	res;

	count = 0;
	res = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		res = write(1, &s[i], 1);
		if (res == -1)
			return (NULL);
		count += res;
		i++;
	}
	return (s);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}