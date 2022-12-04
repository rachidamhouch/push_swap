/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:44:35 by ramhouch          #+#    #+#             */
/*   Updated: 2022/12/03 08:28:21 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	right_fun(t_node **a, t_node **b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		swap(a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		swap(b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(str, "pa\n"))
		push(a, b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		push(b, a, 0);
	else if (!ft_strcmp(str, "ra\n"))
		shiftup(a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		shiftup(b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		shiftdown(a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		shiftdown(b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

static int	help2(t_node **a, t_node **b, char *str)
{
	while (str)
	{
		if (right_fun(a, b, str))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		free(str);
		str = get_next_line(0);
	}
	if (isorted(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freetab(*a);
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*str;
	char	**ptr;

	if (ac == 2)
		ptr = ft_split(av[1], ' ');
	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		helper2(ac, ptr, av);
		helper(ac, ptr, &a, av);
		str = get_next_line(0);
		if (help2(&a, &b, str))
		{
			freetab(a);
			return (1);
		}
	}
	return (0);
}
