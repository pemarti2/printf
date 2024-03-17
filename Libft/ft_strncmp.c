/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:24:20 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/17 12:14:29 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				response;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	i = 0;
	response = 0;
	if (n == 0)
		return (response);
	while (us1[i] && us2[i] && response == 0 && i < n -1)
	{
		response = us1[i] - us2[i];
		if (response != 0)
			break ;
		i++;
	}
	response = us1[i] - us2[i];
	return (response);
}
