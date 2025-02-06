/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:21:13 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/06 16:03:10 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	process_split(t_stack **stack_a, char **split)
{
	long long	nb;
	int			j;

	j = 0;
	while (split[j] != NULL)
	{
		nb = ft_atoi(split[j]);
		if (nb < INT_MIN || nb > INT_MAX)
		{
			free(split[j]);
			free(split);
			exit_error(stack_a, NULL);
		}
		stack_add_bottom(stack_a, stack_new((int)nb));
		free(split[j]);
		j++;
	}
}

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack	*stack_a;
	char	**split;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			exit_error(&stack_a, NULL);
		process_split(&stack_a, split);
		free(split);
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*p;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		p = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (p != NULL)
		{
			if (p->value == INT_MIN && p->index == 0)
				p->index = 1;
			if (p->value > value && p->index == 0)
			{
				value = p->value;
				highest = p;
				p = stack_a;
			}
			else
				p = p->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
