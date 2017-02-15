/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:59:07 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 13:08:32 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*cast_type(char	c, va_list args, char *lenght, char sharp)
{
	char	*res;

	if (c == 's' || c == 'S')
		res = get_s(args);
	if (c == 'D')
		res = get_D(args, c);
	if (c == 'd' || c == 'i')
		res = get_d(args, lenght);
	if (c == 'c' || c == 'C' || c == '%')
		res = get_c(args, c);
	if (c == 'X' || c == 'x')
		res = get_x(args, lenght, c);
	if (c =='o')
		res = get_o(args, lenght, c, sharp);
	if (c == 'O')
		res = get_O(args, sharp);
	if (c == 'U')
		res = get_U(args, c);
	if (c == 'u')
		res = get_u(args, lenght);
	if (c == 'p')
		res = get_p(args);
	return (res);
}

void	now_cast(t_pf **begin_list, va_list args)
{
    t_pf	*list;
    int		len;
    char	*exe;
    char	sharp;

    exe = "sSpdDiouUXcC";
    list = *begin_list;
    
    while (list)
    {
		sharp = '\0';
        len = ft_strlen(list->str);
        if (list->str[0] != '%' && len && !ft_strchr(exe, list->str[len - 1]))
            len = ft_strlen(list->str);
        else if (len)
		{
			if (ft_strchr(list->flags, '#'))
				sharp = '#';
            list->print = cast_type(list->str[len - 1], args, list->len, sharp);
		}
        else
            list->print = ft_strsub(list->str, 0, 1);
        if (list->str[0] == '%' && list->str[1] == '%')
            list->print = "%";
        list = list->next;
    }
}


void	make_cast(t_pf **begin_list, va_list args)
{
	t_pf	*list;
	char	*exe;
	int		len;

	exe = "sSpdDioOuUxXcC";
	list = *begin_list;
	while (list)
	{
		len = ft_strlen(list->str);
		if (list->str[0] != '%' && len && !ft_strchr(exe, list->str[len - 1]))
			list->print = list->str;
		else if (len)
		{
			list->format = ft_strsub(list->str + 1, 0, len - 2);
			list->type = list->str[len - 1];
		}
		list = list->next;
		len = 0;
	}
	cut_len(begin_list);
	now_cast(begin_list, args);
    formatting(begin_list);
}

