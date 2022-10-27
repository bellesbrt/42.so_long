/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:46:52 by inicole-          #+#    #+#             */
/*   Updated: 2022/10/24 18:21:35 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	assist_cat(size_t x, char *dest, char *src)
{
	size_t	y;

	y = 0;
	while (src[y])
		dest[x++] = src[y++];
	return (x);
}

static char	*ft_strcat(char *s1, char *s2)
{
	char	*reciver;
	size_t	i;

	i = 0;
	if (!s1)
	{
		s1 = malloc (sizeof(char) * 1);
		s1[i] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	reciver = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!reciver)
		return (NULL);
	i = assist_cat (i, reciver, s1);
	assist_cat (i, reciver, s2);
	reciver[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free (s1);
	return (reciver);
}

char	*get_all_lines(int fd, char *s)
{
	int		read_bytes;
	char	*read_chars;

	read_chars = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_chars)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read (fd, read_chars, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (read_chars);
			return (NULL);
		}
		read_chars[read_bytes] = '\0';
		s = ft_strcat(s, read_chars);
	}
	free (read_chars);
	return (s);
}
