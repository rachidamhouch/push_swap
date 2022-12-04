/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:44:58 by ramhouch          #+#    #+#             */
/*   Updated: 2022/10/24 17:06:03 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	is_num(const char t)
{
	if (t >= '0' && t <= '9')
		return (1);
	return (0);
}

static int	ft_check(int m, const char *str, int sign)
{
	if (m >= 19)
	{
		if (ft_strncmp("9223372036854775807", str, 19) < 0
			&& sign == 1)
			return (-1);
		if (ft_strncmp("9223372036854775808", str, 19) < 0
			&& sign == -1)
			return (0);
	}
	return (1);
}

static void	skip_and_inicialise(int *i, int *sign, const char *str)
{
	*sign = 1;
	*i = 0;
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' '))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		(*i)++;
		*sign = -1;
	}
	while (str[*i] == '0')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	s;
	int					sign;
	int					m;
	int					start;

	m = 0;
	s = 0;
	skip_and_inicialise(&i, &sign, str);
	start = i;
	while (str[i] && is_num(str[i]))
	{
		s = s * 10 + str[i++] - '0';
		m++;
		if (ft_check(m, str + start, sign) != 1)
			return ((ft_check(m, str + start, sign)));
	}
	return (sign * s);
}
