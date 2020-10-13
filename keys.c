/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:11:33 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/13 18:54:37 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_Kleft(t_keys keys, t_reader *r)
{
	if (r->i > 0)
	{
		write(1, &keys.k_left,3);
		r->i--;
	}
	ft_memset(r->k, 0, 4);
	return (1);	
}

int		ft_Kright(t_keys keys, t_reader *r)
{
	if (r->i < r->len)
	{
		write(1, &keys.k_right,3);
		r->i++;
	}
	ft_memset(r->k, 0, 4);
	return (1);	
}

int		ft_Kdel(t_keys keys, t_reader *r)
{
	int i;

	ft_strlcpy(&r->s[r->i - 1], &r->s[r->i], ft_strlen(&r->s[r->i]) + 1);
	r->i--;
	write(1, &keys.k_left, 3);
	write(1, &r->s[r->i], ft_strlen(&r->s[r->i]));
	write(1, " ", 1);
	i = 0;
	while ((size_t)(i) <= ft_strlen(&r->s[r->i]))
	{
		write(1, &keys.k_left, 3);
		i++;
	}
	r->len--;
	return (1);
}

int		ft_Kenter(t_reader *r, t_historique *h)
{
	int		i;

	i = S_MAX - 2;
	printf("\nR.S: %s\n", r->s);
	h->tab[0] = r->s;
	printf("H.s: %s\n", h->tab[0]);
	while (i >= 0)
	{
		h->tab[i + 1] = h->tab[i];
		--i;
	}
	if (h->tab[S_MAX - 1] != NULL)
	{
		free(h->tab[S_MAX - 1]);
		h->tab[S_MAX - 1] = NULL;
	}
	// free(r->s);
	// r->s = NULL;
	// r->s = ft_calloc(2, sizeof(char));
	return (1);
}

void	ft_Kup(t_reader *r)
{
	write(1, "Kup", 3);
}

void	ft_Kdown(t_reader *r)
{
	write(1, "Kdown", 5);
}
