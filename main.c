/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:25:04 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/18 00:07:15 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			set_keys(t_keys	*keys)
{
	keys->k_left[0] = 27;
	keys->k_left[1] = '[';
	keys->k_left[2] = 'D';
	keys->k_left[3] = 0;
	keys->k_right[0] = 27;
	keys->k_right[1] = '[';
	keys->k_right[2] = 'C';
	keys->k_right[3] = 0;
	keys->k_up[0] = 27;
	keys->k_up[1] = '[';
	keys->k_up[2] = 'A';
	keys->k_up[3] = 0;
	keys->k_down[0] = 27;
	keys->k_down[1] = '[';
	keys->k_down[2] = 'B';
	keys->k_down[3] = 0;
}

void			ft_print_char(t_reader *r, t_keys *keys)
{
	int i;

	i = 0;
	write(1, &r->c, 1);
	write(1, &r->s[r->i], ft_strlen(&r->s[r->i]));
	while ((size_t)(i) < ft_strlen(&r->s[r->i]))
	{
		write(1, keys->k_left, 3);
		++i;
	}
}

void			fill_str(t_reader *r, t_keys *keys)
{
	if (r->i == r->len)
		ft_strncat(r->s, r->c, 1);
	else
	{
		ft_memmove(&r->s[r->i + 1], &r->s[r->i], r->len - r->i + 1);
		r->s[r->i] = r->c;
	}
	r->i++;
	r->len++;
	ft_print_char(r, keys);
}

int				ft_exit(t_reader *r)
{
	r->exit = 1;
	write(1, "exit", 4);
	return (0);
}

int				ft_switch_keys(t_reader *r, t_keys *keys, t_historique *h)
{
	if (r->c == 4 && ft_strlen(r->s) == 0)
		return (ft_exit(r));
	else if (r->c == 3)
		return (ft_exit(r));
	else if (r->c == 28)
		;
	if (ft_strncmp(r->k, keys->k_left, 4) == 0)
		ft_Kleft(keys, r);
	if (ft_strncmp(r->k, keys->k_right, 4) == 0)
		ft_Kright(keys, r);
	if (ft_strncmp(r->k, keys->k_up, 4) == 0)
		ft_Kup(r, h, keys);
	if (ft_strncmp(r->k, keys->k_down, 4) == 0)
		ft_Kdown(r, h, keys);
	else if ((r->c == 127) && r->i > 0)
		ft_Kdel(keys, r);
	return (0);
}

void				ft_reader(t_reader *r, t_keys *keys, t_historique *h, t_term *term)
{
	char		k[4];

	r->k = k;
	ft_memset(r->k, 0, 4);
	set_keys(keys);
	r->s = ft_calloc(2, sizeof(char));
	r->i = 0;
	r->len = 0;
	r->exit = 0;
	r->ent = 0;
	//h->i = 0;
	while (!r->exit && !r->ent)
	{
		tcsetattr(0, 0, &term->set);
		r->c = 0;
		read(0, &r->c, 1);
		if ((r->c >= ' ' && r->c <= '~') && ft_strlen(r->k) == 0)
			fill_str(r, keys);
		if (r->c == 27 || ft_strlen(r->k) > 0)
			r->k[ft_strlen(r->k)] = r->c;
		if (ft_switch_keys(r, keys, h) > 0)
			ft_Kenter(r, h);
		if (ft_strlen(r->k) >=3)
			ft_memset(r->k, 0, 4);
		if (r->c == '\n')
		{
			//ft_strncat(r->s, r->c, 1);
			//r->len++;
			write(1, "\n", 1);
		 	ft_Kenter(r, h);
		}
		tcsetattr(0, 0, &term->backup);
	}
}

int				main(int	ac, char **av)
{
	t_term			term;
	t_keys			keys;
	t_reader		r;
	t_historique	h;
	int				fd, fd2, i;
/*
** 	set read
*/
	if (tcgetattr(0, &term.backup) == -1)
		return (0);
	if (tcgetattr(0, &term.set) == -1)
		return (0);
	term.set.c_lflag &= ~(ICANON | ECHO | ISIG);
/*
** 	First read for the size and malloc
*/
	if (!(fd = open(av[1], O_CREAT | O_RDWR, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))))
		return (0);
	fd2 = dup(fd);
	char	*buff;
	int 	ret;
	int 	line = 0;
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		if (buff[0] != '\n' && buff[0] != '\0')
			line++;
		free(buff);
	}
	close(fd);
	line = (line > 0) ? line : 1;
	if (!(h.tab = malloc(sizeof(char *) * (line + 1))))
		return (0);
	h.tab[line] = NULL;
	h.size = line;
	h.i = 0;
/*
** 	Second read to fill tab
*/
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	i = 0;
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		if (buff[0] != '\n' && buff[0] != '\0')
		{
			h.tab[i] = ft_strdup(buff);
			i++;
		}
		free(buff);
	}
	if (buff[0] != '\n' && buff[0] != '\0')
		h.tab[i] = ft_strdup(buff);
	free(buff);
	buff = NULL;
/*
** 	Main function
*/
	r.exit = 0;
	h.new_s = 0;
	while (!r.exit)
	{	
		ft_reader(&r, &keys, &h, &term);
	}
/*
**	Last open to fill txt file
*/
	if (!(fd = open(av[1],O_RDWR | O_APPEND)))
		return (0);
	i = 0;
	while (h.tab[i] && (i < h.new_s))
	{
		write(fd, h.tab[i], ft_strlen(h.tab[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	free(r.s);
	r.s = NULL;
	return (0);
}
