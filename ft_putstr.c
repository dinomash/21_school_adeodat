/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeodat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:24:19 by adeodat           #+#    #+#             */
/*   Updated: 2021/11/17 18:25:35 by adeodat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	int	t;

	t = 0;
	while (str[t] != '\0')
		t++;
	return (t);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	write(1, s, ft_strlen(s));
	count += ft_strlen(s);
	return (count);
}
