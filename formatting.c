/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:28:45 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/17 18:58:16 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	format_precision(char **print, int pre, int i, int j)
{
	char	*res;
	char	*ptr;

	ptr = *print;
	res = *print[0] == '-' ? ft_strnew(pre + 2) : ft_strnew(pre + 1);
	if (*print[0] == '-')
		pre++;
	while (i < pre)
	{
		res[i] = '0';
		i++;
	}
	i = 0;
	while (i < pre - (int)ft_strlen(ptr))
		i++;
	if (*ptr == '-')
	{
		ptr++;
		res[0] = '-';
		i++;
	}
	while (ptr[j])
		res[i++] = ptr[j++];
	if (pre > (int)ft_strlen(ptr))
		*print = res;
}

void	make_width(char **print, int width, char side, char zero)
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
			ptr[1] = ft_strjoin(ptr[1], ptr[0]);
		*print = ptr[1];
	}
	ptr[2] ? free(ptr[2]) : 0;
}

void	space_plus(char **print, char plus, char space, char zero)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = *print;
	if (*print[0] == '0' && zero == '0')
		*print[0] = '+';
	else if (plus == '+' && ft_strlen(*print) > 0 && *print[0] != '-'
			&& space != ' ' && (**print < '0' || **print > '9'))
	{
		while (ptr[i] < '0' || ptr[i] > '9')
			i++;
		ptr[i - 1] = '+';
		*print = ptr;
	}
	else if (plus == '+' && ft_strlen(*print) > 0 && *print[0] != '-')
	{
		ptr = ft_strjoin("+", ptr);
		if (ptr[ft_strlen(ptr) - 1] < '0')
			ptr[ft_strlen(ptr) - 1] = '\0';
		*print = ptr;
	}
	if (space == ' ' && ft_strlen(*print) > 0 && *print[0] != '-'
		&& plus != '+')
		*print = ft_strjoin(" ", ptr);
}

void	f_d(char **print, int p, int widht, char *flags)
{
	char	s[4];

	if (p == 0 && *print[0] == '0')
		*print[0] = '\0';
	s[3] = (ft_strchr(flags, '+')) ? '+' : 0;
	s[0] = (ft_strchr(flags, '-')) ? '-' : 0;
	s[1] = (ft_strchr(flags, '0')) ? '0' : 0;
	s[2] = (ft_strchr(flags, ' ')) ? ' ' : 0;
	if (p > 0)
		format_precision(print, p, 0, 0);
	if (widht && widht > (int)ft_strlen(*print))
	{
		s[1] = (p >= 0) ? 0 : s[1];
		make_width(print, widht, s[0], s[1]);
	}
	if (flags[0] == 'u')
		return ;
	else if ((s[3] == '+' || s[2] == ' ') && s[0] != '-' && widht > p && widht)
	{
		space_plus(print, s[3], 0, s[1]);
		if (s[2] == ' ' && s[3] != '+' && *print[0] == '+')
			*print[0] = ' ';
	}
	else if (s[3] == '+' || s[2] == ' ')
		space_plus(print, s[3], s[2], s[1]);
}

void	formatting(t_pf **begin_list, t_pf *list, char sh, char minus)
{
	list = *begin_list;
	while (list)
	{
		sh = ft_strchr(list->flags, '#') && list->print[0] != '0' ? '#' : '\0';
		minus = ft_strchr(list->flags, '-') ? '-' : '\0';
		if ((list->type == 'o' || list->type == 'O') && sh == '#' &&
		list->p + 1 < (int)ft_strlen(list->print) + 1 && list->w <= list->p)
			list->p = ft_strlen(list->print) + 1;
		if (list->type == 'd' || list->type == 'D' || list->type == 'i'
			|| list->type == 'u' || list->type == 'U' || list->type == 'b')
			(list->type == 'u' || list->type == 'U') ?
			f_d(&list->print, list->p, list->w, ft_strjoin("u", list->flags)) :
			f_d(&list->print, list->p, list->w, list->flags);
		if (list->type == 'o' || list->type == 'O'
			|| list->type == 'x' || list->type == 'X')
			formatting_xo(&list->print, list->p, list->w, list->flags);
		if ((sh == '#' && (list->type == 'x' || list->type == 'X')))
			put_sharp_xx(&list->print, list->type, minus, list->w);
		if (list->type == 's' || list->type == 'S')
			formatting_s(&list->print, list->p, list->w, list->flags);
		if (list->type == 'c' || list->type == 'C' || list->type == '%'
			|| list->type == 'Z')
			formatting_c(&list->print, list->p, list->w, list->flags);
		list = list->next;
	}
}
