/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:32:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/21 18:26:00 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

static void	ft_count_helper(t_a_nd *n, int *in_sing_q, int *in_doub_q);
static int	ft_count_words(t_array_lst *array);
static int	ft_size_new_array(t_array_lst *array);
char		*ft_cpy_lst_str(t_array_lst *array);
static void clean_white(t_array_lst *array);


void	ft_split_array_lst(t_array_lst *array)
{
	t_v		v;
	char	**matrix;

	if (!array)
		return ;
	v.temp_node = array->head;
	v.index_y = ft_count_words(array);
	matrix = ft_calloc(sizeof(char *), v.index_y +1);
	v.i = 0;
	while (v.i != v.index_y )
	{
		matrix[v.i] = ft_cpy_lst_str(array);
		v.i++;
	}
}

int	ft_count_words(t_array_lst *array)
{
	t_v	v;

	v.i = 1;
	v.index_y = 1;
	v.in_d_quotes = 0;
	v.in_s_quotes = 0;
	v.temp_node = array->head;
	while (v.temp_node->type == WHITE_SPACE)
	{
		v.temp_node = v.temp_node->next;
		v.i++;
	}
	while (v.i <= array->size)
	{
		if (v.temp_node->type == DOUBLE_QUOTES || v.temp_node->type == SINGLE_QUOTES)
			ft_count_helper(v.temp_node, &v.in_d_quotes, &v.in_s_quotes);
		if (v.temp_node->type == WHITE_SPACE && v.temp_node->next->type != WHITE_SPACE && v.temp_node->next != array->head)
			if (v.in_s_quotes == 0 && v.in_d_quotes == 0)
				v.index_y++;
		v.temp_node = v.temp_node->next;
		v.i++;
	}
	return (v.index_y);
}

static void	ft_count_helper(t_a_nd *n, int *in_sing_q, int *in_doub_q)
{
	if (n->type == DOUBLE_QUOTES && (*in_doub_q) == 0)
	{
		if ((*in_sing_q) == 1)
			(*in_sing_q)--;
		else
			(*in_sing_q)++;
	}
	if (n->type == SINGLE_QUOTES && (*in_sing_q) == 0)
	{
		if ((*in_doub_q) == 1)
			(*in_doub_q)--;
		else
			(*in_doub_q)++;
	}
}

char	*ft_cpy_lst_str(t_array_lst *array)
{
	t_v		v;
	char	*str;
	int		size;
	t_a_nd	*first;
	t_a_nd	*second;

	if (!array || !array->head)
	{
		str = ft_calloc(sizeof(char), 1);
		return (str);
	}
	size = ft_size_new_array(array);
	str = ft_calloc(sizeof(char), size+1);
	clean_white(array);
	return (str);
}

static int	ft_size_new_array(t_array_lst *array)
{
	t_v	v;

	v.type = 0;
	v.i = 0;
	v.temp_node = array->head;
	while (v.temp_node->type == WHITE_SPACE)
		v.temp_node = v.temp_node->next;
	if (v.temp_node->type == SINGLE_QUOTES)
	{
		v.temp_node = v.temp_node->next;
		v.i++;
		while (v.temp_node->type != SINGLE_QUOTES)
		{
			v.temp_node = v.temp_node->next;
			v.i++;
		}
		return (v.i);
	}
	if (v.temp_node->type == DOUBLE_QUOTES)
	{
		v.temp_node = v.temp_node->next;
		v.i++;
		while (v.temp_node->type != DOUBLE_QUOTES)
		{
			v.temp_node = v.temp_node->next;
			v.i++;
		}
		return (v.i);
	}
	v.type = v.temp_node->type;
	while (v.temp_node->type == v.type && v.i <= array->size)
	{
		v.temp_node = v.temp_node->next;
		v.i++;
	}
	return (v.i);
}

static void clean_white(t_array_lst *array)
{
	t_a_nd	*first;
	t_a_nd	*second;

	first = array->head;
	second = first->next;
	while (first->type == WHITE_SPACE)
	{
		second->prev = array->last;
		array->last->next = second;
		array->head = second;
		free(first);
		first = second;
		second = second->next;
	}
}