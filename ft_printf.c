/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:02:27 by pemarti2          #+#    #+#             */
/*   Updated: 2024/03/09 11:02:30 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list args)
{
	unsigned long	i;
	char			*str;

	i = va_arg(args, unsigned long);
	str = ft_itoa_base(i, "0123456789abcdef");
	write(1, "0x", 2);
	i = ft_strlen(str);
	write(1, str, i);
	if (str)
		free(str);
	return (i + 2);
}

int	print_unsigned(va_list args)
{
	int				i;
	unsigned int	u_i;
	char			*str;

	i = va_arg(args, int);
	u_i = (unsigned int) i;
	str = ft_uitoa(i);
	i = ft_strlen(str);
	write(1, str, i);
	if (str)
		free(str);
	return (i);
}

int	ft_printf_printer(char letter, va_list args)
{
	if (letter == 'd' || letter == 'i')
		return (print_int(args));
	if (letter == 's')
		return (print_string(args));
	if (letter == 'p')
		return (print_pointer(args));
	if (letter == 'c')
		return (write(1, &(char){va_arg(args, int)}, 1));
	if (letter == '%')
		return (write(1, "%", 1));
	if (letter == 'X' || letter == 'x')
		return (print_hex(args, letter));
	if (letter == 'u')
		return (print_unsigned(args));
	return (0);
}

int	ft_printf(char const *input_print, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, input_print);
	while (input_print[i])
	{
		if (input_print[i] == '%')
		{
			i++;
			j += ft_printf_printer(input_print[i], args);
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
	i = ft_printf("Hello %s, %d, %i, %u, %x, %X, %p, %c, 
	%%%% ", "d", 42, 42, 42, 42, 42, &a, 'd');
	printf("\n%d\n", i);
	i = printf("Hello %s, %d, %i, %u, %x, %X, %p, %c, 
	%%%% ", "d", 42, 42, 42, 42, 42, &a, 'd');

	printf("\n%d\n", i);
	return (0);
}
*/