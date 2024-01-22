/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:50:47 by adbouras          #+#    #+#             */
/*   Updated: 2023/12/14 11:25:00 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*phr;

	phr = (unsigned char *) b;
	while (len > 0)
	{
		*phr = (unsigned char) c;
		phr++;
		len--;
	}
	return (b);
}
