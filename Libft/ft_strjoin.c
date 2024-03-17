/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:02:04 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/19 15:14:45 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total1;
	size_t	total2;
	char	*response;

	total1 = ft_strlen(s1);
	total2 = ft_strlen(s2);
	response = malloc(total1 + total2 + 1);
	if (!response)
		return (NULL);
	ft_strlcpy(response, (char *) s1, total1 + 1);
	ft_strlcat(&response[total1], (char *) s2, total2 + 1);
	return (response);
}
