/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:59:52 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/10 22:59:54 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_node **a, t_node **b, int nb)
{
	if (nb)
		write(1, "rrr\n", 4);
	shiftdown(a, 0);
	shiftdown(b, 0);
}