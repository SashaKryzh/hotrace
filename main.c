/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:03:43 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/26 14:03:44 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_item	g_tab[TABLE_SIZE];

int		get_data(void)
{
	char	*item[2];
	int		ret;

	ret = 1;
	while (ret == 1 && get_next_line(0, &item[0]))
	{
		if (!item[0][0])
			ret = 2;
		if (ret == 1 && get_next_line(0, &item[1]))
		{
			if (!item[1][0])
				ret = -1;
			add_item(item);
		}
	}
	free(item[0]);
	return (ret);
}

int		get_hash(char *tag)
{
	int hash;
	int	i;

	i = 0;
	hash = 0;
	while (tag[i])
	{
		hash += tag[i] - 'a';
		i++;
	}
	if (hash < 0)
		hash = hash * -1;
	return (hash % TABLE_SIZE);
}

t_item	*new_item(char **item)
{
	t_item *new;

	new = (t_item *)malloc(sizeof(t_item));
	new->key = item[0];
	new->value = item[1];
	new->next = NULL;
	return (new);
}

void	add_item(char **item)
{
	t_item	*tmp;
	int		hash;

	hash = get_hash(item[0]);
	if (!g_tab[hash].value)
	{
		g_tab[hash].key = item[0];
		g_tab[hash].value = item[1];
	}
	else
	{
		tmp = &g_tab[hash];
		while (tmp->value)
		{
			if (!ft_strcmp(tmp->key, item[0]))
			{
				free(tmp->value);
				tmp->key = item[1];
				return ;
			}
			if (!tmp->next)
			{
				tmp->next = new_item(item);
				return ;
			}
			tmp = tmp->next;
		}
	}
}

void	search_engine(void)
{
	char	*line;
	int		hash;
	t_item	*tmp;

	while (get_next_line(0, &line))
	{
		hash = get_hash(line);
		tmp = &g_tab[hash];
		while (tmp->value)
		{
			if (!ft_strcmp(tmp->key, line))
			{
				show_res(NULL, tmp->value);
				break ;
			}
			tmp = tmp->next;
		}
		if (!tmp || !tmp->value)
			show_res(line, NULL);
		free(line);
	}
}

int		main(void)
{
	if (get_data() > 0)
	{
		search_engine();
	}
	return (0);
}
