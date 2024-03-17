/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:02:27 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/19 11:02:30 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	char		*response;
	char		*presponse;
	size_t		response_l;

	response_l = ft_strlen(s1);
	end = &s1[response_l];
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (end >= s1 && ft_strchr(set, *end))
		end--;
	response_l = end - s1 + 1;
	response = (char *) malloc(sizeof(char) * (response_l + 1));
	if (response == NULL)
		return (NULL);
	presponse = response;
	while (s1 <= end)
		*presponse++ = *s1++;
	*presponse = '\0';
	return (response);
}
