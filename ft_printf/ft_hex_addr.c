/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:08:54 by adbouras          #+#    #+#             */
/*   Updated: 2024/01/14 15:15:00 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long x)
{
	int		count;
	char	*symb;

	count = 0;
	symb = "0123456789abcdef";
	if (x < 16)
		count += ft_putchar(symb[x]);
	else
	{
		count += ft_put_hex(x / 16);
		count += ft_put_hex(x % 16);
	}
	return (count);
}

int	ft_hex_addr(void *s)
{
	int				count;
	unsigned long	x;

	count = 0;
	x = (unsigned long) s;
	count += ft_putstr("0x");
	count += ft_put_hex(x);
	return (count);
}
