#include "../include/push_swap.h"
#include <stdlib.h>

t_node	*make_nodes(int argc, char *argv[]);
int		free_stack(t_node *stack);

int	main(int argc, char *argv[])
{
	t_node	*ps_a;
	int		i;

	i = 0;
	ps_a = make_nodes(argc, argv);
	while (i < argc)
	{
		printf("%d\n", ps_a->num);
		ps_a = ps_a->next;
		i++;
	}
}

t_node	*make_nodes(int argc, char *argv[])
{
	t_node	*ps_a;
	t_node	*prenode;
	t_node	*nownode;
	int		i;

	i = 1;
	ps_a = malloc(sizeof(t_node));
	if (!ps_a)
		return (free_stack(ps_a));
	prenode = ps_a;
	while (i < argc)
	{
		nownode = malloc(sizeof(t_node));
		if (!nownode)
			return (free_stack(ps_a));
		nownode->num = ft_atoi(argv[i]);
		prenode->next = nownode;
		nownode->before = prenode;
		prenode = nownode;
		i++;
	}
	return (ps_a);
}

int	free_stack(t_node *stack)
{
	t_node	*postnode;

	if (!stack)
		return (0);
	postnode = stack->next;
	while (postnode != stack)
	{
		stack->next = postnode->next;
		free(postnode);
		postnode = stack->next;
	}
	free(stack);
	return (1);
}
