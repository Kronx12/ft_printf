/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_functions.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 22:09:57 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 07:15:30 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *nptr)
{
	int		i;
	int		nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = 1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - '0';
		i++;
	}
	if (sign == 1)
		return (-nb);
	return (nb);
}

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char*)s + i);
		}
		i++;
	}
	if (s[i] == c)
		return ((char*)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_ulitoa_base(unsigned long long val, char *base)
{
	char				*str;
	int					res_len;
	unsigned int		base_len;
	unsigned long long	copy;

	base_len = ft_strlen(base);
	copy = val;
	res_len = 0;
	while (++res_len && copy >= base_len)
		copy /= base_len;
	if (!(str = malloc(res_len + 2)))
		return (NULL);
	str[res_len] = '\0';
	while (val >= base_len && --res_len)
	{
		str[res_len] = base[val % base_len];
		val /= base_len;
	}
	str[--res_len] = base[val];
	return (str);
}
