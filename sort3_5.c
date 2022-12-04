/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:01:14 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/11 17:01:16 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_index(t_node *lst)
{
	int	min;
	int	index;
	int	i;

	min = lst->value;
	index = 1;
	i = 0;
	while (lst)
	{
		i++;
		if (lst->value < min)
		{
			min = lst->value;
			index = i;
		}
		lst = lst->next;
	}
	return (index);
}

void	sort3(t_node **lst)
{
	if ((*lst)->value < (*lst)->next->value
		&& (*lst)->value < (*lst)->next->next->value
		&& (*lst)->next->value < (*lst)->next->next->value)
		return ;
	if ((*lst)->value < (*lst)->next->value
		&& (*lst)->value < (*lst)->next->next->value)
	{
		shiftdown(lst, 'a');
		swap(lst, 'a');
	}
	else if ((*lst)->value > (*lst)->next->value
		&& (*lst)->value > (*lst)->next->next->value)
	{
		shiftup(lst, 'a');
		if ((*lst)->value > (*lst)->next->value)
			swap(lst, 'a');
	}
	else if ((*lst)->value > (*lst)->next->value)
		swap(lst, 'a');
	else if ((*lst)->value > (*lst)->next->next->value)
		shiftdown(lst, 'a');
}

void	sort4(t_node **a, t_node **b)
{
	int	min;

	min = get_min_index(*a);
	if (min == 2)
		swap(a, 'a');
	else if (min == 3)
	{
		shiftup(a, 'a');
		shiftup(a, 'a');
	}
	else if (min == 4)
		shiftdown(a, 'a');
	push(b, a, 'b');
	sort3(a);
	push(a, b, 'a');
}

void	sort5(t_node **a, t_node **b)
{
	int	min;

	(void)b;
	min = get_min_index(*a);
	if (min == 2)
		swap(a, 'a');
	else if (min == 3)
	{
		shiftup(a, 'a');
		shiftup(a, 'a');
	}
	else if (min == 4)
	{
		shiftup(a, 'a');
		shiftup(a, 'a');
		shiftup(a, 'a');
	}
	else if (min == 5)
		shiftdown(a, 'a');
	push(b, a, 'b');
	sort4(a, b);
	push(a, b, 'a');
}
