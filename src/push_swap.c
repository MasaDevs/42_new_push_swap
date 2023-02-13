/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:35:31 by marai             #+#    #+#             */
/*   Updated: 2023/02/13 17:04:39 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t	is_nodes_ordered(t_node *stack);

ssize_t	push_swap(t_node *stack_a, t_node *stack_b, ssize_t a_activelen, ssize_t b_activelen)
{
	ssize_t	movedlen;

	movedlen = push_bigger_nodes(stack_b, stack_a, b_activelen, 0);
	a_activelen -= movedlen;
	b_activelen += movedlen;
	while ()
	{
		a_activelen = push_swap(stack_a, stack_b, a_activelen, b_activelen);

	return (0);
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
