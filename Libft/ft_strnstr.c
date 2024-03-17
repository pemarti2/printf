/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:06:56 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/17 15:54:52 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *) haystack);
	while (haystack[i] && i != len)
	{
		while (needle[j] == haystack[i + j] && needle[j] && i + j != len)
			j++;
		if (!needle[j])
			break ;
		else
		{
			j = 0;
			i++;
		}
	}
	if (j != 0)
		return ((char *) &haystack[i]);
	else
		return ((char *) '\0');
}
