/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutting_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:56:57 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 12:15:19 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_cont(char *str)
{
	char	*exe;
	char	*ptr;

	exe = "sSpdDioOuUxXcC\0";
	while (*exe)
	{
		if ((ptr = ft_strchr(str, *exe)))
		{
			if (str[ft_strlen(str)] != '%')
				return (1);
		}
		exe++;
	}
	return (0);
}

void	b_zero_end(char **str, int n)
{
	int		len;
	int		i;
	char	*ptr;

	i = 0;
	ptr = *str;
	len = ft_strlen(*str);
	while (i < n)
	{
		*(*str + len - i - 1) = '\0';
		i++;
	}
}

char	*separate_str(char **str)
{
	char	*res;
	char	*exe;
	char	*ptr;
	int		i;

	i = 0;
	ptr = *str;
	exe = "sSpdDioOuUxXcC\0";
	while (ptr[i])
	{
		if (ft_strchr(exe, ptr[i]))
		{
			i++;
			if (ft_strlen(ptr + i) > 0)
			{
				res = ft_strsub(ptr + i, 0, ft_strlen(ptr + i));
				b_zero_end(str, ft_strlen(ptr + i));
				return (res);
			}
			break ;
		}
		i++;
	}
	return (NULL);
}

void	fix_list(t_pf **begin_list, char *fr)
{
	t_pf	*list;
	t_pf	*ptr;
    fr = NULL;
	list = *begin_list;
	while (list)
	{
		if (ft_strlen(list->str) == 0 && list->next)
		{
			list = list->next;
			fr = list->str;
			list->str = ft_strjoin("%", list->str);
			free(fr);
		}
		if (list)
			list = list->next;
	}
	list = *begin_list;
	ptr = list;
	while (list)
	{
		if (ft_strlen(list->str) == 0 && list->next)
			ptr->next = list->next;
		ptr = list;
		list = list->next;
	}
}

void	separate_list(t_pf **begin_list)
{
	t_pf	*list;
	char	*str;
	t_pf	*ptr;

	list = *begin_list;
	while (list)
	{
		if (list->str[0] == '%' && check_cont(list->str) == 1)
		{
			str = separate_str(&list->str);
			if (str)
			{
				ptr = list->next;
				list->next = add_list();
				list = list->next;
				list->str = str;
				list->next = ptr;
			}
		}
		list = list->next;
	}
}
