/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:14:51 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char	*ret;
	size_t	length;
	size_t	i;

	length = ft_intlen(n);
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	ret[length] = '\0';
	i = 0;
	if (n == 0)
	{
		ret[i] = '0';
		return (ret);
	}
	ft_tenrec_fill((length - 1), ret, n);
	return (ret);
}

void	ft_tenrec_fill(size_t length, char *ret, unsigned int n)
{
	if (n >= 10 && length > 0)
		ft_tenrec_fill((length - 1), ret, n / 10);
	ret[length] = (n % 10) + 48;
}

size_t	ft_intlen(unsigned int n)
{
	size_t	sum;

	if (n == 0)
		return (1);
	sum = 0;
	while (n > 0)
	{
		n /= 10;
		sum++;
	}
	return (sum);
}
