/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:15:19 by afavier           #+#    #+#             */
/*   Updated: 2024/02/13 22:00:10 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

char	*read_buffer(int fd, char buffer[BUFFER_SIZE + 1])
{
	ssize_t	i;
	char	*new;

	i = 1;
	if (ft_strchr(buffer, '\n'))
		return (ft_strjoin_get(ft_strdup_gnl(""), buffer));
	new = ft_strdup_gnl(buffer);
	if (!new)
		return (free(new), NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || (i == 0 && buffer[0] == '\0'))
			return (free(new), ft_bzero(buffer, BUFFER_SIZE), NULL);
		if (i != 0)
		{
			buffer[i] = '\0';
			new = ft_strjoin_get(new, buffer);
			if (!new)
				return (free(new), NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (new);
}

int	new_buffer(char buffer[BUFFER_SIZE + 1])
{
	char	*new;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	new = ft_strdup_gnl(buffer);
	if (!new)
		return (free(new), -1);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[y])
		buffer[y++] = '\0';
	if (!ft_memcpy(buffer, (new + i), y - i))
		return (free(new), -1);
	free(new);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*ne;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024)
		return (NULL);
	ne = read_buffer(fd, buffer);
	if (!ne)
		return (free(ne), NULL);
	if (new_buffer(buffer) == -1)
		return (free(ne), NULL);
	return (ne);
}
