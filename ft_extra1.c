#include "ft_printf.h"

int ft_nbrLen(long nbr)
{
	int	len;

	len = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int ft_nbrlen(unsigned long value, int base_len)
{
	int	len;

	len = 1;
	while (value >= (unsigned long)base_len)
	{
		value /= base_len;
		len++;
	}
	return (len);
}

char *ft_itoa_base(unsigned long value, char *base)
{
	char	*str;
	int		len;
	int		base_len;

	base_len = ft_strlen(base);
	len = ft_nbrlen(value, base_len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[value % base_len];
		value /= base_len;
	}
	return (str);
}