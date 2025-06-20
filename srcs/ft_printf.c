/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:40:44 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	char	**strr;
	t_flags	*flags;
	va_list	args;
	size_t	i;
	int		sum;

	if (!str)
		return (-1);
	flags = NULL;
	strr = ft_split_prct(str);
	if (!strr)
		return (-1);
	i = 0;
	va_start(args, str);
	sum = ft_printf_suite(strr, args, &flags, &i);
	if (sum == -1)
	{
		if (flags)
		{
			free(flags);
			flags = NULL;
		}
	}
	return (va_end(args), ft_free(strr), sum);
}

int	ft_printf_suite(char **strr, va_list args, t_flags **flags, size_t *i_ptr)
{
	int	sum;
	int	n;

	sum = 0;
	while (strr[*i_ptr])
	{
		n = 0;
		if (strr[*i_ptr][0] == '%')
		{
			n = ft_railway(strr, *i_ptr, flags, args);
			if (n == -1)
				return (-1);
		}
		if (n < 2)
			sum += ft_printer_cs(strr[*i_ptr], *flags, n);
		else if (n == 2)
			sum += ft_printer_di(strr[*i_ptr], *flags);
		else if (n == 3)
			sum += ft_printer_x(strr[*i_ptr], *flags);
		if (*flags)
			ft_free_flags(flags);
		(*i_ptr)++;
	}
	return (sum);
}

void	ft_free_flags(t_flags **flags)
{
	free(*flags);
	*flags = NULL;
}

/*
void	ft_remove_neg(char *str, size_t str_len)
{
	size_t	i;

	i = 0;
	while (i < str_len - 1)
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
}

int	ft_printer(char **strr)
{
	size_t	str_len;
	size_t	sum;
	size_t	i;

	sum = 0;
	i = 0;
	while (strr[i])
	{
		if (strr[i][0] == '\0')
			str_len = 1;
		else
			str_len = ft_strlen(strr[i]);
		write(1, strr[i], str_len);
		sum += str_len;
		i++;
	}
	ft_free(strr, i);
	return (sum);
}
*/
