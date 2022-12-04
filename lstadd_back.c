/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:31:48 by ramhouch          #+#    #+#             */
/*   Updated: 2022/12/03 08:56:29 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(t_node **lst, t_node *new)
{
	t_node	*ptr;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ptr = last_node(*lst);
		ptr->next = new;
	}
}

void	freetab(t_node *lst)
{
	t_node	*ptr;

	while (lst)
	{
		ptr = lst->next;
		free(lst);
		lst = ptr;
	}
}

void	helper(int ac, char **ptr, t_node **a, char **av)
{
	int	i;

	i = 1;
	if (ac == 2)
	{
		i = 0;
		while (ptr[i])
			lstadd_back(a, new_node(ft_atoi(ptr[i++])));
	}
	else
	{
		while (i < ac)
			lstadd_back(a, new_node(ft_atoi(av[i++])));
	}
}

void	helper2(int ac, char **ptr, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (ptr[i])
			i++;
		if (error(ptr, i))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else
	{
		if (error(av + 1, ac - 1))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}
