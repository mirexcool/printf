/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:36:35 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/10 16:30:22 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	check_for_zero(char *str)
{
	while (*str)
	{
		if (*str > '0' && *str <='9')
			while (*str >= '0' && *str <='9')
				str++;
		if (*str == '0')
		{
            return ('0');
			while (*str == '0')
				str++;
			if (*str < '0' || *str > '9')
				return ('0');
		}
		str++;

	}
	return('\0');
}

char	*get_this_flags(char *str)
{
	char	*res;
	int		i;

	i = 0;	
	res = ft_strnew(5);
	if (ft_strchr(str, '+'))
		res[i++] = '+';
	if (ft_strchr(str, '-'))
		res[i++] = '-';
	if (ft_strchr(str, ' '))
		res[i++] = ' ';
	if (ft_strchr(str, '#'))
		res[i++] = '#';
	res[i++] = check_for_zero(str);
	return (res);	
	
}
