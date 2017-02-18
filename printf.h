/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:38:20 by yyefimov          #+#    #+#             */
/*   Updated: 2017/02/18 15:24:12 by yyefimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);

typedef struct	s_pf
{
	char		*format;
	char		*str;
	char		*flags;
	char		*len;
	int			w;
	int			p;
	char		type;
	char		*print;
	struct s_pf	*next;
}				t_pf;

t_pf			*add_list(void);
void			make_cast(t_pf **begin_list, va_list argsm, char *exe, int len);
void			get_lenght(t_pf **begin_list, va_list args);
void			cut_len(t_pf **begin_list);
void			get_lenght(t_pf **begin_list, va_list args);
char			*get_len(char *ptr, char *len);
void			now_cast(t_pf **begin_list, va_list args);
char			*get_this_flags(char *str);
char			*cast_type (char c, va_list args, char *lenght, char sharp);
char			*get_len(char *ptr, char *len);
char			*get_s(va_list args, char c, int p);
char			*get_sss(va_list args, int p, int l, char *res);
char			*get_d(va_list args, char *lenght);
char			*get_dd(va_list args, char *c);
char			*get_u(va_list args, char *lenght);
char			*get_uu(va_list args, char c);
char			*get_c(va_list args, int c, char ch);
char			*get_x(va_list args, char *lenght, char c);
char			*get_o(va_list args, char *lenght, char sharp);
char			*get_oo(va_list args, char sharp);
char			*get_b(va_list args, char *c);
char			*get_p(va_list args);
char			*ft_itoa_long(long long value, int base, char mod, int i);
char			*ft_itoa_unsigned(unsigned long long value, int base, char mod);
char			*wide_char(int c);
void			formatting(t_pf **begin_list, t_pf *list, char sh, char minus);
void			format_precision(char **print, int precision, int i, int j);
void			make_width(char **print, int width, char side, char zero);
void			formatting_xo(char **print, int pre, int widht, char *flags);
void			formatting_p(char **print, int pre, int widht, char *flags);
void			make_width(char **print, int width, char side, char zero);
void			put_sharp_xx(char **print, char type, char minus, int widht);
void			formatting_c(char **print, int pre, int widht, char *flags);
void			formatting_s(char **print, int pre, int widht, char *flags);
char			*fill_wide(char z, char s, int w, int len);
void			fix_sz(t_pf **begin_list);
char			*make_xx(char *type, int *mv, char *ptr, int i);
void			final_print(t_pf *list, int *len);
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *dst, int c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
unsigned int	ft_strlen(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcat(char *dst, const char *src);
void			ft_bzero(void *data, size_t n);
int				ft_strcmp(const char *s1, const char *s2);

#endif
