/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_words.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:39:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/20 13:12:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_WORDS_H
# define KEY_WORDS_H

# define _PIPE_ '|'
# define _REDI_IN_ '<'
# define _REDI_OUT_ '>'
# define _SINGLE_QUOTES_ '\''
# define _DOUBLE_QUOTES_ '"'
# define _DOLLAR_SING_ '$'

# define _REDI_OUT_APEND_ is_redirect_apend
# define _HERE_DOC_ is_hero_doc
# define _OR_ is_or
# define _AND_ is_and
# define _WHITE_SPACE_ is_white_space

typedef enum s_type
{
    PIPE = 1,
    REDI_IN,
    REDI_OUT,
    REDI_OUT_APEND,
    HERE_DOC,
    SINGLE_QUOTES,
    DOUBLE_QUOTES,
    DOLLAR_SING,
    OR,
    AND,
    WHITE_SPACE

}       t_type;

int is_white_space(char c);
int is_hero_doc(char c, char n_c);
int is_redirect_apend(char c, char n_c);
int is_or(char c, char n_c);
int is_and(char c, char n_c);
int ft_type_of_operator(char c);
int ft_type_of_operator_com(char c, char n_c);

#endif