/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:43:01 by *******           #+#    #+#             */
/*   Updated: 2025/06/20 21:09:27 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer_di(char *str, t_flags *fl)
{
	int	ret;
	int	str_len;

	ret = 0;
	str_len = ft_strlen(str);
	if (fl->width > 0 || fl->preci >= 0 || fl->plus > 0 || fl->neg > 0
		|| fl->blank > 0)
		ret += ft_full_print_di(fl, str);
	else
		ret += write(1, str, str_len);
	return (ret);
}

int	ft_full_print_di(t_flags *fl, char *str)
{
	int	upperhand;
	int	str_len;
	int	ret;

	ret = 0;
	if (fl->neg == 2)
		str++;
	str_len = ft_strlen(str);
	upperhand = ft_upperhand(str_len, fl->preci);
	if (fl->left == 1)
		ret += ft_full_print_di_left(fl, str, upperhand, str_len);
	else
		ret += ft_full_print_di_right(fl, str, upperhand, str_len);
	return (ret);
}

int	ft_full_print_di_left(t_flags *fl, char *str, int upperhand, int str_len)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (fl->plus == 1 || fl->neg == 2)
		ret += write(1, &"+-"[(fl->plus + fl->neg) / 2], 1);
	else if (fl->blank == 1)
		ret += write(1, " ", 1);
	while (++i < fl->preci - str_len)
		ret += write(1, "0", 1);
	if (str[0] != '0' || str_len != 1 || fl->preci != 0)
		ret += write(1, str, str_len);
	else if (fl->width > 0)
		ret += write(1, " ", 1);
	i = -1;
	while (++i < fl->width - fl->plus - (fl->neg / 2) - fl->blank - upperhand)
		ret += write(1, " ", 1);
	return (ret);
}

int	ft_full_print_di_right(t_flags *fl, char *str, int upperhand, int str_len)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if (fl->zero == 1)
	{
		if (fl->plus == 1 || fl->neg == 2)
			ret += write(1, &"+-"[(fl->plus + fl->neg) / 2], 1);
		else if (fl->blank == 1)
			ret += write(1, " ", 1);
		while (++i < fl->width - fl->plus - (fl->neg / 2) - fl->blank
			- upperhand)
			ret += write(1, "0", 1);
	}
	else
	{
		while (++i < fl->width - fl->plus - (fl->neg / 2) - fl->blank
			- upperhand)
			ret += write(1, " ", 1);
	}
	ret += ft_full_print_di_right_suite(fl, str, str_len);
	return (ret);
}

int	ft_full_print_di_right_suite(t_flags *fl, char *str, int str_len)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	if ((fl->plus == 1 || fl->neg == 2) && fl->zero == 0)
		ret += write(1, &"+-"[(fl->plus + fl->neg) / 2], 1);
	else if (fl->blank == 1 && fl->zero == 0)
		ret += write(1, " ", 1);
	while (++i < fl->preci - str_len)
		ret += write(1, "0", 1);
	if (str[0] != '0' || str_len != 1 || fl->preci != 0)
		ret += write(1, str, str_len);
	else if (fl->width > 0)
		ret += write(1, " ", 1);
	return (ret);
}
