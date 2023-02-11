/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:21:59 by marai             #+#    #+#             */
/*   Updated: 2023/02/12 06:13:33 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct i_node
{
	int				num;
	int				compressed_num;
	struct i_node	*back;
	struct i_node	*next;
}					t_node;

// push_swap_utils.c
int					ft_isspace(char c);
void				error_exit(void);
long				ft_atol(char *str);
ssize_t				skip_num(char *str);

// check.c
t_node				*make_list(int argc, char *argv[]);
ssize_t				check_compose(int argc, char *argv[]);
void				check_duplicate(ssize_t numslen, int *nums);
int					*make_array_2(ssize_t numslen, char *argv[]);
int					*make_array_3(ssize_t numslen, char *argv[]);
void				check_duplicate(ssize_t numslen, int *nums);

// make_nodes.c
t_node				*make_nodes(ssize_t numslen, int *nums);
void				detele_everything(int *nums, t_node *stack);
void				delete_node(t_node *stack);
void				compress_nodes(t_node *stack, ssize_t numslen, int *nums);

//heap_sort.c
int					*heap_sort(int *nums, ssize_t numslen);
void				push_up(int *nums, ssize_t parent, ssize_t last);
int					*swap(int *nums, ssize_t first, ssize_t second);

// push_swap_utils
ssize_t				get_node_len(t_node *stack);
t_node				*get_lastnode(t_node *stack);

//sort operation
void				rotate_stack(t_node *stack);
void				reverse_rotate_stack(t_node *stack);
void				push_headnode(t_node *stack1, t_node *stack2);
void				swap_headnode(t_node *stack);
#endif
