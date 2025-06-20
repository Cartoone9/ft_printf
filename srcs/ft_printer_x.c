/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:43:01 by *******           #+#    #+#             */
/*   Updated: 2025/06/20 21:09:43 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer_x(char *str, t_flags *fl)
{
	int	ret;
	int	str_len;

	ret = 0;
	str_len = ft_strlen(str);
	if (fl->width > 0 || fl->preci >= 0 || fl->plus > 0 || fl->neg > 0
		|| fl->blank > 0 || fl->diese > 0)
		ret += ft_full_print_x(fl, str);
	else
		ret += write(1, str, str_len);
	return (ret);
}

int	ft_full_print_x(t_flags *fl, char *str)
{
	char	*prefix;
	int		upperhand;
	int		str_len;
	int		ret;

	ret = 0;
	str_len = ft_strlen(str);
	upperhand = ft_upperhand(str_len, fl->preci);
	prefix = ft_prefix(fl->chr);
	if (fl->left == 1)
		ret += ft_full_print_x_left(fl, str, upperhand, prefix);
	else
		ret += ft_full_print_x_right(fl, str, upperhand, prefix);
	return (ret);
}

int	ft_full_print_x_left(t_flags *fl, char *str, int upperhand, char *prefix)
{
	int	str_len;
	int	ret;
	int	i;

	i = -1;
	ret = 0;
	str_len = ft_strlen(str);
	if (fl->diese == 1 && (str[0] != '0' || str_len != 1))
		ret += write(1, prefix, 2);
	while (++i < fl->preci - str_len)
		ret += write(1, "0", 1);
	if (str[0] != '0' || str_len != 1 || fl->preci != 0)
		ret += write(1, str, str_len);
	else if (fl->width > 0)
		ret += write(1, " ", 1);
	i = -1;
	while (++i < fl->width - upperhand - (fl->diese * 2))
		ret += write(1, " ", 1);
	return (ret);
}

int	ft_full_print_x_right(t_flags *fl, char *str, int upperhand, char *prefix)
{
	int	str_len;
	int	ret;
	int	i;

	i = -1;
	ret = 0;
	str_len = ft_strlen(str);
	if (fl->zero == 1)
	{
		if (fl->diese == 1 && (str[0] != '0' || str_len != 1))
			ret += write(1, prefix, 2);
		while (++i < fl->width - upperhand - (fl->diese * 2))
			ret += write(1, "0", 1);
	}
	else
		while (++i < fl->width - upperhand - (fl->diese * 2))
			ret += write(1, " ", 1);
	ret += ft_full_print_x_right_suite(fl, str, prefix, str_len);
	return (ret);
}

int	ft_full_print_x_right_suite(t_flags *fl, char *str, char *prefix,
		int str_len)
{
	int	ret;
	int	i;

	i = -1;
	ret = 0;
	if (fl->diese == 1 && fl->zero == 0 && (str[0] != '0' || str_len != 1))
		ret += write(1, prefix, 2);
	while (++i < fl->preci - str_len)
		ret += write(1, "0", 1);
	if (str[0] != '0' || str_len != 1 || fl->preci != 0)
		ret += write(1, str, str_len);
	else if (fl->width > 0)
		ret += write(1, " ", 1);
	return (ret);
}
