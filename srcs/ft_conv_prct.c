/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_prct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:50:42 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_prct(char **strr, int index)
{
	size_t	str_len;
	char	*temp;
	char	*ret;

	if (!strr)
		return (-1);
	str_len = ft_strlen(strr[index]);
	if (strr[index][0] == '%' && strr[index][str_len - 1] == '%')
	{
		ret = malloc(2);
		ret[0] = '%';
		ret[1] = '\0';
	}
	else
		return (-1);
	temp = strr[index];
	strr[index] = ret;
	free(temp);
	return (0);
}
