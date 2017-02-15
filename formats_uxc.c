/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_uxc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:30:16 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 13:02:54 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"


char	*get_c(va_list args, char s)
{
	char	*res;
	char	c;

	if (s == '%')
		return ("%");
	c = va_arg(args, int);
	res = ft_strnew(2);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*get_x(va_list args, char *lenght, char c)
{
	char				*res;
	unsigned long long	nb;

	if (lenght[0] == 'l')
		if (lenght[0] == 'l')
			nb = va_arg(args, unsigned long long);
		else
			nb = va_arg(args, unsigned long);
	else if (lenght[0] == 'h')
		if (lenght[1] == 'h')
			nb = (unsigned char)va_arg(args, unsigned int);
		else
			nb = (unsigned short int)va_arg(args, unsigned int);
    else if (*lenght == 'j')
		nb = (unsigned long long)va_arg(args, intmax_t);
    else if (*lenght == 'z')
         nb = (unsigned long long)va_arg(args, size_t);
    else if (*lenght == 't')
       nb = (unsigned long long)va_arg(args, ptrdiff_t);
    else
		nb = va_arg(args,  unsigned int);
	res = ft_itoa_unsigned(nb, 16, c);
	return (res);
}

char	*get_U(va_list args, char c)
{
    char				*res;
    unsigned long long	nb;
    
    if (c == 'j')
        nb = (unsigned long long)va_arg(args, intmax_t);
    else if (c == 'z')
        nb = (unsigned long long)va_arg(args, size_t);
    else if (c == 't')
        nb = (unsigned long long)va_arg(args, ptrdiff_t);
    else
        nb = va_arg(args, unsigned long long);
    res = ft_itoa_unsigned(nb, 10, '\0');
    return (res);
}

char	*get_u(va_list args, char *lenght)
{
    char				*res;
    unsigned long long	nb;
    
    if (lenght[0] == 'l')
        if (lenght[1] == 'l')
            nb = va_arg(args, unsigned long long);
        else
            nb = va_arg(args, unsigned long);
	else if (lenght[0] == 'h')
		if (lenght[1] == 'h')
        	nb = (unsigned char)va_arg(args, unsigned int);
        else
            nb = (unsigned short int)va_arg(args, unsigned int);
    else if (lenght[0] == 'j')
        nb = (unsigned long long)va_arg(args, intmax_t);
    else if (lenght[0] == 'z')
        nb = (unsigned long long)va_arg(args, size_t);
    else if (lenght[0] == 't')
        nb = (unsigned long long)va_arg(args, ptrdiff_t);
    else
		nb = va_arg(args, unsigned int);
    res = ft_itoa_unsigned(nb, 10, '\0');
    return (res);
}

char	*get_p(va_list args)
{
    char				*res;
    unsigned long long	nb;
    
    nb = (unsigned long long)va_arg(args, void*);
    res = ft_itoa_unsigned(nb, 16, '\0');
    return (res);
}
