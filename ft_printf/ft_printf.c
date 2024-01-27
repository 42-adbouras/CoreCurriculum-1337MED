/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:40:07 by adbouras          #+#    #+#             */
/*   Updated: 2024/01/16 16:41:54 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char input, va_list arg)
{
	int	count;

	count = 0;
	if (input == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (input == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (input == 'd' || input == 'i')
		count += ft_putnbr((long)va_arg(arg, int), 10, input);
	else if (input == 'u')
		count += ft_putnbr((long)va_arg(arg, unsigned int), 10, input);
	else if (input == 'x' || input == 'X')
		count += ft_putnbr((long)va_arg(arg, unsigned int), 16, input);
	else if (input == 'p')
		count += ft_hex_addr(va_arg(arg, void *));
	else if (input == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(input);
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		count;
	int		i;

	if (write(1, "", 0) == -1)
		return (-1);
	count = 0;
	i = 0;
	va_start(arg, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%' && input[i + 1] != '\0')
			count += ft_format(input[++i], arg);
		else if (input[i] != '%')
			count += ft_putchar(input[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
