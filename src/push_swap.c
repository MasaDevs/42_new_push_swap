/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:35:31 by marai             #+#    #+#             */
/*   Updated: 2023/02/13 15:48:13 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t	is_nodes_ordered(t_node *stack);

void	push_swap(t_node *stack_a, ssize_t stacklen)
{
	t_node	*stack_b;
	ssize_t	a_activelen;
	ssize_t	b_activelen;
	ssize_t	movednodelen;
	ssize_t	i;
	a_activelen	= stacklen;
	b_activelen = stacklen;
	stack_b = malloc(sizeof(t_node));
	if(!stack_b)
		return;
	stack_b->next = stack_b;
	stack_b->back = stack_b;
	stack_b->compressed_num = 0;

	while (!is_nodes_ordered(stack_a) || stack_b->next != stack_b) 
	{
		b_activelen = push_bigger_nodes(stack_a, stack_b, b_activelen, 1);
		a_activelen -= b_activelen;
		while (b_activelen < 7)
		{
			movednodelen = push_bigger_nodes(stack_b, stack_a, b_activelen, 0);
			a_activelen += movednodelen;
			b_activelen -= movednodelen;
		}
		i = 0;
		while (i < b_activelen)
		{
			push_headnode(stack_a, stack_b, 1);
			rotate_stack(stack_a, 1);
			i++;
		}
		b_activelen = 2 * b_activelen - 1;
	}
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
