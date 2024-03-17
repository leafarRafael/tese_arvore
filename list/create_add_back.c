/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:37:31 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/17 12:53:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

static void ft_add_first(t_ast *tree, char *token);
static void ft_add_second(t_ast *tree, char *token);
static void ft_add_third_onwards(t_ast *tree, char *token);

void	ft_add_back(t_ast *tree, char *token)
{
	if (!tree)
		return ;
	if (!token)
		return ;
	if (tree->size == 0)
		ft_add_first(tree, token);
	else if (tree->size == 1)
		ft_add_second(tree, token);
	else
		ft_add_third_onwards(tree, token);
}

static void ft_add_first(t_ast *tree, char *token)
{
	t_node *new_n;

	new_n = malloc(sizeof(t_node));
	if (!new_n)
		return ;
	new_n->tokens = token;
	new_n->left = new_n;
	new_n->right = new_n;
	tree->head = new_n;
	tree->last = new_n;
	tree->size++;
}

static void ft_add_second(t_ast *tree, char *token)
{
	t_node *new_n;

	new_n = malloc(sizeof(t_node));
	if (!new_n)
		return ;
	new_n->tokens = token;
	new_n->right = tree->head;
	new_n->left = tree->head;
	tree->head->right = new_n;
	tree->head->left = new_n;
	tree->last = new_n;
	tree->size++;
}

static void ft_add_third_onwards(t_ast *tree, char *token)
{
	t_node *new_n;
	t_node *last;

	new_n = malloc(sizeof(t_node));
	if (!new_n)
		return ;
	new_n->tokens = token;
	last = tree->last;
	tree->head->left = new_n;
	last->right = new_n;
	new_n->left = last;
	new_n->right = tree->head;
	tree->last = new_n;
	tree->size++;
}
