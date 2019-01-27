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

t_item	*new_item(char *key, char *val)
{
	t_item *new;

	new = (t_item *)malloc(sizeof(t_item));
	new->key = ft_strdup(key);
	new->value = ft_strdup(val);
	new->next = NULL;
	return (new);
}

void	add_item(char *key, char *val)
{
	t_item		*tmp;
	size_t		hash;

	hash = get_hash(key);
	if (!g_tab[hash].value)
	{
		g_tab[hash].key = ft_strdup(key);
		g_tab[hash].value = ft_strdup(val);
	}
	else
	{
		tmp = &g_tab[hash];
		while (tmp && tmp->value)
		{
			if (!ft_strcmp(tmp->key, key))
			{
				free(tmp->value);
				tmp->value = ft_strdup(val);
				return ;
			}
			if (!tmp->next)
			{
				tmp->next = new_item(key, val);
				return ;
			}
			tmp = tmp->next;
		}
	}
}

int		read_line(char *line)
{
	int ret;
	int	i;

	i = 0;
	while ((ret = read(0, &line[i], 1)) > 0)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
	line[i] = '\0';
	return (i || ret);
}

int		get_data(void)
{
	char	item[2][1024];

	while (read_line(item[0]))
	{
		if (!**item)
			break ;
		if (read_line(item[1]))
			add_item(item[0], item[1]);
		else
			return (0);
	}
	return (1);
}
