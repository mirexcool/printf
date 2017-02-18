/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:42:51 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 15:46:52 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#define ULLONG_MAX 18446744073709551615
#define USHRT_MAX 65535
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
int	main(void)
{

	write(1, "MAN  = --->", 11);
	printf("| %d |", printf("%llhhd", 5000));
	printf("<---\n");
	write(1, "MY   = --->", 11);
	ft_printf("| %d |", ft_printf("%d", 5000));
	printf("<---\n");
}
