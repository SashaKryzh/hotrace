/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:50:41 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/27 11:50:41 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		insert(t_item *tmp, char *key, char *val)
{
	while (tmp && tmp->value)
	{
		if (!ft_strcmp(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(val);
			return (tmp->value ? 1 : 0);
		}
		if (!tmp->next)
		{
			tmp->next = new_item(key, val);
			return (tmp->next ? 1 : 0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int		add_item(char *key, char *val)
{
	t_item		*tmp;
	size_t		hash;

	hash = get_hash(key);
	if (!g_tab[hash].value)
	{
		g_tab[hash].key = ft_strdup(key);
		g_tab[hash].value = ft_strdup(val);
		if (!g_tab[hash].key || !g_tab[hash].value)
			return (0);
	}
	else
	{
		tmp = &g_tab[hash];
		return (insert(tmp, key, val));
	}
	return (1);
}

int		get_data(void)
{
	char	item[2][1024];

	while (read_line(item[0]))
	{
		if (!**item)
			break ;
		if (read_line(item[1]))
		{
			if (!item[1][0])
				return (0);
			if (!(add_item(item[0], item[1])))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
