//funciones autorizadas : write, malloc, free, va_start, va_arg, va_copy, va_end

// %c Imprime un solo carácter.
// %s Imprime una string (como se define por defecto en C).
// %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// %d Imprime un número decimal (base 10).
// %i Imprime un entero en base 10.
// %u Imprime un número decimal (base 10) sin signo.
// %x Imprime un número hexadecimal (base 16) en minúsculas.
// %X Imprime un número hexadecimal (base 16) en mayúsculas.
// % % para imprimir el símbolo del porcentaje.

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


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

int ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void print_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	write(1, str, ft_strlen(str));
}

void print_int(va_list args)
{
	int		i;
	char	*str;

	i = va_arg(args, int);
	str = ft_itoa(i);
	write(1, str, ft_strlen(str));
}

void print_hex(va_list args)
{
	unsigned int	i;
	char	*str;

	i = va_arg(args, unsigned int);
	str = ft_itoa_base(i, "0123456789abcdef");
	write(1, str, ft_strlen(str));
}

void print_hex_mayus(va_list args)
{
	unsigned int	i;
	char	*str;

	i = va_arg(args, unsigned int);
	str = ft_itoa_base(i, "0123456789ABCDEF");
	write(1, str, ft_strlen(str));
}

void print_pointer(va_list args)
{
	unsigned long	i;
	char	*str;

	i = va_arg(args, unsigned long);
	str = ft_itoa_base(i, "0123456789abcdef");
	write(1, "0x", 2);
	write(1, str, ft_strlen(str));
}

void print_unsigned(va_list args)
{
	unsigned int	i;
	char	*str;

	i = va_arg(args, unsigned int);
	str = ft_itoa(i);
	write(1, str, ft_strlen(str));
}

int ft_printf(char const *input_print, ...)
{
	va_list	args;
	int	i;

	i = 0;
	va_start(args, input_print);
	while (input_print[i])
	{
		if (input_print[i] == '%')
		{	
			i++;
			if (input_print[i] == 'd' || input_print[i] == 'i')
				print_int(args);
			if (input_print[i] == 's')
				print_string(args);
			if (input_print[i] == 'p')
				print_pointer(args);
			if (input_print[i] == 'c')
				write(1, &(char){va_arg(args, int)}, 1);
			if (input_print[i] == '%')
				write(1, "%", 1);
			if (input_print[i] == 'x')
				print_hex(args);
			if (input_print[i] == 'X')
				print_hex_mayus(args);
			if (input_print[i] == 'u')
				print_unsigned(args);
		}
		else
			write(1, &input_print[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	//test of all functions
	int a = 42;
	ft_printf("Hello %s, %d, %i, %u, %x, %X, %p, %c, %%", '\0', 42, 42, 42, 42, 42, &a, "hola");
	printf("\n");
	printf("Hello %s, %d, %i, %u, %x, %X, %p, %c, %%", '\0', 42, 42, 42, 42, 42, &a, "hola");
	printf("\n");
	return (0);
}