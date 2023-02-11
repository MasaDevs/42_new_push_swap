/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:12:33 by marai             #+#    #+#             */
/*   Updated: 2023/02/12 03:17:33 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_node	*make_nodes(ssize_t numslen, int *nums);
void	detele_everything(int *nums, t_node *stack);
void	delete_node(t_node *stack);
void	compress_nodes(t_node *stack, ssize_t numslen, int *nums);

t_node	*make_nodes(ssize_t numslen, int *nums)
{
	t_node	*stack_a;
	t_node	*nownode;
	t_node	*newnode;
	ssize_t	i;

	stack_a = malloc(sizeof(t_node));
	if (!stack_a)
		detele_everything(nums, stack_a);
	i = 0;
	nownode = stack_a;
	while (i < numslen)
	{
		newnode = malloc(sizeof(t_node));
		if (!newnode)
			detele_everything(nums, stack_a);
		newnode->num = nums[i];
		newnode->back = nownode;
		nownode->next = newnode;
		nownode = newnode;
		i++;
	}
	stack_a->back = nownode;
	nownode->next = stack_a;
	compress_nodes(stack_a, numslen, nums);
	return (stack_a);
}

void	detele_everything(int *nums, t_node *stack)
{
	free(nums);
	if (stack)
		delete_node(stack);
	error_exit();
}

void	delete_node(t_node *stack)
{
	t_node	*postnode;

	postnode = stack->next;
	while (stack != postnode)
	{
		stack->next = postnode->next;
		printf("num delete %d\n", postnode->num);
		printf("compressed_num delete %d\n", postnode->compressed_num);
		printf("\n");
		free(postnode);
		postnode = stack->next;
	}
	free(stack);
}

void	compress_nodes(t_node *stack, ssize_t numslen, int *nums)
{
	t_node	*nownode;
	ssize_t	i;

	heap_sort(nums, numslen);
	nownode = stack->next;
	stack->compressed_num = 0;
	while (stack != nownode)
	{
		i = 0;
		while (i < numslen)
		{
			if (nownode->num == nums[i])
			{
				nownode->compressed_num = i + 1;
				break ;
			}
			i++;
		}
		nownode = nownode->next;
	}
	free(nums);
}
