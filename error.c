/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:57:07 by ramhouch          #+#    #+#             */
/*   Updated: 2022/12/03 08:55:57 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	is_dup(char **ptr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (!ft_strcmp(ptr[i], ptr[j]) && i != j)
				return (1);
			if (ft_atoi(ptr[i]) == ft_atoi(ptr[j]) && i != j)
				return (1);
				j++;
		}
		i++;
	}
	return (0);
}

static int	is_num(char **ptr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (ptr[i][j] && ((ptr[i][j] >= 9 && ptr[i][j] <= 13) ||
			ptr[i][j] == ' '))
			j++;
		if (ptr[i][j] == '-')
			j++;
		else if (ptr[i][j] == '+')
			j++;
		while (ptr[i][j])
		{
			if (ptr[i][j] > '9' || ptr[i][j] < '0')
				return (0);
			j++;
		}
		if ((ptr[i][0] == '-' || ptr[i][0] == '+') && j == 1)
			return (0);
		i++;
	}
	return (1);
}

static int	maxmin(char **ptr, int n)
{
	int			i;
	int			j;
	long long	nb;
	int			sign;

	i = 0;
	while (i < n)
	{
		sign = 1;
		nb = 0;
		j = 0;
		while (ptr[i][j] && ((ptr[i][j] >= 9 && ptr[i][j] <= 13) ||
			ptr[i][j] == ' '))
			j++;
		if (ptr[i][j] == '-' || ptr[i][j] == '+')
			sign = -1 * (ptr[i][j] == '-') + 1 * (ptr[i][j] == '+');
		j += (ptr[i][j] == '-' || ptr[i][j] == '+');
		while (ptr[i][j])
			nb = nb * 10 + ptr[i][j++] - '0';
		nb *= sign;
		if (nb > INT_MAX || nb < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	error(char **ptr, int n)
{
	if (is_dup(ptr, n))
		return (1);
	if (!is_num(ptr, n))
		return (1);
	if (maxmin(ptr, n))
		return (1);
	return (0);
}
