/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:37:13 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 13:40:38 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*get_len(char *ptr, char *len)
{
    int		i;
    
    i = 0;
    while (ptr[i])
        i++;
    i--;
    while (i >= 0)
    {
        if (ptr[i] == 'h' || ptr[i] == 'l' || ptr[i] == 'j'
            || ptr[i] == 'z' || ptr[i] == 't' || ptr[i] == 't')
        {
            if((i - 1) > - 1 && (ptr[i - 1] == 'l'))
                len[1] = 'l';
            if((i - 1) > - 1 && (ptr[i - 1] == 'h'))
                len[1] = 'h';
        }
        if (ptr[i] == 'h' || ptr[i] == 'l' || ptr[i] == 'j'
            || ptr[i] == 'z' || ptr[i] == 't' || ptr[i] == 't')
            len[0] = ptr[i];
        i--;
        if (len[0])
            break ;
    }
    return (len);
}

int		get_widht(char	*ptr, int widht, int i)
{
	while (*ptr)
		ptr++;
	while(i >= 0)
	{
		if (*ptr >= '0' && *ptr <= '9')
			while (*ptr >= '0' && *ptr <= '9' &&  i > 0)
			{ 
				i--;
				ptr--;
				if (*ptr < '0' || *ptr > '9')
					i++;
			}
		if (*ptr != '.')
			widht = (i == 0) ? ft_atoi(ptr) : ft_atoi(ptr + 1);
		if (widht > 0)
			break ;
		i--;
		ptr--;
	}
	return (widht);
}

int		get_precision(char	*ptr, int prec, int i)
{
	while (*ptr)
		ptr++;
	while(i >= 0)
	{
		if (*ptr >= '0' && *ptr <= '9')
			while (*ptr >= '0' && *ptr <= '9' &&  i > 0)
			{ 
				i--;
				ptr--;
				if (*ptr < '0' || *ptr > '9')
					i++;
			}
		if (*ptr == '.')
				prec = ft_atoi(ptr + 1);
		if (prec > 0)
			break ;
		i--;
		ptr--;
	}
	if (ft_strchr(ptr, '.') && prec == 0)
		return (0);
	return (prec);
}

void	cut_len(t_pf **begin_list)
{
    t_pf *list;
    
    list = *begin_list;
    
    while (list)
    {
        list->len = get_len(list->format, ft_strnew(3));
		list->widht = get_widht(list->format, 0, ft_strlen(list->format));
		if (list->widht == 0 && list->type == 'c')
			list->widht++;
        if (ft_strchr(list->format, '.'))
		{
            list->precision = get_precision(list->format, 0, ft_strlen(list->format));
			if (list->type == 'c' || list->type == '%')
				list->precision = 1;
		}
		list->flags = get_this_flags(list->format);
        list = list->next;
    }
}
