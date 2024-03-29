/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcoes_temporarias.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:01:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/21 18:23:59 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

void	ft_print_array_lst(t_array_lst *array)
{
	t_a_nd		*c;
	int			i;
	int aspa;
	int	apos;

	apos = 0;
	aspa = 0;
	i = 0;
	c = array->head;
	printf("\n");
	while (i <= array->size)
	{
		if (c->type == DOUBLE_QUOTES || c->type == SINGLE_QUOTES)
		{
			if (c->type == DOUBLE_QUOTES)
			{
				printf("[content->[%c] type->[%d] ]\n", c->c, c->type);
				c = c->next;
				i++;
				while (c->type != DOUBLE_QUOTES)
				{
					if (i >= array->size)
						break ;
					printf("[content->[%c] type->[%d] ]\n", c->c, c->type);
					c = c->next;
					i++;
				}
			}
			if (c->type == SINGLE_QUOTES)
			{
				printf("[content->[%c] type->[%d] ]\n", c->c, c->type);
				c = c->next;
				i++;
				while (c->type != SINGLE_QUOTES)
				{
					if (i >= array->size)
						break ;
					printf("[content->[%c] type->[%d] ]\n", c->c, c->type);
					c = c->next;
					i++;
				}
			}
		}
		if (c->type != 11)
			printf("[%c]", c->c);
		if (c->type == 11 && aspa == 1)
			printf("[%c]", c->c);
		if (c->type == 11 && aspa == 0)
		{
			printf("%d", c->prev->type);
			printf("\n");
		}
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

void	ft_print_array_lst_simple(t_array_lst *array)
{
	t_a_nd		*c;
	int			i;

	c = array->head;
	i = 0;
	while (i != array->size)
	{
		printf("%c", c->c);
		c = c->next;
		i++;
	}
}