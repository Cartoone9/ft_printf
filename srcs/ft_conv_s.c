/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:50:42 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_s(char **strr, int index, t_flags **flags, char *str)
{
	char	*str_cpy;
	int		tofree;

	if (!strr)
		return (-1);
	tofree = 0;
	if (!str)
	{
		str = ft_nullstr();
		tofree = 1;
	}
	*flags = ft_s_flags(strr, index);
	if (!*flags)
		return (-1);
	if ((*flags)->dot == 1 && (*flags)->preci == 0)
		str_cpy = ft_s_empty();
	else
		str_cpy = ft_strdup(str);
	if (tofree == 1)
		free(str);
	if (!str_cpy)
		return (-1);
	str = strr[index];
	strr[index] = str_cpy;
	return (free(str), 0);
}

char	*ft_s_empty(void)
{
	char	*ret;

	ret = malloc(1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

t_flags	*ft_s_flags(char **strr, int index)
{
	t_flags	*flags;
	char	*dot;
	size_t	i;

	i = 0;
	flags = ft_flags_init();
	if (!flags)
		return (NULL);
	while (ft_isflag(strr[index][++i]))
	{
		if (strr[index][i] == '-')
			flags->left = 1;
	}
	while (strr[index][i] >= '0' && strr[index][i] <= '9')
		ft_width_fill(&flags, strr[index][i++]);
	dot = ft_strrchr(strr[index], '.');
	if (dot)
	{
		i = 1;
		flags->dot = 1;
		flags->preci = 0;
		while (dot[i] >= '0' && dot[i] <= '9')
			ft_preci_fill(&flags, dot[i++]);
	}
	return (flags);
}

char	*ft_nullstr(void)
{
	char	*ret;

	ret = malloc(7);
	ret[0] = '(';
	ret[1] = 'n';
	ret[2] = 'u';
	ret[3] = 'l';
	ret[4] = 'l';
	ret[5] = ')';
	ret[6] = '\0';
	return (ret);
}
