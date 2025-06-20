/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:18:02 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tohexa(unsigned long long n_ulnln, t_flags **flags)
{
	char	*base;
	char	*temp;
	char	*ret;
	size_t	max;

	if ((*flags)->chr == 'x' || (*flags)->chr == 'p')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	max = 19;
	temp = malloc(sizeof(char) * (max));
	if (!temp)
		return (NULL);
	ft_fhexa_neg(temp, max, (*flags)->chr);
	ft_sixtreculn_fill(n_ulnln, base, temp, max);
	ret = ft_strdup(temp);
	free(temp);
	if (!ret)
		return (NULL);
	return (ret);
}

void	ft_sixtreculn_fill(unsigned long long n_ulnln, char *base, char *dest,
		size_t max)
{
	char	*temp;

	if (n_ulnln >= 16)
		ft_sixtreculn_fill(n_ulnln / 16, base, dest, max);
	temp = malloc(2);
	temp[0] = base[n_ulnln % 16];
	temp[1] = '\0';
	ft_strlcat(dest, temp, max);
	free(temp);
}

void	ft_fhexa_neg(char *str, size_t max, unsigned char chr)
{
	size_t	i;

	i = 0;
	if (chr == 'p')
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	while (i < max)
		str[i++] = '\0';
}
