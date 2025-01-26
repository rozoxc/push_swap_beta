/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:27:24 by mcombeau          #+#    #+#             */
/*   Updated: 2025/01/26 10:25:07 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	my_free(char **s)
{
	int j;

	j = 0;
	while (s[j] != NULL)
	{
		free(s[j]);
		j++;
	}
	free(s);
}
int	ft_is_digit(char *str)
{
	int	i;
	int	found_digit;

	i = 0;
	found_digit = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!str[i] || str[i] < '0' || str[i] > '9')
			return (0);
		found_digit = 1;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	return (found_digit);
}

int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **av, int size)
{
	int	i;
	int	nb_zeros;
	(void)size;

	nb_zeros = 0;
	i = 1;
	while (av[i])
	{
		if (ft_is_digit(av[i]) == 0)
			return (0);
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	return (1);
}
