/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemarti2 <pemarti2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:02:43 by pemarti2          #+#    #+#             */
/*   Updated: 2024/01/19 11:02:46 by pemarti2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countw(char const *s, char c)
{
	const char	*ps;
	size_t		nsubs;

	ps = s;
	nsubs = 0;
	while (*ps)
	{
		while (*ps == c)
			ps++;
		if (*ps)
			nsubs++;
		while (*ps && *ps != c)
			ps++;
	}
	return (nsubs);
}

int	ft_free_null(char **pmatrix_s, char **matrix_s)
{
	if (*pmatrix_s == NULL)
	{
		while (pmatrix_s > matrix_s)
			free (*--pmatrix_s);
		free (matrix_s);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	const char	*ps;
	char		**matrix_s;
	char		**pmatrix_s;

	matrix_s = (char **) malloc(sizeof(char *) * (ft_countw(s, c) + 1));
	if (!matrix_s || !s)
		return (NULL);
	pmatrix_s = matrix_s;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		ps = s;
		while (*ps && *ps != c)
			ps++;
		*pmatrix_s = (char *) malloc(sizeof(char) * ((ps - s) + 1));
		if (ft_free_null(pmatrix_s, matrix_s) == 0)
			return (NULL);
		ft_strlcpy(*pmatrix_s++, s, (ps - s) + 1);
		s = ps;
	}
	*pmatrix_s = NULL;
	return (matrix_s);
}
