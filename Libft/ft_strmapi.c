/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:56:00 by adbouras          #+#    #+#             */
/*   Updated: 2023/12/28 10:40:11 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*p_s;

	i = 0;
	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	p_s = malloc ((ft_strlen(s) + 1) * sizeof(char));
	if (p_s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p_s[i] = f(i, s[i]);
		i++;
	}
	p_s[i] = '\0';
	return (p_s);
}
