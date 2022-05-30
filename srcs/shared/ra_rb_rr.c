/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:10:19 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:50:06 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack1, t_stack **stack2, int null_val)
{
	ra_rb(stack1, null_val);
	ra_rb(stack2, null_val);
}

void	ra_rb(t_stack **stack, int null_val)
{
	t_stack	*temp;
	t_stack	*loop;
	t_stack	*insert;

	temp = *stack;
	(*stack) = (*stack)->next;
	loop = *stack;
	while (loop->next && loop->next->sorted != null_val)
		loop = loop->next;
	if (loop->next)
		insert = loop->next;
	else
		insert = NULL;
	loop->next = temp;
	temp->next = insert;
}
