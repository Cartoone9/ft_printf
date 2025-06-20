/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:03 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c_uc;
	size_t			i;

	c_uc = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == c_uc)
			return ((char *)&str[i]);
		i++;
	}
	if (c_uc == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
