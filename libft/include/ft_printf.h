/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:49:32 by mmatamou          #+#    #+#             */
/*   Updated: 2016/12/12 16:03:31 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct			s_flag
{
	int					hsh;
	int					zr;
	int					min;
	int					sp;
	int					plu;
	int					apos;
	int					sum;
}						t_flag;

typedef struct			s_mod
{
	int					h;
	int					l;
	int					ll;
	int					j;
	int					z;
	int					sum;
}						t_mod;

typedef struct			s_gen
{
	t_flag				*flg;
	int					minwid;
	int					preci;
	t_mod				*md;
	char				conv;
	int					size;
	int					digs;
	intmax_t			d;
	uintmax_t			dx;
	uintmax_t			du;
	char				*nw;
	int					tud;
	int					neg;
	int					exp;
	int					i;
	int					nwsize;
	int					y;
	int					erro;
	int					p;
}						t_gen;

typedef struct			s_type
{
	int					i;
	intmax_t			mintmax_t;
	uintmax_t			muintmax_t;
	double				mdouble;
	long double			mlongdouble;
	char				*mpchar;
	short				*mpshort;
	int					*mpint;
	long				*mplong;
	long long			*mplonglong;
	intmax_t			*mpintmax_t;
	wchar_t				mwchar_t;
	wchar_t				*mpwchar_t;
	void				*mvoid;
}						t_ype;

int						ft_printf(const char *format, ...);
int						specs(wchar_t *str, int i, t_gen **a);
int						isflag(wchar_t c);
int						isalg(wchar_t c);
int						ismod(wchar_t c);
int						isconv(wchar_t c);
int						inpchang(wchar_t **str, wchar_t *nw, int i, t_gen *a);
char					*ft_itoa_base(long value, int base, int cap);
int						is_char(t_gen *a);
int						is_short(t_gen *a);
int						is_int(t_gen *a);
int						is_long(t_gen *a);
int						is_longlong(t_gen *a);
int						is_intmax_t(t_gen *a);
int						is_unchar(t_gen *a);
int						is_unshort(t_gen *a);
int						is_unint(t_gen *a);
int						is_unlong(t_gen *a);
int						is_unlonglong(t_gen *a);
int						is_uintmax_t(t_gen *a);
int						is_size_t(t_gen *a);
int						is_double(t_gen *a);
int						is_longdouble(t_gen *a);
int						is_pchar(t_gen *a);
int						is_wchar_t(t_gen *a);
int						is_pwchar_t(t_gen *a);
int						is_void(t_gen *a);
void					di_creat(t_gen **a, char **str, intmax_t n);
int						di_number(char **str, t_gen **a, intmax_t n, int j);
char					*di(intmax_t n, t_gen *a);
char					*oo(uintmax_t n, t_gen *a);
int						xx_number(char **str, t_gen **a, uintmax_t n, int j);
char					*xx_fill4(char *str, t_gen *a, uintmax_t n);
char					*xx(uintmax_t n, t_gen *a);
char					*uu(uintmax_t n, t_gen *a);
void					ff_round(uintmax_t *inteiro, uintmax_t *decimal,
		uintmax_t m);
uintmax_t				ff_creator(uintmax_t inteiro, t_gen **a, char **str);
int						ff_sign(char **str, t_gen *a, int i);
int						ff_putnbrs(uintmax_t nbr, int size, char **str, int i);
char					*ff(double n, t_gen *a);
int						ee_mv_dec_point(double *n);
void					ee_round(uintmax_t *inteiro, uintmax_t *decimal,
		uintmax_t m);
void					ee_to_uint(double n, t_gen *a, uintmax_t *ine,
		uintmax_t *dec);
void					ee_creator(t_gen *a, char **str);
int						ee_sign(char **str, t_gen *a, int i);
char					*ee(double n, t_gen *a);
wchar_t					*cc(char c, t_gen **a);
wchar_t					*lc(wchar_t c, t_gen **a);
char					*ss(char *s, t_gen *a);
wchar_t					*ls(wchar_t *s, t_gen *a);
int						nn(va_list va, wchar_t **str, t_gen *a, int i);
char					*pp(void *p, t_gen *a);
wchar_t					*perc(t_gen *a);
int						count_bytes_s(wchar_t *str, int len);
int						count_bytes(wchar_t c);
int						p_converter(wchar_t **str, t_gen **a, va_list va, int y);
wchar_t					*allconvs(t_ype *tmp, t_gen **a);
wchar_t					*char_to_w(char *s1);
wchar_t					*charconst_to_w(const char *s1);
wchar_t					*minwierr(t_gen **a, wchar_t *str, int i);
void					initall(t_gen **a);
int						isflag(wchar_t c);
int						isalg(wchar_t c);
int						ismod(wchar_t c);
int						isconv(wchar_t c);
void					putflg(t_gen **a, wchar_t c);
void					putmod(t_gen **a, wchar_t c);

#endif
