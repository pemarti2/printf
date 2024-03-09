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

#include "ft_printf.h"

int print_hex_mayus(va_list args)
{
	unsigned int	i;
	char	*str;

	i = va_arg(args, unsigned int);
	str = ft_itoa_base(i, "0123456789ABCDEF");
	i = ft_strlen(str);
	write(1, str, i);
	if (str)
		free(str);
	return (i);
}

int print_pointer(va_list args)
{
	unsigned long	i;
	char	*str;

	i = va_arg(args, unsigned long);
	str = ft_itoa_base(i, "0123456789abcdef");
	write(1, "0x", 2);
	i = ft_strlen(str);
	write(1, str, i);
	if (str)
		free(str);
	return (i + 2);
}

int print_unsigned(va_list args)
{
	unsigned int	i;
	char	*str;

	i = va_arg(args, unsigned int);
	str = ft_itoa(i);
	i = ft_strlen(str);
	write(1, str, i);
	if (str)
		free(str);
	return (i);
}

int ft_printf(char const *input_print, ...)
{
	va_list	args;
	int	i;
	int	j;

	i = 0;
	j = 0;
	va_start(args, input_print);
	while (input_print[i])
	{
		if (input_print[i] == '%')
		{	
			i++;
			if (input_print[i] == 'd' || input_print[i] == 'i')
				j += print_int(args);
			if (input_print[i] == 's')
				j += print_string(args);
			if (input_print[i] == 'p')
				j += print_pointer(args);
			if (input_print[i] == 'c')
				j += write(1, &(char){va_arg(args, int)}, 1);
			if (input_print[i] == '%')
				j += write(1, "%", 1);
			if (input_print[i] == 'x')
				j += print_hex(args);
			if (input_print[i] == 'X')
				j += print_hex_mayus(args);
			if (input_print[i] == 'u')
				j += ft_found_u(va_arg(args, unsigned int));
		}
		else
			j += write(1, &input_print[i], 1);
		i++;
	}
	va_end(args);
	return (j);
}

/*
int main()
{
	//test of all functions
	int a = 42;
	int	i = 0;
	i = ft_printf("Hello %s, %d, %i, %u, %x, %X, %p, %c, %%%%", '\0', 42, 42, 42, 42, 42, &a, "hola");
	printf("\n%d", i);
	//i = printf("Hello %s, %d, %i, %u, %x, %X, %p, %c, %%%%", '\0', 42, 42, 42, 42, 42, &a, "hola");
	//printf("\n%d", i);
	return (0);
}
*/
