/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:50:42 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_conv_p(char **strr, int index, t_flags **flags, void *ptr)
{
	char				*temp;
	char				*ret;
	unsigned long long	addr;

	if (!strr)
		return (-1);
	if (!ptr)
		return (ft_voidptr(strr, index, flags), 2);
	*flags = ft_p_flags(strr, index);
	if (!*flags)
		return (-1);
	addr = (unsigned long long)ptr;
	ret = ft_tohexa(addr, flags);
	if (!ret)
		return (-1);
	temp = strr[index];
	strr[index] = ret;
	free(temp);
	return (3);
}

t_flags	*ft_p_flags(char **strr, int index)
{
	t_flags	*flags;
	size_t	i;

	i = 0;
	flags = ft_flags_init();
	if (!flags)
		return (NULL);
	flags->chr = 'p';
	while (ft_isflag(strr[index][++i]))
	{
		if (strr[index][i] == '-')
			flags->left = 1;
		if (strr[index][i] == '0')
			flags->zero = 1;
	}
	while (strr[index][i] >= '0' && strr[index][i] <= '9')
		ft_width_fill(&flags, strr[index][i++]);
	ft_u_remove_conflict(&flags);
	return (flags);
}

void	ft_p_remove_conflict(t_flags **flags)
{
	if ((*flags)->left == 1)
		(*flags)->zero = 0;
}

int	ft_voidptr(char **strr, int index, t_flags **flags)
{
	char	*ret;
	char	*temp;

	ret = malloc(6);
	if (!ret)
		return (-1);
	ret[0] = '(';
	ret[1] = 'n';
	ret[2] = 'i';
	ret[3] = 'l';
	ret[4] = ')';
	ret[5] = '\0';
	*flags = ft_p_flags(strr, index);
	if (!*flags)
		return (-1);
	temp = strr[index];
	strr[index] = ret;
	free(temp);
	return (3);
}
