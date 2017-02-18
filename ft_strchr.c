/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:05 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 15:00:38 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *dst, int c)
{
	if (c == '\0')
	{
		while (*dst)
			dst++;
		return ((char *)dst);
	}
	while (*dst != '\0')
	{
		if (*dst == c)
			return ((char *)dst);
		dst++;
	}
	return (0);
}
