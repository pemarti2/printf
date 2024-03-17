/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:54:48 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/11 16:09:51 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*bcpy;

	bcpy = (unsigned char *) b;
	i = 0;
	while (len != 0)
	{
		bcpy[i++] = (unsigned char) c;
		len--;
	}
	return (b);
}
