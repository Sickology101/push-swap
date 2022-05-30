/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:19:38 by marius            #+#    #+#             */
/*   Updated: 2022/05/18 14:17:45 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_current(t_stack *stack)
{
	int index;

	index = 0;

	while (stack != NULL)
	{
		stack->current = index++;
		stack = stack->next;
	}
}

int	check_sorted_stack(t_stack *stack)
{
	int	n;

	n = stack->num;
	stack = stack->next;
	while (stack->num > n && stack->next != NULL)
	{
		n = stack->num;
		stack = stack->next;
	}
	if (stack->next == NULL && stack->num > n)
		return (1);
	return (0);
}