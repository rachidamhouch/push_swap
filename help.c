/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:30:36 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/12 23:30:39 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get(t_node *lst, int *tab, int start, int end)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		if (lst->value >= tab[start] && lst->value <= tab[end])
			return (i);
		lst = lst->next;
	}
	return (0);
}

int	get_index2(t_node *lst, int nb)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		if (lst->value == nb)
			return (i);
		lst = lst->next;
	}
	return (0);
}

int	get_index3(int *tab, int nb)
{
	int	i;

	i = 0;
	while (1)
	{
		if (tab[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

void	help(t_node **a, t_node **b, int middle, int *tab)
{
	if ((*a)->value < tab[middle])
	{
		push(b, a, 'b');
		shiftup(b, 'b');
	}
	else
		push(b, a, 'b');
}

int	isorted(t_node *lst)
{
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
