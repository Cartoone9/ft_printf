/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:29 by *******           #+#    #+#             */
/*   Updated: 2025/06/19 13:23:31 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_flags_init(void)
{
	t_flags	*ret;

	ret = (t_flags *)malloc(sizeof(t_flags));
	if (!ret)
		return (NULL);
	ret->preci = -1;
	ret->diese = 0;
	ret->width = 0;
	ret->blank = 0;
	ret->zero = 0;
	ret->plus = 0;
	ret->left = 0;
	ret->dot = 0;
	ret->neg = 0;
	ret->chr = 'x';
	return (ret);
}

void	ft_width_fill(t_flags **flags, unsigned char c)
{
	(*flags)->width *= 10;
	(*flags)->width += (c - 48);
}

void	ft_preci_fill(t_flags **flags, unsigned char c)
{
	(*flags)->preci *= 10;
	(*flags)->preci += (c - 48);
}
