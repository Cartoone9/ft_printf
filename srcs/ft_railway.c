/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_railway.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:17:01 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_railway(char **strr, int index, t_flags **flags, va_list args)
{
	unsigned char	last_c;

	last_c = strr[index][(ft_strlen(strr[index]) - 1)];
	if (last_c == 'c')
		return (ft_conv_c(strr, index, flags, va_arg(args, int)));
	if (last_c == 's')
		return (ft_conv_s(strr, index, flags, va_arg(args, char *)));
	if (last_c == 'p')
		return (ft_conv_p(strr, index, flags, va_arg(args, void *)));
	if (last_c == 'i' || last_c == 'd')
		return (ft_conv_i(strr, index, flags, va_arg(args, int)));
	if (last_c == 'u')
		return (ft_conv_u(strr, index, flags, va_arg(args, unsigned int)));
	if (last_c == 'x' || last_c == 'X')
		return (ft_conv_x(strr, index, flags, va_arg(args, unsigned int)));
	if (last_c == '%')
		return (ft_conv_prct(strr, index));
	return (-1);
}
