/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:29:08 by adbouras          #+#    #+#             */
/*   Updated: 2023/12/20 17:55:10 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	return (sign);
}

static int	ft_nlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_rev_swap(char *str)
{
	char	swap;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;
	int		i;
	long	long_n;

	long_n = n;
	if (long_n < 0)
		long_n = long_n * (-1);
	sign = ft_sign(n);
	len = ft_nlen(long_n);
	str = ft_calloc((len + sign + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (long_n > 0)
	{
		str[i++] = long_n % 10 + '0';
		long_n = long_n / 10;
	}
	if (sign == 1)
		str[i] = '-';
	if (i == 0)
		str[i] = '0';
	return (ft_rev_swap(str));
}
