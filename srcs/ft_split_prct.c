/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_prct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:03 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_split_prct(char const *s)
{
	char	**strr;
	char	c;
	int		j;

	c = '%';
	strr = malloc(sizeof(char *) * (ft_strcnt(s, c) + 1));
	if (!strr)
		return (NULL);
	j = ft_fillstr(strr, s, c);
	if (j == -1)
		return (NULL);
	strr[j] = NULL;
	return (strr);
}

int	ft_fillstr(char **strr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len_nstr;

	i = 0;
	j = 0;
	while (s[i])
	{
		len_nstr = ft_nextch(&s[i], c);
		strr[j] = malloc(sizeof(char) * len_nstr + 1);
		if (!strr[j])
		{
			strr[j] = NULL;
			return (ft_free(strr), -1);
		}
		k = 0;
		while (k < len_nstr)
			strr[j][k++] = s[i++];
		strr[j++][k] = '\0';
	}
	return ((int)j);
}

size_t	ft_strcnt(const char *str, char c)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		i += ft_nextch(&str[i], c);
		sum++;
	}
	return (sum);
}

size_t	ft_nextch(const char *str, char c)
{
	size_t	sum;

	sum = 0;
	if (str[sum] == c)
	{
		if (str[sum + 1] == c)
			return (2);
		sum++;
		while (str[sum] && ft_isflag(str[sum]))
			sum++;
		while ((str[sum] >= '0' && str[sum] <= '9') || str[sum] == '.')
			sum++;
		if (str[sum] && ft_isvalid(str[sum]))
			sum++;
	}
	else
	{
		while (str[sum] && str[sum] != c)
			sum++;
	}
	return (sum);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*str = " %%  %   ";
	char		**strr;
	size_t		i;

	strr = ft_split_prct(str);
	for (i = 0; strr[i] != NULL; i++)
	{
		printf("'%s'\n", strr[i]);
	}
	ft_free(strr, i);
	return (0);
}
*/
