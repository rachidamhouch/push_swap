/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:55:02 by ramhouch          #+#    #+#             */
/*   Updated: 2022/12/03 08:33:48 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	good_fun(t_node **a, t_node **b)
{
	int	n;

	n = lstsize(*a);
	if (n == 2)
		swap(a, 'a');
	else if (n == 3)
		sort3(a);
	else if (n == 4)
		sort4(a, b);
	else if (n == 5)
		sort5(a, b);
	else if (n > 5)
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**ptr;

	if (ac == 2)
		ptr = ft_split(av[1], ' ');
	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		helper2(ac, ptr, av);
		helper(ac, ptr, &a, av);
		if (isorted(a))
		{
			freetab(a);
			return (1);
		}
		good_fun(&a, &b);
		freetab(a);
		(void)good_fun;
	}
	return (0);
}
