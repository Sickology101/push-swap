/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:09:15 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:39:46 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct s_stack
{
	int				num;
	int				sorted;
	int				current;
	int				final;
	struct s_stack	*next;
}		t_stack;

void	sa_sb(t_stack **stack);
void	ss(t_stack **stack1, t_stack **stack2);
void	pa_pb(t_stack **stack1, t_stack **stack2);
void	ra_rb(t_stack **stack, int null_val);
void	rr(t_stack **stack1, t_stack **stack2, int null_val);
void	rra_rrb(t_stack **stack);
void	rrr(t_stack **stack1, t_stack **stack2);
int		create_stack(int argc, char **argv, t_stack **a, t_stack **b);
void	print_stack(t_stack *stack, int null_val);
void	calculate_lis(t_stack *stack);
int		check_sorted(t_stack *a, t_stack *b, int null_val);
void	set_prereq(t_stack *a, int null_val);
int		get_biggest_lis(t_stack *a);
void	update_current(t_stack *stack);
void	set_lis(t_stack *stack, int index);
char	*generate(t_stack **a, t_stack **b, int null_val);
char	*fix(t_stack **stack);
int		get_smallest(t_stack *stack, int null_val);
int		get_biggest(t_stack *stack);
int		check_mid(t_stack *a, int mid);
int		get_last(t_stack *a);
char	*sort_small(t_stack **a, t_stack **b, int null_val);
int		count_unsorted(t_stack *a);
#endif