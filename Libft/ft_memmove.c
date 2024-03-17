/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:03:51 by pemarti2          #+#    #+#             */
/*   Updated: 2024/02/14 20:16:51 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	char unsigned		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *) dst;
	src_cpy = (const unsigned char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (len != i)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	}
	else
	{
		while (len-- != 0)
			dst_cpy[len] = src_cpy[len];
	}
	return (dst);
}
