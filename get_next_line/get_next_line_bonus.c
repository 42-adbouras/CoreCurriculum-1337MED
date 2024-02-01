/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:33:19 by adbouras          #+#    #+#             */
/*   Updated: 2024/01/30 13:18:55 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *line, int fd);
char	*ft_substr_ft(char *line);
char	*ft_save_static(char *line);

char	*get_next_line(int fd)
{
	static char	*line[10240];
	char		*sub_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	line[fd] = ft_read(line[fd], fd); 
	if (line[fd] == NULL || line[fd][0] == '\0')
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	sub_line = ft_substr_ft(line[fd]);
	line[fd] = ft_save_static(line[fd]);
	return (sub_line);
}

char	*ft_read(char *line, int fd)
{
	char	*cup;
	int		bytes;

	bytes = 1;
	cup = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!cup)
		return (NULL);
	while (bytes != 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, cup, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (cup);
			free (line);
			line = NULL;
			return (NULL);
		}
		cup[bytes] = '\0';
		line = ft_strjoin(line, cup);
	}
	free (cup);
	return (line);
}

char	*ft_substr_ft(char *line)
{
	int		i;
	char	*sub;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!ft_strchr(line, '\n'))
		sub = malloc((i + 1) * sizeof(char));
	else
		sub = malloc((i + 2) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		sub[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		sub[i] = line[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_save_static(char *line)
{
	char	*save;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (free(line), NULL);
	save = malloc((ft_strlen(line) - i) * sizeof(char));
	if (!save)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		save[j++] = line[i++];
	save[j] = '\0';
	free (line);
	return (save);
}
