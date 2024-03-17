/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:57:20 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/18 14:34:21 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	temp;
	int	response;

	response = 0;
	temp = 0;
	while (*str && ft_isalpha(*str) != 1
		&& (*str == 43 || *str == 45 || *str == 32 || (*str >= 9 && *str < 14)))
	{
		if (*str == '-')
			temp--;
		if (*str == '+')
			temp++;
		str++;
		if (temp != 0)
			break ;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		if (temp == 0)
			temp = 1;
		response = response * 10 + (*str - 48) * temp;
		str++;
	}
	return (response);
}
