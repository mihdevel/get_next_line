/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meunostu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:53:26 by meunostu          #+#    #+#             */
/*   Updated: 2020/12/06 19:31:03 by meunostu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*before_n(char *cache)
{
	char		*dst;
	size_t		i;

	i = 0;
	while (cache && cache[i] && cache[i] != '\n')
		i++;
	if (!(dst = malloc(i + 1)))
		return (NULL);
	dst[i] = '\0';
	while (i--)
		dst[i] = cache[i];
	return (dst);
}

static	char	*after_n(char *cache)
{
	char		*p_n;
	char		*dst;

	if (!cache || !*cache || !(p_n = ft_strchr(cache, '\n')))
	{
		free(cache);
		return (NULL);
	}
	dst = ft_strdup(p_n + 1);
	free(cache);
	return (dst);
}

int				get_next_line(int fd, char **line)
{
	static char	*cache;
	char		*buf;
	int			readed;

	readed = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, NULL, 0) == -1)
	|| !(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(cache, '\n') && (readed = read(fd, buf, BUFFER_SIZE)))
	{
		if (readed < 0)
		{
			free(buf);
			free(cache);
			return (-1);
		}
		buf[readed] = '\0';
		if (!(cache = ft_strjoin(cache, buf)))
			return (-1);
	}
	free(buf);
	if (!(*line = before_n(cache)))
		return (-1);
	cache = after_n(cache);
	return (readed == 0 ? 0 : 1);
}
