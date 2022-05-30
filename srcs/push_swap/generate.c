/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:25:37 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:31:52 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_stack **b, t_stack **a, int null_val)
{
	int		biggest;
	int		smallest;
	int		mid;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\0';
	biggest = get_biggest(*b);
	smallest = get_smallest(*b, null_val);
	mid = (biggest + smallest) / 2;
	while ((*b)->num != null_val)
	{
		if ((*b)->sorted > mid)
		{
			pa_pb(b, a);
			buffer = ft_strupdate(buffer, "pa\n");
		}
		else
		{
			if ((*b)->sorted == smallest)
			{
				pa_pb(b, a);
				(*a)->final = 1;
				ra_rb(a, null_val);
				buffer = ft_strupdate(buffer, "pa\nra\n");
				smallest = get_smallest(*b, null_val);
			}
			else
			{
				ra_rb(b, null_val);
				buffer = ft_strupdate(buffer, "rb\n");
			}
		}
	}
	return (buffer);
}

char	*push_b(t_stack **a, t_stack **b, int null_val)
{
	int		biggest;
	int		smallest;
	int		mid;
	char	*buffer;
	
	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\0';
	biggest = get_biggest(*a);
	smallest = get_smallest(*a, null_val);
	mid = (biggest + smallest) / 2;
	while (check_mid(*a, mid))
	{
		if ((*a)->sorted <= mid && (*a)->final == 0)
		{
			pa_pb(a, b);
			buffer = ft_strupdate(buffer, "pb\n");
		}
		else
		{
			ra_rb(a, null_val);
			buffer = ft_strupdate(buffer, "ra\n");
		}
	}
	return (buffer);
}


char *fix(t_stack **a)
{
	char *buffer;

	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\0';
	while(get_last(*a) == 0)
	{
		rra_rrb(a);
		buffer = ft_strupdate(buffer, "rra\n");
	}
	return (buffer);
}

int	count_unsorted(t_stack *a)
{
	int	count;

	count = 0;
	while(a)
	{
		if (a->final == 0)
			count++;
		a = a->next;
	}
	return (count);
}

char	*generate(t_stack **a, t_stack **b, int null_val)
{
	char	*buffer;
	int i = 0;
	
	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\n';
	
	while (!check_sorted(*a, *b, null_val))
	{
		if ((*b)->num != null_val)
		{
			buffer = ft_strupdate(buffer, push_a(b, a, null_val));
			if (count_unsorted(*a) < 5)
			{
				sort_small(a, b, null_val);
				break ;
			}
		}	
		else
		{
			buffer = ft_strupdate(buffer, push_b(a, b, null_val));
		}
		if (get_last(*a) == 0 && i++ > 0)
			buffer = ft_strupdate(buffer, fix(a));
	}
	return (buffer);
}