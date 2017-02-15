/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_spdio.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:28:49 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/11 17:31:05 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


char	*get_s(va_list args)
{
	char	*res;

	res = va_arg(args, char*);
	if (res == NULL)
		res = "(null)";
	return (res);
}

char	*get_D(va_list args, char c)
{
	char		*res;
	long long	nb;

	if (c == 'j')
		nb = (long long)va_arg(args, intmax_t);
	else if (c == 'z')
		nb = (long long)va_arg(args, size_t);
	else if (c == 't')
		nb = (long long)va_arg(args, ptrdiff_t);
	else
		nb = va_arg(args, long long);
	res = ft_itoa_long(nb, 10, '\0');
	return (res);
}

char	*get_d(va_list args, char *lenght)
{
	char		*res;
	long long	nb;

	if (lenght[0] == 'l')	
		if (lenght[1] == 'l')
		{
			nb = va_arg(args, long long);
		}
		else
			nb = va_arg(args, long);
	else if (lenght[0] == 'h')	
		if (lenght[1] == 'h')
			nb = (signed char)va_arg(args, signed int);
		else
			nb = (short int)va_arg(args, int);
	else if (lenght[0] == 'j')
		nb = (long long)va_arg(args, intmax_t);
	else if (lenght[0] == 'z')
		nb = (long long)va_arg(args, size_t);
	else if (lenght[0] == 't')
		nb = (long long)va_arg(args, ptrdiff_t);
	else
		nb = (long long)va_arg(args, int);
    res = ft_itoa_long(nb, 10, '\0');
	return (res);
}

char	*get_O(va_list args, char sharp)
{
	char		*res;
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	res = ft_itoa_unsigned(nb, 8, '\0');
	if (sharp == '#')
		res = ft_strjoin("0", res);
	return (res);
}

char	*get_o(va_list args, char *lenght, char c, char sharp)
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
	else if (c == 'j')
		nb = (unsigned long long)va_arg(args, intmax_t);
	else if (c == 'z')
		nb = (unsigned long long)va_arg(args, size_t);
	else if (c == 't')
		nb = (unsigned long long)va_arg(args, ptrdiff_t);
	else
		nb = va_arg(args, unsigned int);
    res = ft_itoa_unsigned(nb, 8, '\0');
	if (sharp == '#')
		res = ft_strjoin("0", res);
	return (res);
}
