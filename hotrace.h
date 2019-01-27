/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:03:53 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/26 14:03:54 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include "libft.h"

# define TABLE_SIZE 100000000

typedef struct		s_item
{
	char			*key;
	char			*value;
	struct s_item	*next;
}					t_item;

extern t_item		*g_tab;

/*
**	Parser
*/

int			get_data(void);
int			read_line(char *line);

t_item		*new_item(char *key, char *val);

/*
**	Search
*/

size_t		get_hash(char *tag);

/*
**	Put funcs
*/

void		m_putstr(char *s);
void		show_res(char *keyword, char *value);

#endif
