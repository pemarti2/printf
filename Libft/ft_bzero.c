/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:36:43 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/11 16:45:26 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *) s;
	if (n > 0)
	{
		while (n != 0)
		{
			*ps++ = 0;
			n--;
		}
	}
	return (s);
}
