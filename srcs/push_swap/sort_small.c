/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:08:35 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:28:07 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *sort_small(t_stack **a, t_stack **b, int null_val)
{
	char *buffer;
	int		biggest;

	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\0';
	biggest = get_biggest(*a);
	while (count_unsorted(*a) > 1)
	{
		if ((*a)->sorted == biggest)
		{
			ra_rb(a, null_val);
			buffer = ft_strupdate(buffer, "ra\n");
		}
		else
		{
			pa_pb(a, b);
			buffer = ft_strupdate(buffer, "pb\n");
		}
	}
	if ((*a)->sorted != biggest)
	{
		rra_rrb(a);
		buffer = ft_strupdate(buffer, "rra\n");
	}
	while ((*b)->final == 0)
	{
		biggest = get_biggest(*b);
		if ((*b)->sorted == biggest)
		{
			pa_pb(b, a);
			(*a)->final = 1;
			buffer = ft_strupdate(buffer, "pa\n");
		}
		else
		{
			ra_rb(b, null_val);
			buffer = ft_strupdate(buffer, "rb\n");
		}
	}
	return (buffer);
}