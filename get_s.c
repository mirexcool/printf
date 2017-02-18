/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_S.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:27:41 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 14:14:26 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_ss(int c, char *res)
{
	unsigned char	dv[3];
	unsigned char	tr[4];

	if (c < 128)
	{
		res[0] = c;
		res[1] = 0;
		return (ft_strdup((char *)res));
	}
	else if (c > 127 && c < 2048)
	{
		dv[0] = (c >> 6) + 192;
		dv[1] = (c << 2);
		dv[1] = (dv[1] >> 2) + 128;
		dv[2] = 0;
		return (ft_strdup((char *)dv));
	}
	tr[0] = (c >> 12) + 224;
	tr[1] = (c >> 6);
	tr[1] = tr[1] << 2;
	tr[1] = (tr[1] >> 2) + 128;
	tr[2] = (c << 2);
	tr[2] = (tr[2] >> 2) + 128;
	tr[3] = 0;
	return (ft_strdup((char *)tr));
}

char	*get_sss(va_list args, int p, int l, char *res)
{
	int				*c;
	char			*buf;

	c = va_arg(args, int *);
	if (!c)
		return ("(null)");
	if (p >= 0)
		while (l <= p)
		{
			buf = get_ss(*c, ft_strnew(2));
			l = l + ft_strlen(buf);
			if (l > p)
				break ;
			res = ft_strjoin(res, buf);
			c++;
		}
	else
		while (*c)
		{
			buf = get_ss(*c, ft_strnew(2));
			l = l + ft_strlen(buf);
			res = ft_strjoin(res, buf);
			c++;
		}
	return (res);
}
