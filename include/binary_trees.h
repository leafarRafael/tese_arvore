/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_trees.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/21 11:13:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "ft_printf.h"
# include "libft.h"
# include "string.h"
# include "key_words.h"

typedef struct	s_node
{
	char			*tokens;
	char			type;
	struct s_node	*left;
	struct s_node	*right;
}		t_node;

typedef struct	s_ast
{
	t_node	*head;
	t_node	*last;
	int		size;
}			t_ast;

typedef struct s_c_node
{
	char			c;
	int				i;
	int				type;
	struct s_c_node	*next;
	struct s_c_node	*prev;
}		t_a_nd;

typedef	struct s_array_lst
{
	t_a_nd	*head;
	t_a_nd	*last;
	int		size;
}		t_array_lst;

typedef struct s_variables
{
	t_a_nd	*temp_node;
	int		i;
	int		type_simple_char;
	int		type_multi_char;
	int		index_y;
	int		in_s_quotes;
	int		in_d_quotes;
	int		type;
}		t_v;

void		ft_add_back(t_ast *tree, char *token);
void		ft_del_node_front(t_array_lst *lst);
void		ft_c_array_list_add_node(t_array_lst *l_array, char c);
t_array_lst	*ft_init_array_lst(void);
t_ast		*init_ast(void);
void		ft_scaner_type(t_array_lst *array);
void		ft_split_array_lst(t_array_lst *array);

/*
		FUNÇÕES TEMPORARIAS DEBUG
*/

void	ft_print_array_lst(t_array_lst *array);
void	ft_print_tree(t_ast *tree);
void	ft_copy_argv_to_ast(t_ast *tree, char **argv);
void	ft_init_lst_array(t_array_lst *array, char *input);
void	ft_print_array_lst_simple(t_array_lst *array);

#endif
