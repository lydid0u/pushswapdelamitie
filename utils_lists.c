/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzinabi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:31:09 by lboudjel          #+#    #+#             */
/*   Updated: 2023/11/13 17:03:03 by adzinabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}
void	ft_vrai_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->vrai_index = i;
		stack = stack->next;
		i++;
	}
}

t_stack	*get_last_node(t_stack *stack_a)
{
	t_stack	*last;

	last = stack_a;
	while (last->next)
		last = last->next;
	return (last);
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n\n");
}

void	print_index(t_stack *stack_a)
{
	ft_printf("index\n");
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->index);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}

int	in_order(t_stack **stack_a)
{
	t_stack	*i;
	t_stack	*j;

	if (stack_a == NULL)
		return (0);
	i = *stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->nbr > j->nbr)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void	where_am_i(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->position = i;
		stack_a = stack_a->next;
		i++;
	}
}