
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
    t_node  *node;

    printf("argc %d\n", argc);
    node = make_list(argc, argv);
    delete_node(node);            
}
