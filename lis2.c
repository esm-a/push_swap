/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:43:18 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 12:26:00 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lis	*ft_alloc(int *arr, int *sub, int *l)
{
	t_lis	*lis;

	lis = malloc(sizeof(t_lis));
	if (lis == NULL)
	{
		free(arr);
		free(sub);
		free(l);
		return (NULL);
	}
	return (lis);
}

void	free_lis(t_lis *lis, int *arr, int *sub, int *l)
{
	free(lis);
	free(arr);
	free(sub);
	free(l);
}

void	check_helper(int *arr, int *sub, int *l)
{
	if (l == NULL)
	{
		free(arr);
		free(sub);
	}
	if (sub == NULL)
	{
		free(arr);
		free(l);
	}
}
