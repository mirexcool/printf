/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:50:41 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 14:51:11 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_bzero(void *data, size_t n)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = (unsigned char *)data;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
}

char	*wide_char(int c)
{
	unsigned char	tr[4];

	tr[0] = (c >> 12) + 224;
	tr[1] = (c >> 6) << 2;
	tr[1] = (tr[1] >> 2) + 128;
	tr[2] = (c << 2);
	tr[2] = (tr[2] >> 2) + 128;
	tr[3] = 0;
	return (ft_strdup((char *)tr));
}
