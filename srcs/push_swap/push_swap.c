/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marius <marius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:58:47 by marius            #+#    #+#             */
/*   Updated: 2022/05/29 16:38:21 by marius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, int index)
{
	t_stack	*temp;
	t_stack *smallest;
	int		count;

	temp = a;
	count = -1;
	while (temp->sorted != -1 && temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp != NULL)
		smallest = temp;
	while (temp != NULL)
	{
		if (temp->num < smallest->num && temp->sorted == -1)
			smallest = temp;
		temp = temp->next;
		count++;
	}
	if (count == 0 && smallest->next == NULL && smallest->sorted == -1)
	{
		smallest->sorted = index++;
	}
	if (count != 0)
	{
		smallest->sorted = index++;
		sort(a,index);
	}
}

int	calculate_actions(char *str)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while(str[index] != '\0')
	{
		if (str[index] == '\n')
			count++;
		index++;
	}
	return (count);
}


int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int		null_val;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char));
	buffer[0] = '\0';
	if (argc == 1)
		return (0);
	null_val = create_stack(argc, argv, &a, &b);
	sort(a, 1);
	update_current(a);
	argc--;
	sort(a, null_val);
	if (!check_sorted(a, b, null_val))
		buffer = ft_strupdate(buffer, generate(&a, &b, null_val));
	while(!check_sorted(a, b, null_val))
	{
		ra_rb(&a, null_val);
		buffer = ft_strupdate(buffer, "ra\n");
	}
	printf("\nactions needed = %d\n",calculate_actions(buffer));
	return (1);
}
