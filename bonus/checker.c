/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:20:05 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 10:45:07 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	handle_error(t_stack **a, char **av)
{
	char	**sp;
	int		i;

	while (*++av)
	{
		i = -1;
		sp = ft_split(*av, ' ');
		if (sp == NULL)
		{
			ft_free(*a);
			ft_error();
		}
		while (sp[++i])
		{
			if (check_args(sp[i]) == 0)
			{
				ft_free(*a);
				free_tab(sp, i);
				ft_error();
			}
			fill_stack(a, sp, i);
		}
		free_tab(sp, i);
	}
	ft_duplicate(a);
}

int	handle_opts(t_stack **a, t_stack **b, char *opt)
{
	if (ft_strncmp(opt, "sa\n", 3) == 0)
		sa(*a);
	else if (ft_strncmp(opt, "sb\n", 3) == 0)
		sb(*b);
	else if (ft_strncmp(opt, "ss\n", 3) == 0)
		ss(*a, *b);
	else if (ft_strncmp(opt, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(opt, "pb\n", 3) == 0)
		pb(b, a);
	else if (ft_strncmp(opt, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(opt, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(opt, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(opt, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(opt, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(opt, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (-1);
	return (1);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*opt;

	if (argc == 1)
		exit(1);
	a = NULL;
	b = NULL;
	handle_error(&a, argv);
	opt = get_next_line(0);
	while (opt)
	{
		if (handle_opts(&a, &b, opt) == -1)
			ft_exit(a, b);
		free(opt);
		opt = get_next_line(0);
	}
	if (is_sorted(a) && b == NULL)
		ft_fprintf(1, "OK\n");
	else
		ft_fprintf(1, "KO\n");
	return (0);
}
