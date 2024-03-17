/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:03:08 by pemarti2          #+#    #+#             */
/*   Updated: 2024/02/14 21:16:32 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countd(int n)
{
	int	response;

	response = 0;
	if (n < 0)
		response++;
	while (n != 0)
	{
		n /= 10;
		response++;
	}
	return (response);
}

int	ft_modulus(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*response;
	char	*presponse;
	int		countn;

	countn = ft_countd(n);
	if (countn == 0)
		return (ft_strdup("0"));
	response = (char *) ft_calloc((countn + 1), sizeof(char));
	if (!response)
		return (NULL);
	presponse = response;
	if (n < 0)
		*presponse = '-';
	presponse += countn;
	*presponse = '\0';
	while (presponse > response)
	{
		countn = n % 10;
		n /= 10;
		if (*(--presponse) != '-')
			*presponse = ft_modulus(countn) + 48;
	}
	return (response);
}
