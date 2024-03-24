/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:39:40 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/21 12:34:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

void	ft_del_node_front(t_array_lst *lst)
{
	t_a_nd *first;
	t_a_nd *second;

	if (!lst)
		return ;
	if (!lst->head)
		return ;
	if (!lst->last)
		return ;
	first = lst->head;
	second = lst->head->next;
	second->prev = lst->last;
	lst->last->next = second;
	lst->head = second;
	lst->size--;
	free(first);
}
