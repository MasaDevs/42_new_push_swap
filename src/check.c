/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:47:08 by marai             #+#    #+#             */
/*   Updated: 2023/02/11 03:05:09 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    t_node  *node;

    printf("argc %d\n", argc);
    node = make_list(argc, argv);
    delete_node(node);    
        
}

t_node  *make_list(int argc, char *argv[])
{
    t_node  *stack_a;
    ssize_t  numslen;
    int     *nums;

    if (argc == 1)
        exit(0);    
    numslen = check_compose(argc, argv);
    printf("compose ok %ld\n", numslen);
    if (argc == 2)
        nums = make_array_2(numslen, argv);
    else
        nums = make_array_3(numslen, argv);
    for (int i = 0; i < numslen; i++)
        printf("number %d  is %d\n", i+1, nums[i]);
    check_duplicate(numslen, nums);
    printf("nums ok\n");
    stack_a = make_nodes(numslen, nums); 
    printf("nodes ok\n");
    return (stack_a);
}

ssize_t check_compose(int argc, char *argv[])
{
    ssize_t  i;
    ssize_t  j;
    ssize_t  numslen;

    i = 1;
    numslen = 0;
    while(i < argc)
    {
        j = 0;
        while(argv[i][j] != '\0')
        {
            if (skip_num(&argv[i][j]) <= 0)
                error_exit();
            j += skip_num(&argv[i][j]);
            while (ft_isspace(argv[i][j]))
                j++;
            numslen++;    
        }
        i++;
    }
    return (numslen);
}

int *make_array_2(ssize_t numslen, char *argv[])
{
    ssize_t  i;
    ssize_t  j;
    long    num;
    int     *nums;
    
    i = 0;
    j = 0;
    nums = malloc(sizeof(int) * numslen);
        if (!nums)
            error_exit();
    while (argv[1][j] != '\0') 
    {
        num = ft_atol(&argv[1][j]);
        if ((long)INT_MAX < num)
        {
            free(nums);
            error_exit();
        }
        nums[i] = (int) num;
        j += skip_num(&argv[1][j]);
        i++;
    }
    return (nums);
}


int *make_array_3(ssize_t numslen, char *argv[])
{
    ssize_t  i;
    long    num;
    int     *nums;

    nums = malloc(sizeof(int) * numslen);
    if(!nums)
        error_exit();
    i = 0;
    while (i < numslen) {
        num = ft_atol(argv[i + 1]);
        if((long)INT_MAX < num)
        {
            free(nums);
            error_exit();
        }
        nums[i] = (int) num;
        i++;
    }
    return (nums);
}

void check_duplicate(ssize_t numslen, int *nums)
{
    ssize_t  i;
    ssize_t  j;

    i = 0;
    while (i < numslen)
    {
        j = i + 1;
        while (j < numslen)
        {
            if(nums[i] == nums[j])
            {
                free(nums);
                error_exit();
            }
            j++;
        }
        i++;
    }
}



