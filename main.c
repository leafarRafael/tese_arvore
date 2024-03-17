/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/17 15:40:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

int	main(int argc, char *argv[])
{
	char		*input;
	t_array_lst	*array;
	t_ast		*tree;

	tree = init_ast();
	input = readline("Minishell >>:");
	array = ft_init_array_lst();
	ft_copy_argv_to_ast(tree, argv);
	ft_print_tree(tree);
	printf("\n");
	ft_init_lst_array(array, input);
	ft_print_array_lst(array);
	free(input);
	return (1);
}
