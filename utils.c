/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:00:40 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/11 19:46:08 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    *ft_memset(void *b, int c, size_t len)
{
        unsigned int    i;
        char                    *tab;

        i = 0;
        tab = (char*)b;
        while (i < len)
        {
                *tab = c;
                tab++;
                i++;
        }
        return (b);
}

void    *ft_calloc(size_t count, size_t size)
{
        char    *ptr;

        if (count == 0 || size == 0)
        {
                count = 1;
                size = 1;
        }
        if (!(ptr = malloc(count * size)))
                return (NULL);
        ptr = ft_memset(ptr, '\0', count * size);
        return (ptr);
}

char    *ft_strdup(const char *s1)
{
        char    *copy;
        int             len;
        int             i;

        if (!s1)
                return (NULL);
        len = 0;
        while (s1[len])
                len++;
        copy = malloc((len + 1) * sizeof(char));
        if (copy != NULL)
        {
                i = 0;
                while (s1[i])
                {
                        copy[i] = s1[i];
                        i++;
                }
                copy[i] = '\0';
                return (copy);
        }
        return (NULL);
}

size_t          ft_strlen(const char *s)
{
        size_t len;

        if (!s)
                return (0);
        len = 0;
        while (s[len])
                len++;
        return (len);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
        size_t  i;
        size_t  len;

        if (!dst || !src)
                return (0);
        len = 0;
        i = 0;
        while (src[len])
                len++;
        if (dstsize > 0)
        {
                while (i < (dstsize - 1) && src[i])
                {
                        dst[i] = src[i];
                        i++;
                }
                dst[i] = '\0';
        }
        return (len);
}

char	*ft_strncat(char *dest,const char c, int nb)
{
	int	i;
	int	dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (i < nb)
	{
		dest[dest_size] = c;
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}

int             ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t                  i;
        int                             res;

        i = 0;
        while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
        {
                res = (unsigned char)s1[i] - (unsigned char)s2[i];
                if (res != 0)
                        return (res);
                i++;
        }
        return (0);
}
