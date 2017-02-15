/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_printf.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: yyefimov <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/01/26 12:40:23 by yyefimov		   #+#	  #+#			  */
/*	 Updated: 2017/02/02 14:15:18 by yyefimov		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include <stdio.h>


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
	list->precision = -1;
	list->widht = 0;
	list->len = "";
    list->next = NULL;
    return (list);
}

char	*dell_unpr(char *str)
{
	char *res;
	int		i;

	i = 0;
	res = malloc(ft_strlen(str) + 1);
	while (*str)
	{
		if ((*str > 31 && *str < 127) || *str == '\n' || *str == '\t')
		{
			res[i] = *str;
			i++;
		}
		str++;
	}
	return (res);
}

char	*get_str(char **format)
{
	int		i;
	char	*res;
	char	*ptr;
	char	*exe = "sSpdDiouUxXcC%";

	ptr = *format;
	i = 0;
	if (*ptr != '%' && *ptr != '\0')
	{
		while (*ptr != '%' && *ptr)
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
		while(!ft_strchr(exe, *ptr) && *ptr)
		{
			ptr++;
			i++;
		}
			ptr = ptr - i;
			res = ft_strsub(ptr, 0, i + 1);
			ptr++;
			res = ft_strjoin("%", res);
	}
	return (res);
}

void	make_format(char *format, t_pf **begin_list)
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

int		ft_printf(const char *format, ...)
{
	int len;
	va_list args;
   	static  t_pf *list;
    t_pf *begin_list;
	char *res;

	len = 0;
	res = "";
	if (!format)
		return (-1);
	va_start(args, format);
    if(!list)
        list = add_list();
    begin_list = list;
	make_format((char *)format, &begin_list);
	make_cast(&begin_list, args);
    while (list)
    {
		if (list->type || ft_strlen(list->print))
		{
			list->print = dell_unpr(list->print);
			res = ft_strjoin(res, list->print);
			if (ft_strlen(list->print) == 0 && list->type == 'c')
				len = len + 1;
			else
			{
				if (list->widht > (int)ft_strlen(list->print))
					len = len + list->widht;
				else
					len = len + ft_strlen(list->print);
			}
		}
        list = list->next;
    }
	write(1, res, len);
		return (len);
}
