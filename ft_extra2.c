/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:02:27 by pemarti2          #+#    #+#             */
/*   Updated: 2024/03/09 11:02:30 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list args)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

int	print_int(va_list args)
{
	int		i;
	char	*str;

	i = va_arg(args, int);
	str = ft_itoa(i);
	i = ft_strlen(str);
	write(1, str, i);
	if (str)
		free(str);
	return (i);
}

int	print_hex(va_list args, char c)
{
	unsigned int	i;
	char			*str;

	i = va_arg(args, unsigned int);
	str = ft_itoa_base(i, "0123456789abcdef");
	i = ft_strlen(str);
	if (c == 'X')
	{
		i = -1;
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	}
	write(1, str, i);
	if (str)
		free(str);
	return (i);
}
