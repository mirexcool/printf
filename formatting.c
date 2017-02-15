/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:58:42 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 13:41:34 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	format_precision(char **print, int precision, int i, int j)
{
	char	*res;
	char	*ptr;

	ptr = *print;
	res = *print[0] == '-' ? (char *)malloc(precision + 2) : (char *)malloc(precision + 1);
	if (*print[0] == '-')
		precision++;
	while (i < precision)
	{
		res[i] = '0';
		i++;
	}
	i = 0;
	while (i < precision - (int)ft_strlen(ptr))
		i++;
	if (*ptr == '-')
	{
		ptr++;
		res[0] = '-';
		i++;
	}
	while (ptr[j])
		res[i++] = ptr[j++];
	if (precision > (int)ft_strlen(ptr))
		*print = res;
}

void	make_width(char **print, int width, char side, char zero)
{
	char	*ptr;
	char	*res;
	int		i;

	i = 0;
	ptr = *print;
	res = (char *)malloc(sizeof(char) * (ft_strlen(ptr) - width) + 1);
	width = **print == 1 ? width + 1: width;
	while (i < width - (int)ft_strlen(ptr))
	{
		if (zero == '0' && side != '-')
			*res++ = '0';
		else
			*res++ = ' ';
		i++;
	}
	res = res - i;
	if (side == '-')
	{
		if (*ptr == '-' && zero == '0')
			res = ft_strjoin(ptr, res);
		else
			res = ft_strjoin(ptr, res);
		*print = res;
	}
	else
	{
		if (*ptr == '-' && zero == '0')
		{
			res = ft_strjoin(res, ++ptr);
			res = ft_strjoin("-", res);
		}
		else
			res = ft_strjoin(res, ptr);
		*print = res;
	}
}

void	space_plus(char	**print, char plus, char space, char zero)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = *print;
	if (*print[0] == '0' && zero == '0')
		*print[0] = '+';
	else if (plus == '+' && ft_strlen (*print) > 0 && *print[0] != '-' && space != ' '
			&& (**print < '0' || **print > '9'))
	{
		while(ptr[i] < '0' || ptr[i] > '9')
			i++;
		ptr[i - 1] = '+';;
		*print = ptr;
	}
	else if (plus == '+' && ft_strlen (*print) > 0 && *print[0] != '-')
	{
		ptr = ft_strjoin("+", ptr);
		if (ptr[ft_strlen(ptr) - 1] < '0')
			ptr[ft_strlen(ptr) - 1] = '\0';
		*print = ptr;
	}
	if (space == ' ' && ft_strlen (*print) > 0 && *print[0] != '-' && plus != '+')
	{
		ptr = ft_strjoin(" ", ptr);
		*print = ptr;
	}
}

void	formatting_digits(char **print, int precision, int widht, char *flags)
{
	char	side;
	char	zero;
	char	space;
	char	plus;
	
	plus = '\0';
	if (precision == 0 && *print[0] == '0')
		*print[0] = 1;
	if(ft_strchr(flags, '-'))
		side = '-';
	if(ft_strchr(flags, '0'))
		zero = '0';
	if(ft_strchr(flags, ' '))
		space = ' ';
	if(ft_strchr(flags, '+'))
		plus = '+';
	if (precision > 0)
		format_precision(print, precision, 0, 0);
	if (widht && widht > (int)ft_strlen(*print))
	{
		if (precision >= 0)
			zero = 0;
		make_width(print, widht, side, zero);
	}
	if (flags[0] == 'u')
		return ;
	else if ((plus == '+' || space == ' ') && side != '-' && widht > precision && widht)
		space_plus(print, plus, 0, zero);
	else if (plus == '+' || space == ' ')
		space_plus(print, plus, space, zero);
	printf("%print = s\n", *print);
}

void	formatting(t_pf **begin_list)
{
	t_pf	*list;
	char	sharp;
	char	minus;

	list = *begin_list;
	while(list)
	{
		sharp = ft_strchr(list->flags, '#') && list->print[0] != '0' ? '#' : '\0';
		minus = ft_strchr(list->flags, '-') ? '-' : '\0';
		if ((list->type == 'o' || list->type == 'O') && sharp == '#'
			&& list->precision + 1 < (int)ft_strlen(list->print) + 1 && list->widht <= list->precision)
			list->precision = ft_strlen(list->print) + 1;
		if (list->type == 'd' || list->type == 'D' || list->type == 'i' 
			|| list->type == 'u' || list->type == 'U')
		{
			if (list->type == 'u' || list->type == 'U')
				formatting_digits(&list->print, list->precision, list->widht, ft_strjoin("u", list->flags));
			else
				formatting_digits(&list->print, list->precision, list->widht, list->flags);
		}
		if (list->type == 'o'|| list->type == 'O' 
			|| list->type == 'x' || list->type == 'X' || list->type == 'p')
			formatting_xo(&list->print, list->precision, list->widht, list->flags);
		if ((sharp == '#' && (list->type == 'x' || list->type =='X' || list->type == 'O'
			|| list->type == 'o')) || (list->type == 'p'))
			put_sharp_xX(&list->print, list->type, minus, list->widht);
		if (list->type == 's' || list->type == 'S')
				formatting_s(&list->print, list->precision, list->widht, list->flags);
		if (list->type == 'c' || list->type == 'C' || list->type == '%')
				formatting_c(&list->print, list->precision, list->widht, list->flags);
		list = list->next;
	}
}
