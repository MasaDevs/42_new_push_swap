/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:08:24 by marai             #+#    #+#             */
/*   Updated: 2023/02/11 00:09:26 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



int ft_isspace(char c)
{
    return ((9 <= c && c <= 13) || c == ' ');
}

void    error_exit()
{
    ft_putstr_fd("Error\n", 1);
    exit(1);
}


size_t  skip_num(char *str)
{
    size_t  i;

    i = 0;
    while (ft_isspace(str[i]))
        i++;
    while (ft_isdigit(str[i]))
        i++;
    return (i);
}

long	ft_atol(char *str)
{
	long	ans;
	int		sign;
	size_t	i;

	ans = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
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

