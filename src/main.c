
#include "../include/push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main(int argc, char *argv[])
{
    t_node  *stack_a;
    stack_a = make_list(argc, argv);
	//printf("nth %d\n", nth_small_num(node, 2));
	//printf("-----------sort start-------------\n");
	//sort_node_under6(stack_a, stack_b, get_node_len(stack_a), 1);
    //swap_headnode(node, 1);
	push_swap(stack_a, get_node_len(stack_a));
    delete_node(stack_a);
}
