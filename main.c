/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/21 18:25:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

int	main(int argc, char *argv[])
{
	char		*input;
	t_array_lst	*array;
	t_ast		*tree;

	tree = init_ast();
	input = readline("Minishell >>: ");
	array = ft_init_array_lst();
	ft_init_lst_array(array, input);
	ft_scaner_type(array);
	ft_split_array_lst(array);
	ft_print_array_lst_simple(array);
	free(input);
	return (1);
}