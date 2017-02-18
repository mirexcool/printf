/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:45:47 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 14:45:27 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*cast_type(char c, va_list args, char *lenght, char sharp)
{
	char	*res;

	if (c == 's' && lenght[0] != 'l')
		res = get_s(args, c, 0);
	if (c == 'D')
		res = get_dd(args, lenght);
	if (c == 'd' || c == 'i')
		res = get_d(args, lenght);
	if (c == 'c' || c == 'C')
		res = (lenght[0] == 'l') ? get_c(args, 0, 'C') : get_c(args, 0, c);
	if (c == 'X' || c == 'x')
		res = get_x(args, lenght, c);
	if (c == 'o')
		res = get_o(args, lenght, sharp);
	if (c == 'O')
		res = get_oo(args, sharp);
	if (c == 'U')
		res = get_uu(args, c);
	if (c == 'u')
		res = get_u(args, lenght);
	if (c == 'p')
		res = get_p(args);
	if (c == 'b')
		res = get_b(args, lenght);
	return (res);
}

void	now_cast(t_pf **begin_list, va_list args)
{
	t_pf	*list;
	int		len;
	char	*exe;
	char	sharp;

	exe = "sSpdDioOuUXcC";
	list = *begin_list;
	while (list)
	{
		len = ft_strlen(list->str);
		if (list->str[0] != '%' && len)
			len = ft_strlen(list->str);
		else if (len)
		{
			if (ft_strchr(list->flags, '#'))
				sharp = '#';
			if (list->type != 'Z')
				list->print = cast_type(list->type, args, list->len, sharp);
			if (list->type == 'S' || (list->type == 's' && list->len[0] == 'l'))
				list->print = get_s(args, 'S', list->p);
		}
		if (list->type == '%' && list->str[ft_strlen(list->str) - 1] == '%')
			list->print = "%";
		list = list->next;
	}
}

void	dell_o(char **str, int i)
{
	char	*res;
	char	*n;

	n = "123456789";
	res = *str;
	while (res[i])
	{
		if (ft_strchr(n, res[i]))
			return ;
		i++;
	}
	i = 0;
	while (res[i])
	{
		if (res[i] == '0')
		{
			res[i] = ' ';
			break ;
		}
		i++;
	}
	*str = res;
}

void	fix_list(t_pf **begin_list, t_pf *list)
{
	list = *begin_list;
	while (list)
	{
		if ((list->type == 'o' || list->type == 'O')
			&& ft_strlen(list->print) < 2)
		{
			if (list->p == 0 && list->w < 2 && ft_strchr(list->flags, '#'))
				list->print = "0";
			else if (list->p == 0)
				list->print = "\0";
		}
		else if ((list->type == 'o' || list->type == 'O')
				&& ft_strlen(list->print) > 2 && list->p == 0)
			dell_o(&list->print, 0);
		if (list->type == 'p')
		{
			if (list->p == 0)
				list->print = "0x";
			else
				formatting_p(&list->print, list->p, list->w, list->flags);
		}
		list = list->next;
	}
	fix_sz(begin_list);
}

void	make_cast(t_pf **begin_list, va_list args, char *exe, int len)
{
	t_pf	*list;

	list = *begin_list;
	while (list)
	{
		len = ft_strlen(list->str);
		if (list->str[0] != '%' && len)
			list->print = list->str;
		else if (len && list->str[0] == '%')
		{
			list->format = ft_strsub(list->str + 1, 0, len - 2);
			if (len > 1)
				list->type = list->str[len - 1];
			if (!ft_strchr(exe, list->type) && list->type)
			{
				list->type = 'Z';
				list->print = ft_strsub(list->str, ft_strlen(list->str) - 1, 1);
			}
		}
		list = list->next;
	}
	cut_len(begin_list);
	now_cast(begin_list, args);
	formatting(begin_list, NULL, 0, 0);
	fix_list(begin_list, NULL);
}
