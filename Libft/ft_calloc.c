/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:45:53 by pemarti2          #+#    #+#             */
/*   Updated: 2024/02/06 14:42:50 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*response;

	response = malloc((count * size) * sizeof(char));
	if (!response)
		return (NULL);
	ft_memset(response, 0, count * size);
	return (response);
}
