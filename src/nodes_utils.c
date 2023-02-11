#include "../include/push_swap.h"
#include <stdio.h>

ssize_t	get_node_len(t_node *stack);
t_node	*get_lastnode(t_node *stack);

ssize_t	get_node_len(t_node *stack)
{
	t_node	*nownode;
	ssize_t	len;

	len = 0;
	nownode = stack->next;
	while (stack != nownode)
	{
		len++;
		nownode = nownode->next;
	}
	return (len);
}

t_node	*get_lastnode(t_node *stack)
{
	t_node	*nownode;

	nownode = stack->next;
	while (nownode->next != stack)
		nownode = nownode->next;
	return (nownode);
}
