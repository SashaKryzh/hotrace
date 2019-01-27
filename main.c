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

t_item	*g_tab;

int		g_cnt;

void	search_engine(void)
{
	char		line[1024];
	size_t		hash;
	t_item		*tmp;

	while (read_line(line))
	{
		hash = get_hash(line);
		tmp = &g_tab[hash];
		while (tmp && tmp->value)
		{
			if (!ft_strcmp(tmp->key, line))
			{
				show_res(NULL, tmp->value);
				break ;
			}
			if (tmp->next)
				g_cnt++;
			tmp = tmp->next;
		}
		if (!tmp || !tmp->value)
			show_res(line, NULL);
	}
}

int		main(void)
{
	if (!(g_tab = (t_item *)malloc(sizeof(t_item) * TABLE_SIZE)))
		return (1);
	if (get_data())
		search_engine();
	else
	{
		m_putstr("No value after tag\n");
		return (1);
	}
	// ft_printf("%d\n", g_cnt);
	// system("leaks hotrace");
	return (0);
}
