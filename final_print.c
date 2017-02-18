/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:10:14 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 15:12:24 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	final_print(t_pf *list, int *len)
{
	if (list->type || ft_strlen(list->print))
	{
		if (ft_strlen(list->print) == 0
			&& (list->type == 'c' || list->type == 'C' || list->type == 'Z'))
		{
			write(1, list->print, 1);
			*len = *len + 1;
		}
		else
		{
			if (list->w > (int)ft_strlen(list->print))
			{
				write(1, list->print, list->w);
				*len = *len + list->w;
			}
			else
			{
				*len = *len + ft_strlen(list->print);
				write(1, list->print, ft_strlen(list->print));
			}
		}
	}
}
