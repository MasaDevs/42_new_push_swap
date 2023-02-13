
#include "../include/push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main(int argc, char *argv[])
{
    t_node  *stack_a;
	t_node	*stack_b;
    stack_a = make_list(argc, argv);
	//printf("nth %d\n", nth_small_num(node, 2));
	//printf("-----------sort start-------------\n");
	stack_b = malloc(sizeof(t_node));
	stack_b->next = stack_b;
	stack_b->back = stack_b;
	//sort_node_under6(stack_a, stack_b, get_node_len(stack_a), 1);
    //swap_headnode(node, 1);
	push_smaller_nodes(stack_a, stack_b, get_node_len(stack_a), 1);
	//print(stack_a, stack_b);
	push_swap(stack_a, stack_b, get_node_len(stack_a), get_node_len(stack_b));
    delete_node(stack_a);
	free(stack_b);
}
