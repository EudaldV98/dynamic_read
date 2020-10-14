/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:10:16 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/14 15:16:43 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_memset2(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	while (len > 0)
	{
		*(ptr++) = (unsigned char)c;
		len--;
	}
	return (b);
}

void			*ft_calloc2(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(ptr = (unsigned char *)malloc(sizeof(size) * count)))
		return (NULL);
	ft_memset2(ptr, 0, count);
	return ((void *)ptr);
}

static char		*new_str(char *string)
{
	if (ft_strchr(string, '\n'))
	{
		ft_strcpy(string, ft_strchr(string, '\n') + 1);
		return (string);
	}
	else if (ft_strlen2(string) > 0)
	{
		ft_strcpy(string, ft_strchr(string, '\0'));
		return (string);
	}
	return (NULL);
}

void			ft_strdel(char **as)
{
	if (as != NULL)
	{
		*as = NULL;
		free(*as);
	}
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*st[MAX];
	int				r;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(st[fd]) && !(st[fd] = ft_calloc2(1, sizeof(int))))
		return (-1);
	while (!(ft_strchr(st[fd], '\n')) && (r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = st[fd];
		st[fd] = ft_strjoin(tmp, buff, r);
		free(tmp);
	}
	tmp = ft_substr(st[fd], 0, ft_strlen2(st[fd]));
	*line = tmp;
	ft_strdel(&tmp);
	if (ft_strchr(st[fd], '\n') == NULL)
	{
		free(st[fd]);
		return (0);
	}
	return ((new_str(st[fd]) == NULL) ? 0 : 1);
}
