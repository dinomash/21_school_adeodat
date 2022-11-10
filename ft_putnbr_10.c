/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeodat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:17:32 by adeodat           #+#    #+#             */
/*   Updated: 2021/11/16 20:23:51 by adeodat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_10(int n)
{
	char	r;
	int		i;

	i = ft_numlen(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_10 (n / 10);
	}
	r = n % 10 + '0';
	ft_putchar(r);
	return (i);
}
