/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftdown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:44:48 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/10 22:44:50 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	shiftdown(t_node **lst, char stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (lstsize(*lst) >= 2)
	{
		if (stack)
		{
			write(1, "rr", 2);
			write(1, &stack, 1);
			write(1, "\n", 1);
		}
		tmp1 = lstlast(*lst);
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		lstadd_front(lst, tmp2);
	}
}
