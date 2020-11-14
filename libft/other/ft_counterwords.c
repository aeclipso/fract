/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterwords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:56:06 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/29 16:57:27 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_counterwords(char const *s, char c)
{
	size_t				quantity_words;
	size_t				iter_letter;

	quantity_words = 0;
	iter_letter = 0;
	if (!s)
		return (0);
	while (s[iter_letter])
	{
		if (s[iter_letter] != c && (s[iter_letter + 1] == c
		|| s[iter_letter + 1] == 0))
			quantity_words++;
		iter_letter++;
	}
	return (quantity_words);
}
