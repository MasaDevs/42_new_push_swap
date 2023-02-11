#include "../include/push_swap.h"

void	rotate_stack(t_node *stack);
void	reverse_rotate_stack(t_node *stack);
void	push_headnode(t_node *stack1, t_node *stack2);
void	swap_headnode(t_node *stack);

void	rotate_stack(t_node *stack)
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
}

void	reverse_rotate_stack(t_node *stack)
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
}

void	push_headnode(t_node *stack1, t_node *stack2)
{
	t_node	*nownode1;
	t_node	*nownode2;

	nownode1 = stack1->next;
	nownode2 = stack2->next;
	stack1->next = nownode1->next;
	nownode1->next->back = stack1;
	stack2->next = nownode1;
	nownode1->back = stack2;
	nownode1->next = nownode2;
	nownode2->back = nownode1;
}

void	swap_headnode(t_node *stack)
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
}
