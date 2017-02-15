/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:02:53 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 13:16:48 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	make_width_s(char **print, int width, char side, char zero)
{
    char	*ptr;
    char	*res;
    int		i;
    
    i = 0;
    ptr = *print;
    res = (char *)malloc(sizeof(char) * (ft_strlen(ptr) - width) + 1);
	if (ft_strlen(*print) == 0)
		width++;
    while (i < width - (int)ft_strlen(ptr))
    {
        if (zero == '0')
            *res++ = '0';
        else
            *res++ = ' ';
        i++;
    }
    res = res - i;
    if (side == '-' && ft_strlen(res) > 0)
    {
        if (*ptr == '-' && zero == '0')
        {
            res = ft_strjoin(res, ++ptr);
            res = ft_strjoin("-", res);
        }
        else
            res = ft_strjoin(ptr, res);
        *print = res;
    }
    else
    {
        if (*ptr == '-' && zero == '0')
        {
            res = ft_strjoin(res, ++ptr);
            res = ft_strjoin("-", res);
        }
        else
            res = ft_strjoin(res, ptr);
        *print = res;
    }
}

void	make_width_c(char **print, int width, char side, char zero)
{
    char	*ptr;
    char	*res;
    int		i;
    
    i = 0;
    ptr = *print;
    res = (char *)malloc(sizeof(char) * (ft_strlen(ptr) - width) + 1);
    while (i < width - (int)ft_strlen(ptr))
    {
        if (zero == '0')
            *res++ = '0';
        else
            *res++ = ' ';
        i++;
    }
    res = res - i;
    if (side == '-' && ft_strlen(res) > 0)
    {
        if (*ptr == '-' && zero == '0')
        {
            res = ft_strjoin(res, ++ptr);
            res = ft_strjoin("-", res);
        }
        else
            res = ft_strjoin(ptr, res);
        *print = res;
    }
    else
    {
        if (*ptr == '-' && zero == '0')
        {
            res = ft_strjoin(res, ++ptr);
            res = ft_strjoin("-", res);
        }
        else
            res = ft_strjoin(res, ptr);
        *print = res;
    }
}

void	formatting_s(char **print, int precision, int widht, char *flags)
{
    char	side;
    char	zero;
  
	side = 0;
	zero = 0;   
	if (**print == '\0')
		widht--;
    if (precision == 0 && *print[0] == '0')
        *print[0] = 1;
    if(ft_strchr(flags, '-'))
        side = '-';
    if(ft_strchr(flags, '0'))
        zero = '0';
    if (precision != -1)
		*print = ft_strsub(*print, 0, precision);
   if (widht && widht > (int)ft_strlen(*print))
        make_width_s(print, widht, side, zero);
}

void	formatting_c(char **print, int precision, int widht, char *flags)
{
    char	side;
    char	zero;
  
	side = 0;
	zero = 0;   
	if (**print == '\0')
		widht--;
    if (precision == 0 && *print[0] == '0')
        *print[0] = 1;
    if(ft_strchr(flags, '-'))
        side = '-';
    if(ft_strchr(flags, '0'))
        zero = '0';
    if (precision != -1)
		*print = ft_strsub(*print, 0, precision);
   if (widht && widht > (int)ft_strlen(*print))
        make_width_c(print, widht, side, zero);
}
