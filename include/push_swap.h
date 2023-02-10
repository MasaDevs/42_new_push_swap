

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct i_node
{
	int				num;
	int				compressed_num;
    struct i_node   *before;
	struct i_node	*next;
}					t_node;
#endif
