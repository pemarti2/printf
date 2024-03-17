/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:20:00 by pemarti2          #+#    #+#             */
/*   Updated: 2024/02/06 15:09:43 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	j;

	j = ft_strlen(s);
	if (!s)
		return (NULL);
	while (j >= 0)
	{
		if (s[j] == (char) c)
			return ((char *) &s[j]);
		j--;
	}
	return (NULL);
}
