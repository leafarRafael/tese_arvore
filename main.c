/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/19 11:28:26 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_trees.h"

int		ft_type_of_operator(char c);
void	ft_scaner_type(t_array_lst *arrey);
int		ft_type_of_operator_com(char c, char n_c);

int	main(int argc, char *argv[])
{
	char		*input;
	t_array_lst	*array;
	t_ast		*tree;

	tree = init_ast();
	input = readline("Minishell >>:");
	array = ft_init_array_lst();
	ft_copy_argv_to_ast(tree, argv);
	ft_print_tree(tree);
	printf("\n");
	ft_init_lst_array(array, input);
	ft_scaner_type(array);
	ft_print_array_lst(array);
	free(input);
	return (1);
}

void	ft_scaner_type(t_array_lst *array)
{
	int	i;
	int simple_type;
	int	comp_type;
	t_a_nd *c;

	c = array->head;
	i = 0;
	while (i != array->size)
	{
		simple_type = 0;
		simple_type = ft_type_of_operator(c->c);
		c->type = simple_type;
		comp_type = 0;
		comp_type = ft_type_of_operator_com(c->c, c->next->c);
		if (comp_type != 0)
		{
			c->type = comp_type;
			c->next->type = comp_type;
			c = c->next;
		}
		c = c->next;
		i++;
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