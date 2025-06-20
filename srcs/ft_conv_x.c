/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:50:42 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_x(char **strr, int index, t_flags **flags, unsigned int n_u)
{
	char	*temp;
	char	*ret;

	if (!strr)
		return (-1);
	*flags = ft_x_flags(strr, index, n_u);
	if (!*flags)
		return (-1);
	temp = ft_tohexa(n_u, flags);
	if (!temp)
		return (-1);
	if (ft_strlen(temp) > 8)
	{
		ret = ft_substr(temp, (ft_strlen(temp) - 8), 100);
		free(temp);
	}
	else
		ret = temp;
	temp = strr[index];
	strr[index] = ret;
	free(temp);
	return (3);
}

t_flags	*ft_x_flags(char **strr, int index, unsigned int n_u)
{
	t_flags	*flags;
	size_t	i;

	i = 0;
	flags = ft_flags_init();
	if (!flags)
		return (NULL);
	if (strr[index][ft_strlen(strr[index]) - 1] == 'X')
		flags->chr = 'X';
	while (ft_isflag(strr[index][++i]))
	{
		if (strr[index][i] == '-')
			flags->left = 1;
		if (strr[index][i] == '0')
			flags->zero = 1;
		if (strr[index][i] == '#' && n_u != 0)
			flags->diese = 1;
	}
	while (strr[index][i] >= '0' && strr[index][i] <= '9')
		ft_width_fill(&flags, strr[index][i++]);
	ft_dot(strr, index, &flags);
	return (ft_u_remove_conflict(&flags), flags);
}

void	ft_x_remove_conflict(t_flags **flags)
{
	if ((*flags)->left == 1)
		(*flags)->zero = 0;
}
