/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:01:46 by marai             #+#    #+#             */
/*   Updated: 2023/02/14 04:50:51 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sort_node_under3(t_node *stack, ssize_t activelen, ssize_t stacknum);
ssize_t	push_bigger_nodes(t_node *stack1, t_node *stack2, ssize_t activelen,
			ssize_t stacknum);
void	sort_node_under6(t_node *stack1, t_node *stack2, ssize_t activelen,
			ssize_t stacknum);
t_node	*sort_node_2(t_node *stack, ssize_t stacknum);
t_node	*sort_node_3(t_node *stack, ssize_t stacknum);
ssize_t	is_nodes_sorted(t_node *stack);
void	make_1st_node_head(t_node *stack, ssize_t stacknum);

void	sort_node_under3(t_node *stack, ssize_t activelen, ssize_t stacknum)
{
	if (activelen < 2)
		return ;
	else if (activelen == 2)
		sort_node_2(stack, stacknum);
	else if (activelen == 3)
		sort_node_3(stack, stacknum);
	return ;
}

void	sort_node_under6(t_node *stack1, t_node *stack2, ssize_t activelen,
		ssize_t stacknum)
{
	ssize_t	movednum;

	if (activelen < 2)
		return ;
	else if (activelen == 2)
		sort_node_2(stack1, stacknum);
	else if (activelen == 3)
		sort_node_3(stack1, stacknum);
	else if (activelen < 7 && !is_nodes_sorted(stack1))
	{
		movednum = 0;
		while (3 < get_node_len(stack1))
		{
			while (stack1->next->compressed_num != nth_small_num(stack1, 1,
					get_node_len(stack1)))
				rotate_stack(stack1, stacknum);
			push_headnode(stack2, stack1, stacknum + 1);
			movednum++;
		}
		sort_node_under3(stack1, get_node_len(stack1), stacknum);
		while (movednum--)
			push_headnode(stack1, stack2, stacknum);
	}
	return ;
}

ssize_t	push_bigger_nodes(t_node *stack1, t_node *stack2, ssize_t activelen,
		ssize_t stacknum)
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
			push_headnode(stack2, stack1, stacknum + 1);
			swappednum++;
		}
		else
			rotate_stack(stack1, stacknum);
		i++;
	}
	return (swappednum);
}

ssize_t	push_smaller_nodes(t_node *stack1, t_node *stack2, ssize_t activelen,
		ssize_t stacknum)
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
		if (nownode1->compressed_num <= threshold)
		{
			push_headnode(stack2, stack1, stacknum + 1);
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
	else if (nownode2->compressed_num < nownode1->compressed_num
			&& nownode1->compressed_num < nownode3->compressed_num)
		swap_headnode(stack, stacknum);
	else if (nownode2->compressed_num < nownode3->compressed_num
			&& nownode3->compressed_num < nownode1->compressed_num)
		rotate_stack(stack, stacknum);
	else if (nownode3->compressed_num < nownode1->compressed_num
			&& nownode1->compressed_num < nownode2->compressed_num)
		reverse_rotate_stack(stack, stacknum);
	else if (nownode3->compressed_num < nownode2->compressed_num
			&& nownode2->compressed_num < nownode1->compressed_num)
	{
		rotate_stack(stack, stacknum);
		swap_headnode(stack, stacknum);
	}
	return (stack);
}

ssize_t	is_nodes_sorted(t_node *stack)
{
	t_node	*nownode;
	int		previous;

	nownode = stack->next;
	previous = 0;
	while (nownode != stack)
	{
		if (nownode->compressed_num < previous)
			return (0);
		previous = nownode->compressed_num;
		nownode = nownode->next;
	}
	return (1);
}

void	make_1st_node_head(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode;
	ssize_t	nodelen;
	ssize_t	i;
	int		num;
	
	i = 0;
	nownode = stack->next;
	nodelen = get_node_len(stack);
	num = nth_small_num(stack, 1, nodelen);
	while (i <= nodelen)
	{
		if(nownode->compressed_num == num)
			break;
		nownode = nownode->next;
		i++;
	}
	if(i < nodelen / 2)
		while (0 < i--)
			rotate_stack(stack, stacknum);
	else
		while (0 < i--)
			reverse_rotate_stack(stack, stacknum);
}












