/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:43:47 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer_cs(char *str, t_flags *fl, int chr)
{
	size_t	isnull;
	size_t	fl_width_cs;
	int		sum;

	isnull = 0;
	sum = ft_strlen(str);
	if (!ft_strncmp(str, "(null)", sum))
		isnull = 1;
	if (chr == 1)
		sum = 1;
	else if (isnull == 1 && fl && fl->preci >= 0 && fl->preci < 6)
		sum = 0;
	else if (fl && fl->preci >= 0 && fl->preci < sum)
		sum = fl->preci;
	fl_width_cs = 0;
	if (fl && (fl->width >= sum))
		fl_width_cs = fl->width - sum;
	if (fl_width_cs > 0 && fl->left == 1)
		ft_width_print_l_cs(fl_width_cs, str, sum);
	else if (fl_width_cs > 0)
		ft_width_print_r_cs(fl_width_cs, str, sum);
	else
		write(1, str, sum);
	return (sum + fl_width_cs);
}

void	ft_width_print_l_cs(size_t width, char *str, int sum)
{
	size_t	i;

	i = -1;
	write(1, str, sum);
	while (++i < width)
		write(1, " ", 1);
}

void	ft_width_print_r_cs(size_t width, char *str, int sum)
{
	size_t	i;

	i = -1;
	while (++i < width)
		write(1, " ", 1);
	write(1, str, sum);
}
