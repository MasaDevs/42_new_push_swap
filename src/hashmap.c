#include "../include/push_swap.h"
#include <stdio.h>


t_node  *compress_nodes(t_node *stack, ssize_t numslen, int *nums)
{
    t_node  *node;
    int     i;

    i = 0;
}



int *nums_copy(int *nums, ssize_t numslen)
{
    int     *nums_copy;
    ssize_t i;

    nums_copy = malloc(sizeof(int) * numslen);
    if(!nums_copy)
        NULL;
    i = 0;
    while (i < numslen)
    {
        nums_copy[i] = nums[i];
        i++;
    }
    return (nums_copy);
}

int *nums_heapsort(int *nums, ssize_t numslen)
{
    ssize_t numslen_copy;
    ssize_t target;

    target = entry_depth(numslen);
    if((target * 2 + 1) < numslen && nums[target * 2 + 1] > nums[target])
        int_swap(nums, target * 2 + 1, target);
    if((target * 2 + 2) < numslen && nums[target * 2 + 2] > nums[target])
        int_swap(nums, target * 2 + 2, target);







}

ssize_t entry_depth(ssize_t numslen)
{
    ssize_t devidend;
    ssize_t entry_node;
    
    if (numslen < 0)
        return (-1);
    devidend = numslen;
    entry_node = 0;
    while (devidend > 0)
    {
        devidend /= 2;
        entry_node++;
    }
    return (entry_node);
}


int *int_swap(int *nums, ssize_t first, ssize_t second)
{
    int *temp;
    
    temp = nums[first];
    nums[first] = nums[second];
    nums[second] = temp;
    return (nums);
}
