/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:08:24 by marai             #+#    #+#             */
/*   Updated: 2023/02/14 03:39:08 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_isspace(char c);
void	error_exit(void);
ssize_t	skip_num(char *str);
long	ft_atol(char *str);

int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

ssize_t	skip_num(char *str)
{
	ssize_t	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	ans;
	int		sign;
	ssize_t	i;

	ans = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if ((long)INT_MAX < ans || ans < (long)INT_MIN)
			return (LONG_MAX);
		ans = 10 * ans + (str[i] - '0');
		i++;
	}
	return (ans * sign);
}
