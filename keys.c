/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:11:33 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/19 16:10:27 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_kleft(t_keys *keys, t_reader *r)
{
	if (r->i > 0)
	{
		write(1, keys->k_left, 3);
		r->i--;
	}
	ft_memset(r->k, 0, 4);
	return (1);
}

int		ft_kright(t_keys *keys, t_reader *r)
{
	if (r->i < r->len)
	{
		write(1, keys->k_right, 3);
		r->i++;
	}
	ft_memset(r->k, 0, 4);
	return (1);
}

int		ft_kenter(t_reader *r, t_historique *h)
{
	if (ft_strlen(r->s) > 0)
	{
		ft_add_input(r, h);
		r->ent = 1;
		h->size++;
		h->i = -1;
	}
	return (1);
}

int		ft_kup(t_reader *r, t_historique *h, t_keys *keys)
{
	int i;

	if (h->line == 0 && h->size == 1)
		return (0);
	if (h->i < h->size - 2)
	{
		if (h->i == -1)
			h->tmp = ft_strdup(r->s);
		h->i++;
		i = 0;
		while (++i <= ft_strlen(r->s) - ft_strlen(&r->s[r->i]))
			write(1, keys->k_left, 3);
		i = 0;
		while (++i <= ft_strlen(r->s))
			write(1, " ", 1);
		i = 0;
		while (++i <= ft_strlen(r->s))
			write(1, keys->k_left, 3);
		free(r->s);
		r->s = ft_strdup(h->tab[h->i]);
		write(1, r->s, ft_strlen(r->s));
		r->i = ft_strlen(r->s);
		r->len = ft_strlen(r->s);
	}
	return (0);
}

int		ft_kdown(t_reader *r, t_historique *h, t_keys *keys)
{
	int i;

	if (h->i == 0)
		ft_kdown_zero(r, h, keys);
	if (h->i > 0)
	{
		h->i--;
		i = 0;
		while (++i <= ft_strlen(r->s) - ft_strlen(&r->s[r->i]))
			write(1, keys->k_left, 3);
		i = 0;
		while (++i <= ft_strlen(r->s))
			write(1, " ", 1);
		i = 0;
		while (++i <= ft_strlen(r->s))
			write(1, keys->k_left, 3);
		free(r->s);
		r->s = ft_strdup(h->tab[h->i]);
		write(1, r->s, ft_strlen(r->s));
		r->i = ft_strlen(r->s);
		r->len = ft_strlen(r->s);
	}
	return (0);
}
