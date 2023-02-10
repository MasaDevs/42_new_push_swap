/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <masadevs@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:47:08 by marai             #+#    #+#             */
/*   Updated: 2023/02/10 18:15:40 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int *make_array(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int *nums;

    nums = make_array(argc, argv);
    
        
}

int *make_array(int argc, char *argv[])
{
    int *nums;

    if(argc == 1)
        exit(0);
    else
        nums = make_multi_array(argc, argv);
    
    check_duplicate();
}

int check_compose(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(ft_isdigit(str[i]) || ft_isspace(str[i]))

        i++;

    }
}

