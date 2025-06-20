/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:50:42 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_i(char **strr, int index, t_flags **flags, int n)
{
	char	*temp;
	char	*ret;

	if (!strr)
		return (-1);
	ret = ft_itoa(n);
	if (!ret)
		return (-1);
	*flags = ft_i_flags(strr, index, n);
	if (!*flags)
		return (-1);
	temp = strr[index];
	strr[index] = ret;
	free(temp);
	return (2);
}

t_flags	*ft_i_flags(char **strr, int index, int n)
{
	t_flags	*flags;
	size_t	i;

	i = 0;
	flags = ft_flags_init();
	if (!flags)
		return (NULL);
	while (ft_isflag(strr[index][++i]))
	{
		if (strr[index][i] == '-')
			flags->left = 1;
		if (strr[index][i] == '0')
			flags->zero = 1;
		if (strr[index][i] == '+')
			flags->plus = 1;
		if (strr[index][i] == ' ')
			flags->blank = 1;
	}
	while (strr[index][i] >= '0' && strr[index][i] <= '9')
		ft_width_fill(&flags, strr[index][i++]);
	ft_dot(strr, index, &flags);
	return (ft_i_remove_conflict(&flags, n), flags);
}

void	ft_i_remove_conflict(t_flags **flags, int n)
{
	if ((*flags)->preci >= 0 || (*flags)->left == 1)
		(*flags)->zero = 0;
	if ((*flags)->plus == 1 || n < 0)
		(*flags)->blank = 0;
	if (n < 0)
	{
		(*flags)->plus = 0;
		(*flags)->neg = 2;
	}
}
