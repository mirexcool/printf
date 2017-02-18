/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:51:44 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 15:44:10 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_pf		*add_list(void)
{
	t_pf	*list;

	list = (t_pf *)malloc(sizeof(t_pf));
	list->format = "";
	list->str = "";
	list->type = 0;
	list->print = "";
	list->flags = "";
	list->p = -1;
	list->w = 0;
	list->len = "";
	list->next = NULL;
	return (list);
}

char		*get_text(char **ptr, int i)
{
	char	*res;
	char	*pt;
	char	*exe;
	char	*ex;

	exe = "sSpdDioOuUxXcCb%";
	ex = "sSpdDioOuUxXcCb+-0 #hlLjzt.%123456789";
	i = 0;
	pt = *ptr;
	while (!ft_strchr(exe, *pt) && *pt != '\0' && ft_strchr(ex, *pt))
	{
		pt++;
		i++;
	}
	pt = pt - i;
	res = ft_strsub(pt, 0, i + 1);
	pt++;
	res = ft_strjoin("%", res);
	return (res);
}

char		*get_str(char **format)
{
	int		i;
	char	*res;
	char	*ptr;

	ptr = *format;
	i = 0;
	if (*ptr != '%' && *ptr != '\0')
	{
		while (*ptr != '%' && *ptr != '\0')
		{
			ptr++;
			i++;
		}
		ptr = ptr - i;
		res = ft_strsub(ptr, 0, i);
		return (res);
	}
	else
	{
		ptr++;
		return (get_text(&ptr, 0));
	}
}

void		make_format(char *format, t_pf **begin_list)
{
	char	*str;
	t_pf	*list;

	list = *begin_list;
	while (*format)
	{
		str = get_str(&format);
		list->str = ft_strdup(str);
		list->next = add_list();
		list = list->next;
		if (ft_strlen(str))
			format += ft_strlen(str);
		else if (str[0] == '%' || *format == '%')
			format++;
	}
}

int			ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;
	static t_pf	*list;
	t_pf		*begin_list;
	char		*res;

	len = 0;
	res = "";
	if (!format)
		return (-1);
	va_start(args, format);
	if (!list)
		list = add_list();
	begin_list = list;
	make_format((char *)format, &begin_list);
	make_cast(&begin_list, args, "sSpdDioOuUxXcCib%", 0);
	while (list)
	{
		final_print(list, &len);
		list = list->next;
	}
	return (len);
}
