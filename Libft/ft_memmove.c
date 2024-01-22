/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:25:39 by adbouras          #+#    #+#             */
/*   Updated: 2023/12/25 18:06:04 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_src;
	unsigned char	*p_dst;

	p_src = (unsigned char *) src;
	p_dst = (unsigned char *) dst;
	if (dst > src)
	{
		while (len > 0)
		{
			p_dst[len - 1] = p_src[len - 1];
			len--;
		}
		return (p_dst);
	}
	else
		return (ft_memcpy(p_dst, p_src, len));
}
