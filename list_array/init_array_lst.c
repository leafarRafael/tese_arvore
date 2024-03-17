/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:44:54 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/17 12:47:51 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

t_array_lst	*ft_init_array_lst(void)
{
	t_array_lst	*new_array;

	new_array = malloc(sizeof(t_array_lst));
	if (!new_array)
		return (NULL);
	new_array->size = 0;
	new_array->head = NULL;
	new_array->last = NULL;
	return (new_array);
}