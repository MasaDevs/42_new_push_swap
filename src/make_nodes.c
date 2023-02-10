/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:12:33 by marai             #+#    #+#             */
/*   Updated: 2023/02/11 00:51:17 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_node  *make_nodes(size_t numslen, int *nums)
{
    t_node  *stack_a;
    t_node  *nownode;
    t_node  *newnode;
    size_t  i;

    stack_a = malloc(sizeof(t_node));
    if (!stack_a)
        detele_everything(nums, stack_a);
    i = 0;
    nownode = stack_a;
    while (i < numslen) 
    {
        newnode = malloc(sizeof(t_node));
        if(!newnode)
            detele_everything(nums, stack_a);
        newnode->back  = nownode;
        nownode->next = newnode;
        nownode = newnode;
        i++;
    }
    stack_a->back = nownode;
    nownode->next = stack_a;
    return (stack_a);
}

void    detele_everything(int *nums, t_node *stack)
{
    free(nums);
    if (stack)
        delete_node(stack);
    error_exit();
}

void    delete_node(t_node *stack)
{
    t_node  *postnode;

    postnode = stack->next;
    while (stack != postnode) 
    {
        stack->next = postnode->next;
        printf("delete %d\n", postnode->num);
        free(postnode);
        postnode = stack->next;
    }
    free(stack);
}

