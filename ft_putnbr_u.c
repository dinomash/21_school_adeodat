/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeodat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:29:40 by adeodat           #+#    #+#             */
/*   Updated: 2021/11/17 18:31:53 by adeodat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	char	r;
	int		i;

	i = ft_numlen(n);
	if (n >= 10)
	{
		ft_putnbr_u (n / 10);
	}
	r = n % 10 + '0';
	ft_putchar(r);
	return (i);
}
