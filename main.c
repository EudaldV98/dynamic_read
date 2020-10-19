/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:25:04 by jvaquer           #+#    #+#             */
/*   Updated: 2020/10/19 19:09:05 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			set_keys(t_keys *keys)
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

int				main(int ac, char **av)
{
	t_term			term;
	t_keys			keys;
	t_reader		r;
	t_historique	h;

	if (tcgetattr(0, &term.backup) == -1)
		return (0);
	if (tcgetattr(0, &term.set) == -1)
		return (0);
	term.set.c_lflag &= ~(ICANON | ECHO | ISIG);
	set_keys(&keys);
	if (!(create_history(&h)))
		return (0);
	if (!(fill_history_b(&h)))
		return (0);
	r.exit = 0;
	while (!r.exit)
	{
		ft_reader(&r, &keys, &h, &term);
		//write(1, "STR: ", 5);
		//write(1, r.s, ft_strlen(r.s));
	}
	if (!(fill_history_a(&h, &r)))
		return (0);
	free_histo(&r, &h);
	return (0);
}
