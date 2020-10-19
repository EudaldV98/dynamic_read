/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:29:51 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/19 18:58:54 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ctrl(t_reader *r)
{
	r->ent = 1;
	write(1, "\n", 1);
	if (r->c == 3)
		r->s = ft_strdup("\n");
	else if (r->c == 12)
		r->s = ft_strdup("clear\n");
	return (0);
}

int			ctrl_kdel(t_keys *keys, t_reader *r)
{
	if (r->i < r->len)
	{
		r->i++;
		write(1, keys->k_right, 3);
		ft_kdel(keys, r);
	}
	return (1);
}

void        ft_strdel_av(char ***av)
{
	if (*av)
	{
		free(*av);
		*av = NULL;
	}
}

void		ft_free_av(char **av)
{
	int		i;
	i = -1;
	if (av)
	{
		while (av[++i])
			ft_strdel(&av[i]);
		ft_strdel_av(&av);
	}
}

void            ft_strdel(char **s)
{
        if (s != NULL)
        {
                free(*s);
                *s = NULL;
        }
}
