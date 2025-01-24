/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:57:59 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/24 16:56:51 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_numbers(char **av, int ac)
{
	int		i;
	int		count;
	int		j;
	char	**split;

	i = 1;
	count = 0;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j] != NULL)
		{
			count++;
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	return (count);
}