/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaner_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:23:56 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/20 13:11:09 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

void	ft_scaner_type(t_array_lst *array)
{
	t_v	v;

	v.temp_node = array->head;
	v.i = 0;
	while (v.i != array->size)
	{
		v.type_simple_char = 0;
		v.type_multi_char = 0;
		v.type_simple_char = ft_type_of_operator(v.temp_node->c);
		v.temp_node->type = v.type_simple_char;
		if (v.temp_node->next != array->head)
			v.type_multi_char = ft_type_of_operator_com(v.temp_node->c, v.temp_node->next->c);
		if (v.type_multi_char != 0)
		{
			v.temp_node->type = v.type_multi_char;
			v.temp_node->next->type = v.type_multi_char;
			v.temp_node = v.temp_node->next;
		}
		v.temp_node = v.temp_node->next;
		v.i++;
	}
}

int	ft_type_of_operator(char c)
{
	if (c == _PIPE_)
		return (PIPE);
	if (c == _REDI_IN_)
		return (REDI_IN);
	if (c == _REDI_OUT_)
		return (REDI_OUT);
	if (c == _SINGLE_QUOTES_)
		return (SINGLE_QUOTES);
	if (c == _DOUBLE_QUOTES_)
		return (DOUBLE_QUOTES);
	if (c == _DOLLAR_SING_)
		return (DOLLAR_SING);
	if (_WHITE_SPACE_(c))
		return (WHITE_SPACE);
	return (0);	
}

int	ft_type_of_operator_com(char c, char n_c)
{
	if (_REDI_OUT_APEND_(c, n_c))
		return (REDI_OUT_APEND);
	if (_HERE_DOC_(c, n_c))
		return (HERE_DOC);
	if (_OR_(c, n_c))
		return (OR);
	if (_AND_(c, n_c))
		return (AND);
	return (0);	
}
