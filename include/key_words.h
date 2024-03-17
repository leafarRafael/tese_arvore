/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_words.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:39:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/17 15:01:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_WORDS_H
# define KEY_WORDS_H

# define _PIPE_ '|'
# define PIPE (1 << 0)

# define _REDI_IN_ '<'
# define REDI_IN (1 << 1)

# define _REDI_OUT_ '>'
# define REDI_OUT (1 << 2)

# define _REDI_OUT_APEND_ ">>"
# define REDI_OUT_APEND (1 << 3)

# define _HERE_DOC_ "<<"
# define HERE_DOC (1 << 4)

# define _SINGLE_QUOTES_ '\''
# define SINGLE_QUOTES (1 << 5)

# define _DOUBLE_QUOTES_ '"'
# define DOUBLE_QUOTES (1 << 6)

# define _DOLLAR_SING_ '$'
# define DOLLAR_SING (1 << 7)

# define _OR_ "||"
# define OR (1 << 8)

# define _AND_ "&&"
# define AND (1 << 9)

#endif