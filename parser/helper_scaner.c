/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_scaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:24:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/20 11:25:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

int	is_white_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int	is_hero_doc(char c, char n_c)
{
	return (c == '<' && n_c == '<');
}

int	is_redirect_apend(char c, char n_c)
{
	return (c == '>' && n_c == '>');
}

int	is_or(char c, char n_c)
{
	return (c == '|' && n_c == '|');
}

int	is_and(char c, char n_c)
{
	return (c == '&' && n_c == '&');
}