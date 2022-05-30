/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:08:36 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:44:15 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	check_sorted(t_stack *a, t_stack *b, int null_val)
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
}*/

static int	read_inst(char *line, t_stack **a, t_stack **b, int null_val)
{
	if (!ft_strcmp(line, "sa"))
		sa_sb(a);
	else if (!ft_strcmp(line, "sb"))
		sa_sb(b);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa"))
		pa_pb(b, a);
	else if (!ft_strcmp(line, "pb"))
		pa_pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		ra_rb(a, null_val);
	else if (!ft_strcmp(line, "rb"))
		ra_rb(b, null_val);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b, null_val);
	else if (!ft_strcmp(line, "rra"))
		rra_rrb(a);
	else if (!ft_strcmp(line, "rrb"))
		rra_rrb(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		null_val;

	if (argc == 1)
		return (0);
	null_val = create_stack(argc, argv, &a, &b);
	while (get_next_line(0, &line))
	{
		if (read_inst(line, &a, &b, null_val))
		{
			if (ft_strcmp(line, ""))
				ft_printf("ERROR");
			break ;
		}
	}
	if (check_sorted(a, b, null_val))
		ft_printf("OK");
	else
		ft_printf("KO");
	return (1);
}
