/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:35:31 by marai             #+#    #+#             */
/*   Updated: 2023/02/14 03:58:07 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t	is_nodes_ordered(t_node *stack);
void	see_node(t_node *stack);

void	push_swap(t_node *stack_a, t_node *stack_b, ssize_t a_activelen,
		ssize_t b_activelen)
{
	ssize_t	movedlen;
	ssize_t	sortedlen;

	while (!is_nodes_ordered(stack_a) || b_activelen != 0)
	{
		printf("intial status\n");
		print(stack_a, stack_b);
		movedlen = 0;
		while (6 < b_activelen)
		{
			movedlen = push_bigger_nodes(stack_b, stack_a, b_activelen, 0);
			a_activelen += movedlen;
			b_activelen -= movedlen;
		}
		printf("after making quick sort\n");
		print(stack_a, stack_b);
		sort_node_under6(stack_b, stack_a, b_activelen, 0);
		while (0 < b_activelen)
		{
			push_headnode(stack_a, stack_b, 1);
			rotate_stack(stack_a, 1);
			b_activelen--;
		}
		printf("after sorted\n");
		print(stack_a, stack_b);
		sortedlen = get_node_len(stack_a) - a_activelen;
		while (b_activelen < sortedlen && a_activelen)
		{
			push_headnode(stack_b, stack_a, 0);
			a_activelen--;
			b_activelen++;
		}
		if (a_activelen == 1)
		{
			push_headnode(stack_b, stack_a, 0);
			a_activelen--;
			b_activelen++;
		}
	}
}

void	see_node(t_node *stack)
{
	t_node	*nownode;

	nownode = stack->next;
	while (nownode != stack)
	{
		printf("inside %d\n", nownode->compressed_num);
		nownode = nownode->next;
	}
}

void	print(t_node *stack_a, t_node *stack_b)
{
	printf("------stack_a num-------\n");
	printf("stack_a num %ld\n", get_node_len(stack_a));
	printf("--------stack_a----------\n");
	see_node(stack_a);
	printf("------stack_b num-------\n");
	printf("stack_b num %ld\n", get_node_len(stack_b));
	printf("--------stack_b----------\n");
	see_node(stack_b);
	printf("\n\n");
}
ssize_t	is_nodes_ordered(t_node *stack)
{
	t_node	*nownode;
	int		previousnum;

	nownode = stack->next;
	previousnum = stack->next->compressed_num;
	while (nownode != stack)
	{
		if (nownode->compressed_num < previousnum)
			return (0);
		previousnum = nownode->compressed_num;
		nownode = nownode->next;
	}
	return (1);
}
