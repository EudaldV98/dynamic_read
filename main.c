/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:25:04 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/13 18:54:55 by jvaquer          ###   ########.fr       */
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

void			ft_print_char(t_reader *r, t_keys keys)
{
	int i;

	i = 0;
	write(1, &r->c, 1);
	write(1, &r->s[r->i], ft_strlen(&r->s[r->i]));
	while ((size_t)(i) < ft_strlen(&r->s[r->i]))
	{
		write(1, keys.k_left, 3);
		++i;
	}
}

void			fill_str(t_reader *r, t_keys keys)
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
	r->close = 1;
	write(1, "exit", 4);
	return (1);
}

int				ft_switch_keys(t_reader *r, t_keys keys)
{
	if (r->c == 4 && ft_strlen(r->s) == 0)
		return (ft_exit(r));
	else if (r->c == 3)
		return (ft_exit(r));
	else if (r->c == 28)
		;
	else if (ft_strncmp(r->k, keys.k_left, 4) == 0)
		ft_Kleft(keys, r);
	else if (ft_strncmp(r->k, keys.k_right, 4) == 0)
		ft_Kright(keys, r);
	else if (ft_strncmp(r->k, keys.k_up, 4) == 0)
		ft_Kup(r);
	else if (ft_strncmp(r->k, keys.k_down, 4) == 0)
		ft_Kdown(r);
	else if ((r->c == 127) && r->i > 0)
		ft_Kdel(keys, r);
	return (0);
}

void				ft_reader(t_reader *r, t_keys keys, t_historique *h, t_term *term)
{
	while (r->close == 0)
	{
		tcsetattr(0, 0, &term->set);
		r->c = 0;
		read(0, &r->c, 1);
		if ((r->c >= ' ' && r->c <= '~') && ft_strlen(r->k) == 0)
			fill_str(r, keys);
		if (r->c == 27 || ft_strlen(r->k) > 0)
			r->k[ft_strlen(r->k)] = r->c;
		else if (ft_switch_keys(r, keys))
			ft_Kenter(r, h);
		if (ft_strlen(r->k) >=3)
			ft_memset(r->k, 0, 4);
		if (r->c == '\n')
		 	ft_Kenter(r, h);
		tcsetattr(0, 0, &term->backup);
	}
}

int				main()
{
	t_term			term;
	t_keys			keys;
	t_reader		r;
	t_historique	h;
	int			enter;
	char		k[4];

/*
** 	set read
*/
	if (tcgetattr(0, &term.backup) == -1)
		return (0);
	if (tcgetattr(0, &term.set) == -1)
		return (0);
	term.set.c_lflag &= ~(ICANON | ECHO | ISIG);
/*
** 	set vars
*/
	enter = 0;
	r.k = k;
	ft_memset(r.k, 0, 4);
	set_keys(&keys);
	r.s = ft_calloc(2, sizeof(char));
	r.i = 0;
	r.len = 0;
	int i = 0;
	while (i < S_MAX)
	{
		h.tab[i] = NULL;
		i++;
	}
	r.close = 0;
	
	while (!r.close)
	{	
		ft_reader(&r, keys, &h, &term);

	}

	//if (r.c == '\n')
	//{
	//	ft_strncat(r.s, r.c, 1);
	//	r.len++;
	printf("STR: %s\nLEN: %zu\n", h.tab[0], ft_strlen(h.tab[0]));
	//}
	free(r.s);
	r.s = NULL;
	return (0);
}
