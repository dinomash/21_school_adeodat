/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeodat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:26:16 by adeodat           #+#    #+#             */
/*   Updated: 2021/11/17 18:35:49 by adeodat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num16_len(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_putpointer_base(unsigned long long int n, char c)
{
	int	i;

	i = ft_num16_len(n);
	if (n >= 16)
	{
		ft_putpointer_base(n / 16, c);
		n %= 16;
	}
	if (n > 9 && n < 16)
	{
		if (c == 'x' || c == 'p')
			ft_putchar((n % 10) + 97);
		else
			ft_putchar((n % 10) + 65);
	}
	else
		ft_putchar(n + 48);
	return (i);
}
