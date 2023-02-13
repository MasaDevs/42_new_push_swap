/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:01:46 by marai             #+#    #+#             */
/*   Updated: 2023/02/13 13:28:28 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sort_node_under3(t_node *stack, ssize_t activelen, ssize_t stacknum);
ssize_t	push_bigger_nodes(t_node *stack1, t_node *stack2, ssize_t activelen, ssize_t stacknum);
void	sort_node_under6(t_node *stack1, t_node *stack2, ssize_t activelen, ssize_t stacknum);
t_node	*sort_node_2(t_node *stack, ssize_t stacknum);
t_node	*sort_node_3(t_node *stack, ssize_t stacknum);

void	sort_node_under3(t_node *stack, ssize_t activelen, ssize_t stacknum)
{
	if(activelen < 2)
		return;
	else if (activelen == 2)
	 	sort_node_2(stack, stacknum);
	else if (activelen == 3)
		sort_node_3(stack, stacknum);
}

void	sort_node_under6(t_node *stack1, t_node *stack2, ssize_t activelen, ssize_t stacknum)
{
	ssize_t swappednum;
	ssize_t	i;

	if(activelen < 2)
		return;
	else if(activelen == 2)
		sort_node_2(stack1, stacknum);
	else if (activelen == 3)
	 	sort_node_3(stack1, stacknum);
	else if (activelen < 7)
	{
		swappednum =  push_bigger_nodes(stack1, stack2, activelen, stacknum);
		printf("--push end--\n");
		sort_node_under3(stack1, activelen - swappednum, stacknum);
		sort_node_under3(stack2, swappednum, stacknum + 1);
		printf("--sort end--\n");
		i = 0;
		while (i < swappednum)
		{
			push_headnode(stack1, stack2, stacknum);
			rotate_stack(stack1, stacknum);
			i++;
		}
	}
}

// push stack2 stack bigger nodes;

ssize_t	push_bigger_nodes(t_node *stack1, t_node *stack2, ssize_t activelen, ssize_t stacknum)
{
	ssize_t	i;
	ssize_t	swappednum;
	int		threshold;
	t_node	*nownode1;

	threshold = nth_small_num(stack1, activelen / 2, activelen);
	printf("threshhold %d\n", threshold);
	i = 0;
	swappednum = 0;
	while (i < activelen)
	{
		nownode1 = stack1->next;
		if (threshold < nownode1->compressed_num)
		{
			push_headnode(stack2, stack1, stacknum);
			swappednum++;
		}
		else
			rotate_stack(stack1, stacknum);
		i++;
	}
	return (swappednum);
}

t_node	*sort_node_2(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode;

	nownode = stack->next;
	if (nownode->compressed_num < nownode->next->compressed_num)
		return (stack);
	swap_headnode(stack, stacknum);
	return (stack);
}

t_node	*sort_node_3(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode1;
	t_node	*nownode2;
	t_node	*nownode3;

	nownode1 = stack->next;
	nownode2 = stack->next->next;
	nownode3 = stack->next->next->next;
	if (nownode1->compressed_num < nownode3->compressed_num &&
		nownode3->compressed_num < nownode2->compressed_num)
	{
		swap_headnode(stack, stacknum);
		rotate_stack(stack, stacknum);
	}
	else if (nownode2->compressed_num < nownode1->compressed_num &&
				nownode1->compressed_num < nownode3->compressed_num)
		swap_headnode(stack, stacknum);
	else if (nownode2->compressed_num < nownode3->compressed_num &&
				nownode3->compressed_num < nownode1->compressed_num)
		rotate_stack(stack, stacknum);
	else if (nownode3->compressed_num < nownode1->compressed_num &&
				nownode1->compressed_num < nownode2->compressed_num)
		reverse_rotate_stack(stack, stacknum);
	else if (nownode3->compressed_num < nownode2->compressed_num &&
				nownode2->compressed_num < nownode1->compressed_num)
	{
		rotate_stack(stack, stacknum);
		swap_headnode(stack, stacknum);
	}
	return (stack);
}
