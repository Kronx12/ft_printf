/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: guillaume <guillaume@student.le-101.fr>    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/20 04:22:21 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 07:12:26 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			min;
	char		flag;
	int			width;
	int			precision;
	char		type;
	char		*result;
}				t_flags;
typedef struct	s_str
{
	char		*str;
	int			len;
}				t_str;
int				ft_atoi(const char *nptr);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ftib(long long val2, char *base);
char			*ft_ulitoa_base(unsigned long long val, char *base);
char			*ft_charfjoin(char *s1, char c, int f);
t_str			*ft_structfjoin(t_str *s1, t_str *s2, int f);
t_str			*ft_strndup(t_str *str, int n, int f);
void			ft_putnstr(char *str, int len);
void			ft_replace(char *str, char c, char d);
t_str			*create_str(char *s, int l);
t_str			*create__str(char *s);
void			free_str(t_str *s);
t_flags			*init_flags(void);
void			fill_struct(const char *str, int *i, va_list *lst, t_flags *f);
void			fill_min(const char *str, int *i, va_list *lst, t_flags *f);
void			fill_flags(const char *str, int *i, t_flags *f);
void			fill_width(const char *str, int *i, va_list *lst, t_flags *f);
void			fill_precision(const char *str, int *i,
					va_list *lst, t_flags *f);
void			fill_type(const char *str, int *i, va_list *lst, t_flags *f);
void			flags_on_value(t_str **str, t_flags *f);
int				ft_printf(const char *str, ...) __attribute__
					((format(printf,1,2)));

#endif
