/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:21:17 by marai             #+#    #+#             */
/*   Updated: 2023/02/12 03:21:19 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		*heap_sort(int *nums, ssize_t numslen);
void	push_up(int *nums, ssize_t parent, ssize_t last);
int		*swap(int *nums, ssize_t first, ssize_t second);

int	*heap_sort(int *nums, ssize_t numslen)
{
	ssize_t	i;

	i = numslen / 2 - 1;
	while (0 <= i)
	{
		push_up(nums, i, numslen - 1);
		i--;
	}
	i = numslen - 1;
	while (1 <= i)
	{
		swap(nums, 0, i);
		push_up(nums, 0, i - 1);
		i--;
	}
	return (nums);
}

void	push_up(int *nums, ssize_t parent, ssize_t last)
{
	ssize_t	child;

	child = parent * 2 + 1;
	while (child <= last)
	{
		if (child + 1 <= last && nums[child] < nums[child + 1])
			child++;
		if (nums[child] < nums[parent])
			break ;
		swap(nums, parent, child);
		parent = child;
		child = parent * 2 + 1;
	}
	return ;
}

int	*swap(int *nums, ssize_t first, ssize_t second)
{
	int	temp;

	temp = nums[first];
	nums[first] = nums[second];
	nums[second] = temp;
	return (nums);
}
