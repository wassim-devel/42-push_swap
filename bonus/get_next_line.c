/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:50:56 by goat              #+#    #+#             */
/*   Updated: 2023/11/22 17:22:08 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*to_return;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
	to_return = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!to_return)
		return (NULL);
	i = -1;
	j = 0;
	while (str1[++i] != '\0')
		to_return[i] = str1[i];
	free(str1);
	while (str2[j] != '\0')
		to_return[i++] = str2[j++];
	to_return[i] = '\0';
	return (to_return);
}

char	*remove_next_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_line = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_line)
		return (NULL);
	while (stash[i + 1] != '\0')
	{
		new_line[j] = stash[i + 1];
		i++;
		j++;
	}
	new_line[j] = '\0';
	free(stash);
	return (new_line);
}

char	*get_linea(char *stash)
{
	int		i;
	char	*to_return;

	i = 0;
	if (!stash[0])
		return (NULL);
	to_return = malloc(sizeof(char) * (ft_strlen_to_char(stash, '\n') + 2));
	if (!to_return)
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
	{
		to_return[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		to_return[i] = '\n';
		to_return[i + 1] = '\0';
	}
	else
		to_return[i] = '\0';
	return (to_return);
}

char	*find_next_line(char *buffer, char *stash, int fd)
{
	int	read_number;

	read_number = 1;
	while (search_char(stash, '\n') == 0 && read_number != 0)
	{
		read_number = read(fd, buffer, BUFFER_SIZE);
		if (read_number == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[read_number] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*to_return;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	stash = find_next_line(buffer, stash, fd);
	if (!stash)
		return (NULL);
	free(buffer);
	to_return = get_linea(stash);
	stash = remove_next_line(stash);
	return (to_return);
}
