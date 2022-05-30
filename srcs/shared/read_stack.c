/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 08:02:20 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:49:32 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *a, t_stack *b, int null_val)
{
	int	n;

	if (b->num != null_val)
		return (0);
	n = a->num;
	a = a->next;
	while (a->num > n && a->next != NULL)
	{
		n = a->num;
		a = a->next;
	}
	if (a->next == NULL && a->num > n)
		return (1);
	return (0);
}

int	check_unique(char *argv, t_stack *stack)
{
	int	num;

	num = ft_atoi(argv);
	while (stack != NULL)
	{
		if (stack->num == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*

A function to print the stack, used for debugging

void	print_stack(t_stack *stack, int null_val)
{
	while (stack && stack->num != null_val)
	{
		ft_printf("%d  index = %d    final = %d\n",stack->num, 
			stack->sorted, stack->final);
		stack = stack->next;
	}
}*/

static	t_stack	*add_to_stack(char *argv, int *null_val)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->num = ft_atoi(argv);
	node->sorted = -1;
	node->final = 0;
	if (node->num == *null_val)
		(*null_val)--;
	node->next = NULL;
	return (node);
}

static void	init_stack(t_stack **stack, int null_val)
{
	(*stack)->num = null_val;
	(*stack)->final = 1;
	(*stack)->sorted = -1;
	(*stack)->next = NULL;
}

int	create_stack(int argc, char **argv, t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		index;
	int		null_val;

	index = 1;
	null_val = -1;
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	(*a)->num = ft_atoi(argv[index++]);
	(*a)->sorted = -1;
	if ((*a)->num == null_val)
		null_val--;
	init_stack(b, null_val);
	temp = *a;
	while (index < argc)
	{
		if (check_unique(argv[index],*a))
		{
			ft_printf("error");
			return (0);
		}
		temp->next = add_to_stack(argv[index++], &null_val);
		temp = temp->next;
	}
	return (null_val);
}
