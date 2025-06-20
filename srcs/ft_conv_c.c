/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:50:42 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_c(char **strr, int index, t_flags **flags, int c)
{
	unsigned char	uc;
	char			*temp;
	char			*ret;

	if (!strr)
		return (-1);
	*flags = ft_c_flags(strr, index);
	if (!*flags)
		return (-1);
	ret = malloc(2);
	if (!ret)
		return (-1);
	uc = (unsigned char)c;
	ret[0] = uc;
	ret[1] = '\0';
	temp = strr[index];
	strr[index] = ret;
	free(temp);
	return (1);
}

t_flags	*ft_c_flags(char **strr, int index)
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
	}
	while (strr[index][i] >= '0' && strr[index][i] <= '9')
		ft_width_fill(&flags, strr[index][i++]);
	return (flags);
}

/*
char	*ft_c_ret(t_flags *flags, unsigned char uc)
{
	char	*ret;
	size_t	size;
	size_t	i;

	i = -1;
	size = 1 + flags->width;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	if (flags->left == 1)
	{
		ret[++i] = uc;
		while (++i < size)
			ret[i] = ' ';
	}
	else
	{
		if (flags->width > 0)
			while (++i < size - 1)
				ret[i] = ' ';
		ret[i] = uc;
	}
	ret[++i] = '\0';
	return (ret);
}
*/
