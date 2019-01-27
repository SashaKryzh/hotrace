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

t_item		*new_item(char *key, char *val)
{
	t_item *new;

	if (!(new = (t_item *)malloc(sizeof(t_item))))
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(val);
	if (!new->key || !new->value)
		return (NULL);
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
