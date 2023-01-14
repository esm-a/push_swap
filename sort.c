/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:24:29 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 17:26:39 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*build_temp(t_stack *a);
static int		is_in_lis(t_lis *lis, int n);
static void		longest_inc_sub(t_stack **a, t_stack **b, t_lis *lis);

void	sort(t_stack **a, t_stack **b)
{
	t_lis	*lis;
	t_stack	*temp;
	int		size;

	size = ft_lstsize(*a);
	temp = build_temp(*a);
	put_smallest_on_top(&temp);
	lis = find_lis(transfer_to_array(temp), size);
	ft_free(temp);
	if (lis == NULL)
	{
		ft_free(*a);
		exit(0);
	}
	longest_inc_sub(a, b, lis);
	while (*b)
	{
		set_index_b(b, a);
		push_to_a(a, b, best_element(*b));
	}
	put_smallest_on_top_a(a);
}

static void	longest_inc_sub(t_stack **a, t_stack **b, t_lis *lis)
{
	t_stack	*s;
	int		size;
	int		n;

	size = ft_lstsize(*a);
	s = *a;
	while (s && size-- > 0)
	{
		n = s->n;
		s = s->next;
		if (is_in_lis(lis, n) == 0)
		{
			pb(b, a);
			if ((*b)->n < (lis->arr)[lis->len / 2])
				rb(b);
		}
		else
			ra(a);
	}
	free(lis->arr);
	free(lis);
}

static t_stack	*build_temp(t_stack *a)
{
	t_stack	*temp;

	temp = NULL;
	while (a)
	{
		ft_lstadd_back(&temp, ft_lstnew(a->n));
		a = a->next;
	}
	return (temp);
}

int	*transfer_to_array(t_stack *s)
{
	int	*arr;
	int	i;

	arr = malloc(ft_lstsize(s) * sizeof(int));
	if (arr == NULL)
	{
		ft_free(s);
		exit(1);
	}
	i = 0;
	while (s)
	{
		arr[i] = s->n;
		s = s->next;
		i++;
	}
	return (arr);
}

static int	is_in_lis(t_lis *lis, int n)
{
	int	i;

	i = 0;
	while (i < lis->len)
	{
		if ((lis->arr)[i] == n)
			return (1);
		i++;
	}
	return (0);
}
