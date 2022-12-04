/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:54:47 by ramhouch          #+#    #+#             */
/*   Updated: 2022/12/03 08:56:22 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}t_node;

t_node	*new_node(int value);
void	lstadd_front(t_node **lst, t_node *new);
void	lstadd_back(t_node **lst, t_node *new);
t_node	*last_node(t_node *lst);
int		ft_atoi(const char *str);
int		lstsize(t_node *lst);
void	swap(t_node **list, char stack);
void	ss(t_node **a, t_node **b, int nb);
void	push(t_node **dst, t_node **src, char stack);
void	shiftup(t_node **lst, char stack);
void	rr(t_node **a, t_node **b, int nb);
void	shiftdown(t_node **lst, char stack);
void	rrr(t_node **a, t_node **b, int nb);
int		error(char **ptr, int n);
void	sort3(t_node **lst);
void	sort4(t_node **a, t_node **b);
void	sort5(t_node **a, t_node **b);
void	sort(t_node **a, t_node **b);
int		get(t_node *lst, int *tab, int start, int end);
int		get_index2(t_node *lst, int nb);
int		get_index3(int *tab, int nb);
void	help(t_node **a, t_node **b, int middle, int *tab);
char	*get_next_line(int fd);
size_t	my_strlen(const char *s);
char	*my_strjoin(char *s1, char *s2);
char	*my_strchr(const char *s, int c);
void	*my_memcpy(void *dst, const void *src, size_t n);
int		isorted(t_node *lst);
void	freetab(t_node *lst);
char	**ft_split(char const *s, char c);
void	helper2(int ac, char **ptr, char **av);
void	helper(int ac, char **ptr, t_node **a, char **av);

#endif