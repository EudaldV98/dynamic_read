/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:11:33 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/12 18:51:02 by jvaquer          ###   ########.fr       */
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

int		ft_Kdel_r(t_keys keys, t_reader *r)
{
	int i;

	ft_strlcpy(&r->s[r->i + 1], &r->s[r->i], ft_strlen(&r->s[r->i]) - 1);
	r->i--;
	// write(1, &keys.k_left, 3);
	// write(1, &r->s[r->i], ft_strlen(&r->s[r->i]));
	// write(1, " ", 1);
	// i = 0;
	// while ((size_t)(i) <= ft_strlen(&r->s[r->i]))
	// {
	// 	write(1, &keys.k_left, 3);
	// 	i++;
	// }
	r->len--;
	return (1);
}
