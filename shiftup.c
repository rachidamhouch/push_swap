/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:55:55 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/10 21:55:57 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shiftup(t_node **lst, char stack)
{
	t_node	*tmp;

	if (lstsize(*lst) >= 2)
	{
		if (stack)
		{
			write(1, "r", 1);
			write(1, &stack, 1);
			write(1, "\n", 1);
		}
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = NULL;
		lstadd_back(lst, tmp);
	}
}
