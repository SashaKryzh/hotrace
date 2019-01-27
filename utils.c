/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:22:39 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/27 15:22:39 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t		get_hash(char *tag)
{
	size_t	hash;
	int		c;

	hash = 5381;
	while ((c = *tag++))
		hash = ((hash << 5) + hash) + c;
	hash %= TABLE_SIZE;
	return (hash);
}

t_item		*new_item(char *key, char *val)
{
	t_item *new;

	new = (t_item *)malloc(sizeof(t_item));
	new->key = ft_strdup(key);
	new->value = ft_strdup(val);
	new->next = NULL;
	return (new);
}

int			read_line(char *line)
{
	int ret;
	int	i;

	i = 0;
	while ((ret = read(0, &line[i], 1)) > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	line[i] = '\0';
	return (i || ret);
}
