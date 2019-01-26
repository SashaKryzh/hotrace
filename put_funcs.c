/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:07:38 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/26 17:07:38 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	m_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	show_res(char *keyword, char *value)
{
	if (!value)
	{
		m_putstr(keyword);
		m_putstr(": Not found.\n");
	}
	else
	{
		m_putstr(value);
		write(1, "\n", 1);
	}
}
