/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:17:20 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/10 21:17:24 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dst, t_node **src, char stack)
{
	t_node	*tmp;

	if (lstsize(*src))
	{
		if (stack)
		{
			write(1, "p", 1);
			write(1, &stack, 1);
			write(1, "\n", 1);
		}
		tmp = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = tmp;
	}
}
