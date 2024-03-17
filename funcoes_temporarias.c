/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcoes_temporarias.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:01:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/17 14:09:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

void	ft_print_array_lst(t_array_lst *array)
{
	t_a_nd		*c;
	int			i;

	i = 0;
	c = array->head;
	while (i != array->size)
	{
		printf("%c", c->c);
		c = c->next;
		i++;
	}
}

void ft_print_tree(t_ast *tree)
{
	int i;
	t_node *n;

	n = tree->head;
	i = 0;
	while (i != tree->size)
	{
		printf("%s\n", n->tokens);
		n = n->right;
		i++;
	}
}

void	ft_copy_argv_to_ast(t_ast *tree, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		ft_add_back(tree, argv[i]);
		i++;
	}
}


void	ft_init_lst_array(t_array_lst *array, char *input)
{
	int		i;
	char	**tokens;

	i = 0;
	while(input[i] != '\0')
	{
		ft_c_array_list_add_node(array, input[i]);
		i++;
	}
}
