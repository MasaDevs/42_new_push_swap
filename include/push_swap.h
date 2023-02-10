

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

typedef struct i_node
{
	int				num;
	int				compressed_num;
    struct i_node   *back;
	struct i_node	*next;
}					t_node;


// push_swap_utils.c
int     ft_isspace(char c);
void    error_exit();
long    ft_atol(char *str);
size_t  skip_num(char *str);

// check.c
t_node  *make_list(int argc, char *argv[]);
size_t  check_compose(int argc, char *argv[]);
void    check_duplicate(size_t numslen, int *nums);
int     *make_array_2(size_t numslen, char *argv[]);
int     *make_array_3(size_t numslen, char *argv[]);
void    check_duplicate(size_t numslen, int *nums);

// make_nodes.c
t_node  *make_nodes(size_t numslen, int *nums);
void    detele_everything(int *nums, t_node *stack);
void    delete_node(t_node *stack);
#endif
