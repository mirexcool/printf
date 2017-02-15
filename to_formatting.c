/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_formatting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:02:04 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 13:39:46 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	put_sharp_xX(char **print, char type, char minus, int widht)
{
    char	*ptr;
    int		i;
	char	*res;

    ptr = *print;
	if (type == 'o' || type == 'O')
		return ;
	if (type == 'p' && *ptr == '0' && widht < 2)
	{
		type = 'x';
		*print = "0x";
		return ;
	}
	else if (type == 'p')
		type = 'x';
	i = 0;
	res = ft_strnew(3);
	res[0] = '0';
	res[1] = type == 'o' || type == 'O' ? '\0' : type;
	if (type)
	{
		while ((ptr[i] < '0' || ptr[i] > '9') && ptr[i] != 'a' && ptr[i] != 'b' && ptr[i] != 'c' 
				&& ptr[i] != 'd' && ptr[i] != 'e' && ptr[i] != 'f' && ptr[i] != 'C' 
				&& ptr[i] != 'D' && ptr[i] != 'F' && ptr[i] != 'F' && ptr[i] != 'A' && ptr[i] != 'B')
				i++;
		if (i == 0 && (type == 'x' || type == 'X'))
		{
			if (minus == '-' && widht + 2 > (int)ft_strlen(ptr))
			{
				ptr = ft_strjoin(res, ptr);
				ptr[ft_strlen(ptr) - 2] = '\0';
				*print = ptr;
			}
			else
				*print = ft_strjoin(res, ptr);
		}
		else
		{
			if (type == 'o' || type == 'O')
				ptr[i - 1] = '0';
			else
			{
				ptr[i - 2] = '0';
				ptr[i - 1] = type;
			}
			*print = ptr;
		}
	}
}

void	formatting_xo(char **print, int precision, int widht, char *flags)
{
        char	side;
        char	zero;
        char	space;

        if (precision == 0 && *print[0] == '0')
            *print[0] = 1;
        if(ft_strchr(flags, '-'))
            side = '-';
        if(ft_strchr(flags, '#') && ft_strchr(flags, '0') && !ft_strchr(flags, '-'))
			if (widht > (int)ft_strlen(*print) + 2)
				widht = widht - 2;
        if(ft_strchr(flags, '0'))
            zero = '0';
        if(ft_strchr(flags, ' '))
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
