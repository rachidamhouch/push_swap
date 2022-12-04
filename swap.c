/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:41:49 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/10 18:41:50 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **list, char stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (lstsize(*list) >= 2)
	{
		if (stack)
		{
			write(1, "s", 1);
			write(1, &stack, 1);
			write(1, "\n", 1);
		}
		tmp1 = *list;
		tmp2 = (*list)->next->next;
		*list = (*list)->next;
		(*list)->next = tmp1;
		tmp1->next = tmp2;
	}
}
