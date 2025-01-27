/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_diplucated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:28:11 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/27 15:37:34 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_diplucated(t_stack *stack_a)
{
	t_stack	*outer;
	t_stack	*inner;

	outer = stack_a;
	while (outer != NULL)
	{
		inner = outer->next;
		while (inner != NULL)
		{
			if (outer->value == inner->value)
				return (0);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (1);
}
