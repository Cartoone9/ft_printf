/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:01:13 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(char **strr)
{
	size_t	i;

	i = 0;
	while (strr[i] != NULL)
	{
		free(strr[i]);
		strr[i] = NULL;
		i++;
	}
	if (strr)
	{
		free(strr);
		strr = NULL;
	}
}
