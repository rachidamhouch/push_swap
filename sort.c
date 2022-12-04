/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:57:29 by ramhouch          #+#    #+#             */
/*   Updated: 2022/12/03 08:54:12 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*cpytotabe(t_node *lst, int *i)
{
	int	n;
	int	*tab;

	n = lstsize(lst);
	tab = malloc(n * 4);
	while (lst)
	{
		tab[*i] = lst->value;
		lst = lst->next;
		*i = *i + 1;
	}
	return (tab);
}

static void	sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	min;
	int	index;

	i = 0;
	while (i < size)
	{
		index = i;
		min = i;
		while (index < size)
		{
			if (tab[index] < tab[min])
				min = index;
			index++;
		}
		tmp = tab[i];
		tab[i] = tab[min];
		tab[min] = tmp;
		i++;
	}
}

static void	first_sort(t_node **a, t_node **b, int *tab, int size)
{
	int	start;
	int	end;
	int	middle;
	int	offset;

	middle = size / 2;
	offset = 1 + (size / 8) * (size < 150) + (size / 19) * (size >= 150);
	start = middle - offset;
	end = middle + offset;
	while (lstsize(*a))
	{
		if ((*a)->value >= tab[start] && (*a)->value <= tab[end])
			help(a, b, middle, tab);
		else if (!get(*a, tab, start, end))
		{
			start = ((start - offset) >= 0)
				* (start - offset);
			end = ((end + offset) < size)
				* (end + offset) + ((end + offset) >= size) * (size - 1);
		}
		else if (get(*a, tab, start, end) < lstsize(*a) / 2)
			shiftup(a, 'a');
		else if (lstsize(*a) && get(*a, tab, start, end) >= lstsize(*a) / 2)
			shiftdown(a, 'a');
	}
}

static void	last_sort(t_node **b, t_node **a, int *nb, int i)
{
	static int	index;

	if (!get_index2(*b, nb[i]))
	{
		shiftdown(a, 'a');
		index = 0;
	}
	while (get_index2(*b, nb[i]))
	{
		if ((*b)->value == nb[i])
			push(a, b, 'a');
		else if (!index || (*b)->value == nb[index + 1])
		{
			index = get_index3(nb, (*b)->value);
			push(a, b, 'a');
			shiftup(a, 'a');
		}
		else if ((*b)->next->value == nb[i])
			swap(b, 'b');
		else if (get_index2(*b, nb[i]) < (lstsize(*b) / 2))
			shiftup(b, 'b');
		else if (get_index2(*b, nb[i]) >= (lstsize(*b) / 2))
			shiftdown(b, 'b');
	}
}

void	sort(t_node **a, t_node **b)
{
	int	i;
	int	*tab;

	i = 0;
	tab = cpytotabe(*a, &i);
	sort_tab(tab, i);
	first_sort(a, b, tab, i);
	while (i)
	{
		i--;
		last_sort(b, a, tab, i);
	}
	free(tab);
}
