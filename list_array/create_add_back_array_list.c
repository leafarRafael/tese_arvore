/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_add_back_array_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:17:46 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/17 11:27:29 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

static void ft_first_node(t_array_lst *l_array, char c);
static void ft_second_node(t_array_lst *l_array, char c);
static void ft_third_onwards_node(t_array_lst *l_array, char c);

void	ft_c_array_list_add_node(t_array_lst *l_array, char c)
{
	t_a_nd	*new_c;
	t_a_nd	*temp;

	if (!l_array)
		return ;
	new_c = malloc(sizeof(t_a_nd));
	if (!new_c)
		return ;
	new_c->c = c;
	if (l_array->size == 0)
		ft_first_node(l_array, c);
	else if (l_array->size == 1)
		ft_second_node(l_array, c);
	else
		ft_third_onwards_node(l_array, c);
}

static void ft_first_node(t_array_lst *l_array, char c)
{
	t_a_nd	*new_c;

	new_c = malloc(sizeof(t_a_nd));
	new_c->c = c;
	l_array->head = new_c;
	l_array->last = new_c;
	new_c->next = new_c;
	new_c->prev = new_c;
	new_c->i = l_array->size;
	l_array->size++;
}

static void ft_second_node(t_array_lst *l_array, char c)
{
	t_a_nd	*new_c;

	new_c = malloc(sizeof(t_a_nd));
	new_c->c = c;
	l_array->last = new_c;
	new_c->next = l_array->head;
	new_c->prev = l_array->head;
	l_array->head->next = new_c;
	l_array->head->prev = new_c;
	new_c->i = l_array->size;
	l_array->size++;
}

static void ft_third_onwards_node(t_array_lst *l_array, char c)
{
	t_a_nd	*new_c;
	t_a_nd	*temp;

	new_c = malloc(sizeof(t_a_nd));
	new_c->c = c;
	temp = l_array->last;
	new_c->next = l_array->head;
	new_c->prev = temp;
	temp->next = new_c;
	l_array->head->prev = new_c;
	new_c->i = l_array->size;
	l_array->size++;
	l_array->last = new_c;
}
