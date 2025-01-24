/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:44:42 by mcombeau          #+#    #+#             */
/*   Updated: 2025/01/24 16:53:01 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack	*stack_a;
	char	**split;
	long	nb;
	int		i;
	int		j;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			nb = ft_atoi(split[j]);
			if (nb < INT_MIN || nb > INT_MAX)
			{
				free(split);
				exit_error(&stack_a, NULL);
			}
			stack_add_bottom(&stack_a, stack_new((int)nb));
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
