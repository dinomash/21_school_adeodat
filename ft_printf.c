/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeodat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:24:08 by adeodat           #+#    #+#             */
/*   Updated: 2021/11/16 20:27:08 by adeodat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arg_checker(char s, va_list ap)
{
	int	i;

	i = 0;
	if (s == 'd' || s == 'i')
		i += ft_putnbr_10(va_arg(ap, int));
	if (s == 's')
		i += ft_putstr(va_arg(ap, char *));
	if (s == 'c')
		i += ft_putchar(va_arg(ap, int));
	if (s == 'u')
		i += ft_putnbr_u(va_arg(ap, unsigned int));
	if (s == 'p')
	{
		write(1, "0x", 2);
		i += ft_putpointer_base(va_arg(ap, unsigned long long int), s) + 2;
	}
	if (s == 'x' || s == 'X')
		i += ft_putpointer_base(va_arg(ap, unsigned int), s);
	if (s == '%')
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += ft_arg_checker(str[i], ap);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
