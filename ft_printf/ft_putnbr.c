/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:52:01 by adbouras          #+#    #+#             */
/*   Updated: 2024/01/14 16:03:49 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base, char s)
{
	int		count;
	char	*symb;

	count = 0;
	if (s == 'x')
		symb = "0123456789abcdef";
	else
		symb = "0123456789ABCDEF";
	if (n < 0)
	{
		count += write (1, "-", 1);
		count += ft_putnbr(-n, base, s);
	}
	else if (n < base)
		count += ft_putchar(symb[n]);
	else
	{
		count += ft_putnbr(n / base, base, s);
		count += ft_putnbr(n % base, base, s);
	}
	return (count);
}
