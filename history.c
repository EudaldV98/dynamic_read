/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:29:07 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/19 12:43:39 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			create_history(t_historique *h)
{
	int		fd;
	char	*buff;
	int		ret;
	int		line;

	if (!(fd = open(H_NAME, O_CREAT | O_RDWR, (S_IRUSR | S_IWUSR))))
		return (0);
	h->line = 0;
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		if (buff[0] != '\n' && buff[0] != '\0')
			h->line++;
		free(buff);
	}
	close(fd);
	line = (h->line > 0) ? h->line : 1;
	if (!(h->tab = malloc(sizeof(char *) * (line + 1))))
		return (0);
	h->tab[line] = NULL;
	h->size = line;
	h->i = -1;
	free(buff);
	buff = NULL;
	return (1);
}

int			fill_history_b(t_historique *h)
{
	int		fd;
	char	*buff;
	int		ret;
	int		i;

	if (!(fd = open(H_NAME, O_RDONLY)))
		return (0);
	i = 0;
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		if (buff[0] != '\n' && buff[0] != '\0')
		{
			h->tab[i] = ft_strdup(buff);
			i++;
		}
		free(buff);
	}
	if (buff[0] != '\n' && buff[0] != '\0')
		h->tab[i] = ft_strdup(buff);
	free(buff);
	buff = NULL;
	return (1);
}

int			fill_history_a(t_historique *h, t_reader *r)
{
	int		i;
	int		fd;

	if (!(fd = open(H_NAME, O_WRONLY)))
		return (0);
	i = 0;
	while (h->tab[i])
	{
		write(fd, h->tab[i], ft_strlen(h->tab[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	if (!(fd = open(H_NAME, O_CREAT, 0000)))
		return (0);
	close(fd);
	free(r->s);
	r->s = NULL;
	return (1);
}
