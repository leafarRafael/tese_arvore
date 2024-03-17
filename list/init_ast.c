/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:50:43 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/17 12:52:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

t_ast	*init_ast(void)
{
	t_ast	*new_tree;

	new_tree = malloc(sizeof(t_ast));
	if (!new_tree)
		return (NULL);
	new_tree->size = 0;
	new_tree->head = NULL;
	new_tree->last = NULL;
	return (new_tree);
}