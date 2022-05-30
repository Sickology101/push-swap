/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:36:35 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 15:26:39 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last(t_stack *a)
{
	while (a->next != NULL)
		a = a->next;
	return (a->current);
}

int check_sorted_1(t_stack *a)
{
	int	end;

	end = find_last(a);
	while (end != 0)
	{
		if (a->sorted < a->next->sorted)
			a = a->next;
		end--;
	}
	if (a->next == NULL)
		return (1);
	else
		return (0);
}

int	get_biggest(t_stack *stack)
{
	int	biggest;
	
	biggest = stack->sorted;
	while (stack->final == 0 && stack->next)
	{
		if (biggest < stack->sorted)
			biggest = stack->sorted;
		stack = stack->next;
	}
	if (stack->next == NULL)
	{
		if (biggest < stack->sorted)
			biggest = stack->sorted;
	}
	return (biggest);
}

int	get_smallest(t_stack *stack, int null_val)
{
	int	smallest;
	
	smallest = stack->sorted;
	while (stack->final == 0 && stack->next && stack->num != null_val)
	{
		if (smallest > stack->sorted)
			smallest = stack->sorted;
		stack = stack->next;
	}
	if (stack->next == NULL && stack->sorted != null_val)
	{
		if (smallest > stack->sorted)
			smallest = stack->sorted;
	}
	return (smallest);
}

int	check_mid(t_stack *a, int mid)
{
	while (a)
	{
		if (a->sorted < mid && a->final == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

int	get_last(t_stack *a)
{
	while (a->next != NULL)
	{
		a = a->next;
	}
	return (a->final);
}