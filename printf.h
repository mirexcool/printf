/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:38:20 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/15 13:01:20 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include "libft/libft.h"

int				ft_printf(const char * format, ...);

typedef struct		 s_pf
{
	char			*format;

	char			*str;

	char			*flags;
	
	char			*len;

	int				widht;

	int				precision;

	char			type;

	char			*print;

	struct	s_pf	*next;
}					t_pf;

t_pf		*add_list(void);
int		check_cont(char *str);
char	*separate_str(char	**str);
void	b_zero_end(char	**str, int n);
void	fix_list(t_pf 	**begin_list, char *fr);
void    separate_list(t_pf **begin_list);
void	make_cast(t_pf **begin_list, va_list args);
void	get_lenght(t_pf **begin_list, va_list args);
void	cut_len(t_pf **begin_list);
void	get_lenght(t_pf **begin_list, va_list args);
char	*get_len(char *ptr, char *len);
void	now_cast(t_pf **begin_list, va_list args);
char	*get_this_flags(char *str);
char	*cast_type (char c, va_list args, char *lenght, char sharp);
char	*get_len(char *ptr, char *len);
char	*get_s(va_list args);
char	*get_d(va_list args, char *lenght);
char	*get_D(va_list args, char c);
char	*get_u(va_list args, char *lenght);
char	*get_U(va_list args, char c);
char	*get_c(va_list args, char c);
char	*get_x(va_list args, char *lenght, char c);
char	*get_o(va_list args, char *lenght, char c, char sharp);
char	*get_O(va_list args, char sharp);
char	*get_p(va_list args);
char	*ft_itoa_long(long long value, int base, char mod);
char	*ft_itoa_unsigned(unsigned long long value, int base, char mod);


void	formatting(t_pf **begin_list);
void	format_precision(char **print, int precision, int i, int j);
void	make_width(char **print, int width, char side, char zero);
void	formatting_xo(char **print, int precision, int widht, char *flags);
void    put_sharp_xX(char **print, char type, char minus, int widht);
void	formatting_c(char **print, int precision, int widht, char *flags);
void	formatting_s(char **print, int precision, int widht, char *flags);

int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_strchr(const char *dst, int c);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
unsigned int		ft_strlen(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcat(char *dst, const char *src);
void				ft_bzero(void *data, size_t n);



#endif
