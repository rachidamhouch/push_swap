/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:25:09 by ramhouch          #+#    #+#             */
/*   Updated: 2022/11/10 19:25:11 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **a, t_node **b, int nb)
{
	if (nb)
		write(1, "ss\n", 3);
	swap(a, 0);
	swap(b, 0);
}
