/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:04:53 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/27 16:04:54 by okryzhan         ###   ########.fr       */
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
