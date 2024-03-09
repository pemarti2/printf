#include "ft_printf.h"

int	ft_printf_write(int c, int i)
{
	i++;
	write (1, &c, 1);
	return (i);
}

int	ft_found_u(unsigned int u)
{
	unsigned int	len;

	len = 0;
	if (u >= 10)
	{
		len += ft_found_u(u / 10);
		len += ft_found_u(u % 10);
	}
	if (u < 10)
		len = ft_printf_write(u + 48, len);
	return (len);
}

char *ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;
	long	nbr;

	nbr = n;
	neg = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		neg = 1;
	}
	len = ft_nbrLen(nbr);
	if (neg)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}