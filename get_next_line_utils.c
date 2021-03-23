/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meunostu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:54:00 by meunostu          #+#    #+#             */
/*   Updated: 2020/12/06 18:56:04 by meunostu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	size_t	ft_strlen(const char *str)
{
	size_t		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char			*ft_strjoin(char *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*cat_s;
	char		*start_s1;
	char		*start_cat_s;

	if (!s2)
		return (NULL);
	len_s1 = !s1 ? 0 : ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(cat_s = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	start_cat_s = cat_s;
	start_s1 = s1;
	while (s1 && *s1)
		*cat_s++ = *s1++;
	while (s2 && *s2)
		*cat_s++ = *s2++;
	*cat_s = '\0';
	free(start_s1);
	return (start_cat_s);
}

char			*ft_strchr(const char *s, int c)
{
	size_t		len;
	char		*str;

	if (!s || *s == '\0')
		return (NULL);
	str = (char *)s;
	len = ft_strlen(str) + 1;
	while (len--)
		if (*str++ == c)
			return (str - 1);
	return (NULL);
}

char			*ft_strdup(const char *str)
{
	char		*dest;
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
