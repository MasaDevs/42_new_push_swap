/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:20:06 by marai             #+#    #+#             */
/*   Updated: 2023/02/14 03:20:07 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	rotate_stack(t_node *stack, ssize_t stacknum);
void	reverse_rotate_stack(t_node *stack, ssize_t stacknum);
void	push_headnode(t_node *stack1, t_node *stack2, ssize_t stacknum);
void	swap_headnode(t_node *stack, ssize_t stacknum);

void	rotate_stack(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode;
	t_node	*lastnode;

	nownode = stack->next;
	lastnode = get_lastnode(stack);
	nownode->next->back = stack;
	stack->next = nownode->next;
	stack->back = nownode;
	nownode->next = stack;
	lastnode->next = nownode;
	nownode->back = lastnode;
	if (stacknum == 1)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate_stack(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode;
	t_node	*lastnode;

	nownode = stack->next;
	lastnode = get_lastnode(stack);
	lastnode->back->next = stack;
	stack->back = lastnode->back;
	lastnode->next = nownode;
	nownode->back = lastnode;
	lastnode->back = stack;
	stack->next = lastnode;
	if (stacknum == 1)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

void	push_headnode(t_node *stack1, t_node *stack2, ssize_t stacknum)
{
	t_node	*nownode1;
	t_node	*nownode2;

	nownode1 = stack1->next;
	nownode2 = stack2->next;
	stack2->next = nownode2->next;
	nownode2->next->back = stack2;
	stack1->next = nownode2;
	nownode2->back = stack1;
	nownode2->next = nownode1;
	nownode1->back = nownode2;
	if (stacknum == 1)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

void	swap_headnode(t_node *stack, ssize_t stacknum)
{
	t_node	*nownode1;
	t_node	*nownode2;

	nownode1 = stack->next;
	nownode2 = stack->next->next;
	stack->next = nownode2;
	nownode2->back = stack;
	nownode1->next = nownode2->next;
	nownode2->next->back = nownode1;
	nownode1->back = nownode2;
	nownode2->next = nownode1;
	if (stacknum == 1)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}
