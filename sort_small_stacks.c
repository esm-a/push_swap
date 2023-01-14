/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:44:39 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 10:44:40 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack **a)
{
	if (a_is_sorted(*a))
		return ;
	if (ft_lstsize(*a) == 2)
	{
		sa(*a);
		return ;
	}
	if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
	{
		if ((*a)->next->n < (*a)->next->next->n)
			rra(a);
		else
			sa(*a);
		sort_three_a(a);
	}
	if ((*a)->n > (*a)->next->n && (*a)->n < (*a)->next->next->n)
		sa(*a);
	if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n)
		rra(a);
	if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
	{
		rra(a);
		sort_three_a(a);
	}
}

int	handle(t_stack **b, t_stack **a)
{
	if ((*b)->n < (*a)->n)
		pa(a, b);
	else if ((*b)->n > ft_lstlast(*a)->n)
	{
		pa(a, b);
		return (1);
	}
	else if ((*b)->n > (*a)->n && (*b)->n < (*a)->next->n)
	{
		pa(a, b);
		sa(*a);
	}
	else if ((*b)->n > (*a)->next->n && (*b)->n < ft_lstlast(*a)->n)
	{
		rra(a);
		pa(a, b);
		return (2);
	}
	return (0);
}

void	push_min(t_stack **a)
{
	t_stack	*s;
	int		size;
	int		smallest;
	int		counter;

	smallest = get_smallest(*a);
	size = ft_lstsize(*a);
	counter = 0;
	s = *a;
	while (s)
	{
		if (s->n == smallest)
			break ;
		s = s->next;
		++counter;
	}
	if (counter == 0)
		return ;
	if (counter <= ft_lstsize(*a) / 2)
		rs_machine(a, counter, ra);
	else
		rrs_machine(a, size - counter, rra);
}

void	sort_five(t_stack **a, t_stack **b)
{
	push_min(a);
	pb(b, a);
	push_min(a);
	pb(b, a);
	sort_three_a(a);
	pa(a, b);
	pa(a, b);
}
