/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:53:08 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_isvalid(char c)
{
	char	*list;

	list = "cspdiuxX%";
	if (ft_strchr(list, c))
		return (1);
	else
		return (0);
}

size_t	ft_isflag(char c)
{
	char	*list;

	list = "-0# +";
	if (ft_strchr(list, c))
		return (1);
	else
		return (0);
}
