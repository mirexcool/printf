/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_formatting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:55:29 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 13:57:40 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_sharp_xx(char **print, char type, char minus, int widht)
{
	char	*ptr;
	char	*res;
	char	type3[2];
	int		mv[2];

	mv[0] = minus;
	mv[1] = widht;
	type3[0] = type;
	type3[1] = type;
	ptr = *print;
	if (type == 'o' || type == 'O')
		return ;
	if (type == 'p')
		type = 'x';
	res = ft_strnew(3);
	res[0] = '0';
	res[1] = type == 'o' || type == 'O' ? '\0' : type;
	if (type)
		*print = make_xx(type3, mv, ptr, 0);
}

void	formatting_xo(char **print, int precision, int widht, char *f)
{
	char	side;
	char	zero;
	char	space;

	if (precision == 0 && *print[0] == '0' && !ft_strchr(f, 'o'))
		*print[0] = '\0';
	if (ft_strchr(f, '-'))
		side = '-';
	if (ft_strchr(f, '#') && ft_strchr(f, '0') && !ft_strchr(f, '-'))
		if (widht > (int)ft_strlen(*print) + 2)
			widht = widht - 2;
	if (ft_strchr(f, '0'))
		zero = '0';
	if (ft_strchr(f, ' '))
		space = ' ';
	if (precision > 0 && precision > (int)ft_strlen(*print))
		format_precision(print, precision, 0, 0);
	if (widht && widht > (int)ft_strlen(*print))
	{
		if (precision >= 0)
			zero = '\0';
		make_width(print, widht, side, zero);
	}
}

void	format_precision_p(char **print, int pre, int i, int j)
{
	char	*res;
	char	*ptr;

	j = 0;
	ptr = *print;
	res = ft_strnew(pre + 1);
	res[0] = '0';
	res[1] = 'x';
	ptr = ptr + 2;
	while (i < pre - (int)ft_strlen(ptr))
	{
		res[i + 2] = '0';
		i++;
	}
	i++;
	while (*ptr)
	{
		i++;
		res[i] = *ptr;
		ptr++;
	}
	*print = res;
}

void	make_width_p(char **print, int width, char side, char zero)
{
	char	*ptr[4];

	ptr[0] = *print;
	width = **print == 1 ? width + 1 : width;
	ptr[1] = fill_wide(zero, side, width, (int)ft_strlen(ptr[0]));
	ptr[2] = ptr[1];
	if (side == '-')
		*print = (*ptr[0] == '-' && zero == '0') ? ft_strjoin(ptr[0], ptr[1]) :
		ft_strjoin(ptr[0], ptr[1]);
	else
	{
		if (*ptr[0] == '-' && zero == '0')
		{
			ptr[1] = ft_strjoin(ptr[1], ++ptr[0]);
			ptr[1] = ft_strjoin("-", ptr[1]);
		}
		else
			ptr[1] = ft_strjoin(ptr[0], ptr[1]);
		*print = ptr[1];
	}
	ptr[2] ? free(ptr[2]) : 0;
}

void	formatting_p(char **print, int precision, int widht, char *f)
{
	char	side;
	char	zero;
	char	space;

	if (precision == 0 && *print[0] == '0')
		*print[0] = '\0';
	if (ft_strchr(f, '-'))
		side = '-';
	if (ft_strchr(f, '#') && ft_strchr(f, '0') && !ft_strchr(f, '-'))
		if (widht > (int)ft_strlen(*print) + 2)
			widht = widht - 2;
	if (ft_strchr(f, '0'))
		zero = '0';
	space = (ft_strchr(f, ' ')) ? ' ' : 0;
	if (precision > 0 && precision > (int)ft_strlen(*print))
		format_precision_p(print, precision, 0, 0);
	if (widht && widht > (int)ft_strlen(*print))
	{
		if (precision >= 0)
			zero = '\0';
		if (zero == '0' && widht > 0)
			make_width_p(print, widht, side, zero);
		else
			make_width(print, widht, side, zero);
	}
}
