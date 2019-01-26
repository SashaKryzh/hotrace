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

# define TABLE_SIZE 1000000

typedef struct		s_item
{
	char			*key;
	char			*value;
	struct s_item	*next;
}					t_item;

void		add_item(char **item);

void	show_res(char *keyword, char *value);

#endif
