/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:58:55 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/03 21:13:32 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

char	*ft_leak(char *buffer, char *str)
{
	char	*tmp;

	tmp = buffer;
	buffer = ft_strjoin(tmp, str);
	if (!buffer)
		return (free(tmp), NULL);
	free(tmp);
	return (buffer);
}

char	*read_bytes(int fd, char *buffer)
{
	char	*str;
	int		n;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (free(buffer), NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n < 0)
			return (free(str), free(buffer), NULL);
		str[n] = '\0';
		buffer = ft_leak(buffer, str);
		if (!buffer)
			return (free(str), NULL);
		if (ft_strchr(str, '\n') != NULL)
			break ;
	}
	return (free(str), buffer);
}

char	*get_lline(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		line = ft_calloc(i + 1, 1);
	else
		line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_leftovers(char *buffer)
{
	int		start;
	int		i;
	int		len;
	char	*next;

	if (!buffer)
		return (NULL);
	start = 0;
	while (buffer[start] && buffer[start] != '\n')
		start++;
	if (buffer[start] == '\n')
		start++;
	if (buffer[start] == '\0')
		return (free(buffer), NULL);
	len = ft_strlen(buffer + start);
	next = ft_calloc(len + 1, 1);
	if (!next)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[start])
		next[i++] = buffer[start++];
	next[i] = 0;
	return (free(buffer), next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = read_bytes(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_lline(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = get_leftovers(buffer);
	return (line);
}
