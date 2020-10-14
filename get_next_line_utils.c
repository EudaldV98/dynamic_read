/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:23:22 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/14 15:15:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] && str[count] != '\n')
	{
		count++;
	}
	return (count);
}

char    *ft_strcpy(char *dest, char *src)
{
    unsigned int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}

char			*ft_strjoin(char *s1, char *s2, size_t len)
{
	char			*str;
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	if (!(str = malloc(sizeof(char) * (ft_strlen2(s1) + len + 1))))
		return (NULL);
	tmp = str;
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] && len > 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str - (str - tmp));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen2(s))
		len = 0;
	if (!(string = (char *)malloc(len + 1)))
		return (NULL);
	string[len] = '\0';
	while (i < len)
	{
		string[i] = s[start];
		i++;
		start++;
	}
	return (string);
}

