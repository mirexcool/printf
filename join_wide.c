/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_wide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:25:24 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 15:37:43 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*fill_wide(char z, char s, int w, int len)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(len - w + 100);
	while (i < w - len)
	{
		if (z == '0' && s != '-')
			*res++ = '0';
		else
			*res++ = ' ';
		i++;
	}
	res = res - i;
	return (res);
}

char	*get_b(va_list args, char *c)
{
	char		*res;
	long long	nb;

	if (c[0] == 'j')
		nb = (long long)va_arg(args, intmax_t);
	else if (c[0] == 'z')
		nb = (long long)va_arg(args, size_t);
	else if (c[0] == 't')
		nb = (long long)va_arg(args, ptrdiff_t);
	else
		nb = va_arg(args, long long);
	res = ft_itoa_long(nb, 2, '\0', 0);
	return (res);
}

void	fix_sz(t_pf **begin_list)
{
	t_pf *list;

	list = *begin_list;
	while (list)
	{
		if (list->type == 's' && list->p == 0)
			list->print = ft_strsub(list->print, 0, list->w);
		if (list->type == 'Z' && list->p == 0 && list->w < 1)
			list->print = "%";
		if (list->str[0] == '%' && list->str[1] == '\0')
			list->print = "\0";
		list = list->next;
	}
}

char	*format_res(char *type, int *i, char *ptr)
{
	char	*res;

	res = ft_strnew(3);
	res[0] = '0';
	res[1] = (*type == 'o' || *type == 'O') ? '\0' : *type;
	*type = (*type == 'p') ? 'x' : *type;
	while (ptr[*i] == ' ')
		(*i)++;
	return (res);
}

char	*make_xx(char *type, int *mv, char *ptr, int i)
{
	char	*res;

	res = format_res(&type[0], &i, ptr);
	if (i == 0 && (type[0] == 'x' || type[0] == 'X'))
	{
		if (mv[0] == 45 && mv[1] + 2 > (int)ft_strlen(ptr) && type[1] != 'p')
		{
			ptr = ft_strjoin(res, ptr);
			ptr[ft_strlen(ptr) - 2] = '\0';
		}
		else
			ptr = ft_strjoin(res, ptr);
	}
	else
	{
		if (type[0] == 'o' || type[0] == 'O')
			ptr[i - 1] = '0';
		else
		{
			ptr[i - 2] = '0';
			ptr[i - 1] = type[0];
		}
	}
	return (ptr);
}
