/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:53:44 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/17 18:29:57 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	make_width_s(char **print, int width, char side, char zero)
{
	char	*ptr[2];

	ptr[0] = *print;
	width = (ft_strlen(*print) == 0) ? width + 1 : width;
	ptr[1] = fill_wide(zero, side, width, ft_strlen(ptr[0]));
	if (side == '-' && ft_strlen(ptr[1]) > 0)
	{
		if (*ptr[0] == '-' && zero == '0')
		{
			*print = ft_strjoin(ptr[1], ++ptr[0]);
			*print = ft_strjoin("-", *print);
		}
		else
			*print = ft_strjoin(ptr[0], ptr[1]);
	}
	else
	{
		if (*ptr[0] == '-' && zero == '0')
		{
			*print = ft_strjoin(ptr[1], ++ptr[0]);
			*print = ft_strjoin("-", *print);
		}
		else
			*print = ft_strjoin(ptr[1], ptr[0]);
	}
}

void	make_width_c(char **print, int width, char side, char zero)
{
	char	*ptr[2];

	ptr[0] = *print;
	ptr[1] = fill_wide(zero, side, width, ft_strlen(ptr[0]));
	if (side == '-' && ft_strlen(ptr[1]) > 0)
	{
		if (*ptr[0] == '-' && zero == '0')
		{
			ptr[1] = ft_strjoin(ptr[1], ++ptr[0]);
			ptr[1] = ft_strjoin("-", ptr[1]);
		}
		else
			ptr[1] = ft_strjoin(ptr[0], ptr[1]);
	}
	else
	{
		if (*ptr[0] == '-' && zero == '0')
		{
			ptr[1] = ft_strjoin(ptr[0], ++ptr[0]);
			ptr[1] = ft_strjoin("-", ptr[0]);
		}
		else
			ptr[1] = ft_strjoin(ptr[1], ptr[0]);
	}
	*print = ptr[1];
}

void	formatting_s(char **print, int precision, int widht, char *flags)
{
	char	side;
	char	zero;
	char	*buf;
	int		i;

	i = 0;
	buf = *print;
	side = (ft_strchr(flags, '-')) ? '-' : 0;
	zero = (ft_strchr(flags, '0')) ? '0' : 0;
	if (**print == '\0')
		widht--;
	if (precision == 0 && *print[0] == '0')
		*print[0] = 1;
	if (precision != -1)
		*print = ft_strsub(*print, 0, precision);
	if (widht)
		make_width_s(print, widht, side, zero);
	else if (widht && zero && !ft_strcmp(buf, "(null)"))
	{
		buf = ft_strnew(widht);
		while (i++ < widht)
			buf[i] = '0';
		*print = buf;
	}
}

void	formatting_c(char **print, int precision, int widht, char *flags)
{
	char	side;
	char	zero;

	side = 0;
	zero = 0;
	if (**print == '\0')
		widht--;
	if (precision == 0 && *print[0] == '0')
		*print[0] = 1;
	if (ft_strchr(flags, '-'))
		side = '-';
	if (ft_strchr(flags, '0'))
		zero = '0';
	if (precision != -1)
		*print = ft_strsub(*print, 0, precision);
	if (widht && widht > (int)ft_strlen(*print))
		make_width_c(print, widht, side, zero);
}
