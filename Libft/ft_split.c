/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:37:11 by adbouras          #+#    #+#             */
/*   Updated: 2023/12/27 09:29:35 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	word_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if ((s[i + 1] == c || s[i + 1] == '\0'))
				count++;
			i++;
		}
	}
	return (count);
}

static void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}

static	char	**ft_write(char **array, char const *s, char c, int n)
{
	int	i;
	int	line;
	int	old_i;

	i = 0;
	line = 0;
	while (s[i] != '\0' && line < n)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		old_i = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		array[line] = ft_substr(s, old_i, i - old_i);
		if (!array[line])
		{
			ft_free(array);
			return (NULL);
		}
		line++;
	}
	array[line] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_write(array, s, c, words);
	return (array);
}
