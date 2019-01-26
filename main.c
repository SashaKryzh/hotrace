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
			// add_item(item);
			free(item[1]);
		}
		free(item[0]);
	}
	return (ret);
}

int		main(void)
{
	if (get_data() > 0)
	{
		ft_putendl("GOOD");
	}
	system("leaks hotrace");
	return (0);
}
