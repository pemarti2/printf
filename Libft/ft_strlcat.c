/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:46:13 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/19 15:04:53 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	response;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	response = dst_len + ft_strlen(src);
	if (size == 0)
		return (response - dst_len);
	if (size < dst_len)
		return (response - dst_len + size);
	while (dst_len + 1 < size && *src)
		dst[dst_len++] = *src++;
	dst[dst_len] = '\0';
	return (response);
}
